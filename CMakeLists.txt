# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)
project(BMC-ENGINE)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

# Subdirectories 1
add_subdirectory ("BMC-ENGINE")

# Include directories
target_include_directories(BMC-ENGINE PUBLIC extern/glfw/include)
target_include_directories(BMC-ENGINE PUBLIC libs/glad/include)
target_include_directories(BMC-ENGINE PUBLIC libs/imgui)
target_include_directories(BMC-ENGINE PUBLIC libs/imgui/backends)
target_include_directories(BMC-ENGINE PUBLIC extern/stb)
target_include_directories(BMC-ENGINE PUBLIC BMC-ENGINE/classes)
target_include_directories(BMC-ENGINE PUBLIC extern/glm)

# More subdirectories
#add_subdirectory ("extern/GTest")
add_subdirectory ("extern/glfw")
add_subdirectory ("libs/glad/include")
add_subdirectory ("libs/glad/src")
add_subdirectory ("libs/imgui")
add_subdirectory ("libs/imgui/backends")
add_subdirectory ("tests")
