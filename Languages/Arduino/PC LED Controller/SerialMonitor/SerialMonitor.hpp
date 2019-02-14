#pragma once
#include "SerialPort.h"
#include "Logger.hpp"
#include <array>
#include <vector>
#include <string>
#include <functional>
#include <memory>
#include <boost/asio.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include "IRunnable.hpp"


class SerialMonitor: public IRunnable
{
    private:
        std::array<char, 100> mPortName;
        std::array<char, 512> mInputBuffer;
        std::array<char, 100> mCommandBuffer;
        unsigned mBaudRate;
        bool mReset;
        bool mConnected;
        bool mRunning;
        std::unique_ptr<SerialPort> mPort;
        Logger mLogger;
        boost::asio::thread_pool mThreadPool;
        boost::mutex mIOMutex;
        boost::thread mUpdateThread;
    public:
        SerialMonitor(const std::string& portName="", unsigned baudRate=9600, bool reset=false);
        ~SerialMonitor();
        void Render() {}
        void OnImGui();
        void Update(float deltatime) {}
        void PollEvent(const sf::Event& event) {}
    private:
        void Connect();
        void ReadPackets();
        void WritePackets();
};

