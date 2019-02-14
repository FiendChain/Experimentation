cmake_minimum_required(VERSION 3.0)

project("PC Controller Client")

set(APP_DIR .)
set(SRC_FILES
    ${APP_DIR}/App.cpp
    ${APP_DIR}/Logger.cpp
    ${APP_DIR}/SerialMonitor.cpp)

add_subdirectory(${APP_DIR}/SerialPort)

add_library(SerialMonitor ${SRC_FILES})
target_link_libraries(SerialMonitor SerialPort)
target_link_libraries(SerialMonitor sfml-system sfml-graphics sfml-window)
target_link_libraries(SerialMonitor imgui imgui-sfml)
target_link_libraries(SerialMonitor ws2_32 boost_system boost_thread)
target_include_directories(SerialMonitor PUBLIC ${CLIENT_DIR})
target_compile_options(SerialMonitor PUBLIC -O3 -std=c++17)

