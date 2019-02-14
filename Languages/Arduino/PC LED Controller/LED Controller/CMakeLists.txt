project("LEDController")
cmake_minimum_required(VERSION 3.0)

set(SRC_DIR LEDController/src)
set(SRC_FILES 
    ${SRC_DIR}/LEDControllers/Oscillator.cpp
    ${SRC_DIR}/LEDControllers/SteadyState.cpp
    ${SRC_DIR}/LEDControllers/Selectable.cpp)

add_library(LEDController ${SRC_FILES})
target_include_directories(LEDController PUBLIC ${SRC_DIR})