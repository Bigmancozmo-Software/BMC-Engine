# CMakeList.txt : CMake project for BMC-ENGINE, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (BMC-ENGINE "main.cpp" "main.h" "../libs/glad/src/glad.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BMC-ENGINE PROPERTY CXX_STANDARD 20)
endif()

# Libraries
if(WIN32)
  target_link_libraries(BMC-ENGINE ${CMAKE_CURRENT_SOURCE_DIR}/../libs/GLFW/lib/glfw3.lib)
  target_link_libraries(BMC-ENGINE ${CMAKE_CURRENT_SOURCE_DIR}/../libs/GLFW/lib/glfw3dll.lib)
  target_link_libraries(BMC-ENGINE ${CMAKE_CURRENT_SOURCE_DIR}/../libs/GLFW/lib/glfw3_mt.lib)
endif()