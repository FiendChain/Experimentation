#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <boost/filesystem.hpp>
#include "SerialMonitor/App.hpp"
#include "SerialMonitor/SerialMonitor.hpp"
#include <imgui/imgui.h>

int main(int argc, char *argv[])
{
    if (argc == 2 && strncmp(argv[1], "-h", 2) == 0)
    {
        printf("Usage: %s <port> [baudRate] <reset>", argv[0]);
        return 0;
    }
    std::string portName(argc >= 2 ? argv[1] : "COM3");

    unsigned baudRate = 9600;
    if (argc >= 3 && sscanf(argv[2], "%u", &baudRate) != 1) {
        printf("%s is not a valid baudRate\n", argv[2]);
        return 0;
    }
    bool reset = argc >= 4 && argv[3][0] == 'y' ? true : false;

    ImGui::CreateContext();
    ImGuiIO& config = ImGui::GetIO();
    boost::filesystem::path userprofilePath(getenv("APPDATA"));
    boost::filesystem::path folder("ledctrl");
    boost::filesystem::path filename("settings.ini");
    boost::filesystem::path configPath = userprofilePath / folder / filename;
    std::string configPathStr = configPath.string();
    config.IniFilename = configPathStr.c_str();

    App app(1920, 1080, "LED Controller");
    SerialMonitor monitor(portName, baudRate, reset);
    app.SetRunnable(&monitor);
    app.Run();

    return 0;
}