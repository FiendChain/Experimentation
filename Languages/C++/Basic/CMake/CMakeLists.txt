cmake_minimum_required (VERSION 2.6)
project (CMake_Tutorial)

# set directories
set (PROJECT_BINARY_DIR "bin")
set (PROJECT_SOURCE_DIR "src")

# options
option (USE_MY_VECTOR "Use tutorial provided vector implementation" ON) 

# set compiler
set (CMAKE_C_COMPILER C:/MinGW/bin/gcc)
set (CMAKE_CXX_COMPILER C:/MinGW/bin/g++)

# version number
set (CMake_Tutorial_VERSION_MAJOR 1)
set (CMake_Tutorial_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/CMakeTutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/CMakeTutorialConfig.h"
)
include_directories ("build/${PROJECT_BINARY_DIR}")

# add vector
if (USE_MY_VECTOR) 
  include_directories ("${PROJECT_SOURCE_DIR}/Vector")
  add_subdirectory ("${PROJECT_SOURCE_DIR}/Vector")
  set (EXTRA_LIBS ${EXTRA_LIBS} Vector)
endif (USE_MY_VECTOR)

# create executable
add_executable (main ${PROJECT_SOURCE_DIR}/main.cpp ${PROJECT_SOURCE_DIR}/App.cpp)
target_link_libraries (main ${EXTRA_LIBS})

install (TARGETS main DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)
