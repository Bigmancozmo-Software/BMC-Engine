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

project ("BMC-ENGINE")

# Add base subdirectory
add_subdirectory ("BMC-ENGINE")

# Include directories
target_include_directories(BMC-ENGINE PRIVATE libs/GLFW/include)
target_include_directories(BMC-ENGINE PRIVATE libs/glad/include)
target_include_directories(BMC-ENGINE PRIVATE libs/imgui)
target_include_directories(BMC-ENGINE PRIVATE libs/imgui/backends)

# More subdirectories
add_subdirectory ("libs/GLFW/include")
add_subdirectory ("libs/glad/include")
add_subdirectory ("libs/glad/src")
add_subdirectory ("libs/imgui")
add_subdirectory ("libs/imgui/backends")
