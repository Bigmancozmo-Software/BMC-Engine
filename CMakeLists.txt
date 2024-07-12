# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.14)
set(CMAKE_CXX_STANDARD 14) # GTest requires C++14 or above
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(BMC-ENGINE)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Add base subdirectory
add_subdirectory ("BMC-ENGINE")

# Include directories
target_include_directories(BMC-ENGINE PRIVATE extern/glfw/include)
target_include_directories(BMC-ENGINE PRIVATE libs/glad/include)
target_include_directories(BMC-ENGINE PRIVATE libs/imgui)
target_include_directories(BMC-ENGINE PRIVATE libs/imgui/backends)
target_include_directories(BMC-ENGINE PRIVATE extern/stb)
target_include_directories(BMC-ENGINE PRIVATE BMC-ENGINE/classes)
target_include_directories(BMC-ENGINE PRIVATE extern/glm)

# More subdirectories
add_subdirectory ("extern/glfw")
add_subdirectory ("libs/glad/include")
add_subdirectory ("libs/glad/src")
add_subdirectory ("libs/imgui")
add_subdirectory ("libs/imgui/backends")

# Setup GTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(${CMAKE_SOURCE_DIR}/cmake/testing.cmake)