project("Serial Port")
cmake_minimum_required(VERSION 3.0)

set(SRC_DIR .)
set(SRC_FILES 
    ${SRC_DIR}/SerialPort.cpp)

add_library(SerialPort ${SRC_FILES})
target_include_directories(SerialPort PUBLIC ${SRC_DIR})