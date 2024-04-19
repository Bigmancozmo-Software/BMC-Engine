# CMakeList.txt : CMake project for BMC-ENGINE, include source and define
# project specific logic here.
#

cmake_minimum_required(VERSION 3.0)
project(BMC-ENGINE)

# Add source to this project's executable.
add_executable (BMC-ENGINE "main.cpp" "main.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BMC-ENGINE PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
include(ExternalProject)

ExternalProject_Add(glfw3
    GIT_REPOSITORY https://github.com/aimotive-legacy/glfw
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

target_link_libraries(BMC-ENGINE ... glfw)
