#include "SerialMonitor.hpp"
#include <windows.h>
#include <imgui/imgui.h>
#include <imgui-sfml/imgui-SFML.h>
#include <vector>

SerialMonitor::SerialMonitor(const std::string& portName, unsigned baudRate, bool reset) 
    : mPortName{0},
      mInputBuffer{0},
      mCommandBuffer{0},
      mPort(nullptr),
      mBaudRate(baudRate),
      mReset(reset),
      mThreadPool(2),
      mRunning(true)
{
    for (int i = 0; i < mPortName.size() && i < portName.size(); i++) {
        mPortName[i] = portName[i];
    }
    Connect();
    mUpdateThread = boost::thread([this]() {
        while (mRunning) {
            ReadPackets();
            Sleep(10);
        }
    });
}

SerialMonitor::~SerialMonitor()
{
    mRunning = false;
    mThreadPool.join();
    mUpdateThread.join();
}

void SerialMonitor::OnImGui()
{
    ImGui::Begin("Serial Monitor", NULL, ImGuiWindowFlags_MenuBar);
    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("Edit")) {
            if (ImGui::MenuItem("Clear"))
                mLogger.Clear();
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    ImGui::InputText("Port name", mPortName.data(), mPortName.size()-1);
    ImGui::InputScalar("Baud rate", ImGuiDataType_U32, (void *)&mBaudRate);
    ImGui::Checkbox("Reset", &mReset);
    if (ImGui::RadioButton("Connected", mPort && mConnected)) {
        Connect();
    }
    ImGui::Separator();
    if (ImGui::InputText("Console", mCommandBuffer.data(), mCommandBuffer.size()-1, ImGuiInputTextFlags_EnterReturnsTrue))
        WritePackets();
    mLogger.OnImGui();
    ImGui::End();
}

void SerialMonitor::WritePackets()
{
    boost::asio::post(mThreadPool, [this]() {
        boost::mutex::scoped_lock lock(mIOMutex);
        if (!mPort) 
            return;
        mPort->writeSerialPort(mCommandBuffer.data(), mCommandBuffer.size());
        std::vector<char> buffer;
        int endIndex = 0;
        while (endIndex < mCommandBuffer.size() && mCommandBuffer[endIndex] != 0)
            endIndex++;
        buffer.assign(mCommandBuffer.begin(), mCommandBuffer.begin()+endIndex);
        buffer.insert(buffer.begin(), '>');
        buffer.push_back('\n');
        buffer.push_back('\0');
        mLogger.WriteLine(buffer);
    });
}

void SerialMonitor::Connect()
{
    boost::asio::post(mThreadPool, [this]() {
        boost::mutex::scoped_lock lock(mIOMutex);
        mPort = nullptr;
        mConnected = false;
        std::stringstream ss;
        ss << "\\\\.\\" << mPortName.data();
        mPort = std::make_unique<SerialPort>(ss.str().c_str(), mBaudRate, mReset);
        mConnected = mPort->isConnected();
    });
}

void SerialMonitor::ReadPackets()
{
    boost::mutex::scoped_lock lock(mIOMutex);
    if (!mPort)
        return;
    int totalBytes = mPort->readSerialPort(mInputBuffer.data(), mInputBuffer.size());
    if (totalBytes > 0) {
        std::vector<char> line;
        line.assign(mInputBuffer.begin(), mInputBuffer.begin()+totalBytes);
        mLogger.WriteLine(line);
    }
}

