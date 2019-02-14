#include "Logger.hpp" 
#include <imgui/imgui.h>
#include <imgui-sfml/imgui-SFML.h>

Logger::Logger()
    : mConsole(0),
      mCurrLine(0)
{
    mConsole.push_back(std::vector<char>(0));
}


void Logger::OnImGui()
{
    ImGui::TextColored(ImVec4(1,1,0,1), "Console");
    ImGui::BeginChild("Scrolling");
    for (const auto& line: mConsole) {
        if (line.size() > 0)
            ImGui::Text("%.*s", line.size(), line.data()); 
    }
    ImGui::EndChild();
}

void Logger::Clear()
{
    mConsole.erase(mConsole.begin(), mConsole.end());
}

void Logger::WriteLine(const std::vector<char>& line)
{
    for (char c: line)
    {
        switch (c)
        {
        case 0:
            return;
        case '\n':
            if (mConsole.at(mCurrLine).size() > 0)
            {
                mCurrLine++;
                mConsole.push_back(std::vector<char>(0));
            }
            break;
        default:
            mConsole.at(mCurrLine).push_back(c);
        }
    }
}