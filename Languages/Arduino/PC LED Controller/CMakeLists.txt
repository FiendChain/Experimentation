cmake_minimum_required(VERSION 3.0)
project("PC Controller Serial Monitor")

set(APP_DIR .)
set(SRC_FILES
    ${APP_DIR}/main.cpp)

add_subdirectory(${APP_DIR}/SerialMonitor)

add_executable(main ${SRC_FILES})
target_link_libraries(main SerialMonitor)
target_link_libraries(main imgui)
target_link_libraries(main boost_system boost_filesystem)
target_compile_options(main PUBLIC -O3 -std=c++17)
