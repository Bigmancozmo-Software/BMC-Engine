# CMakeList.txt : CMake project for BMC-ENGINE, include source and define
# project specific logic here.

# Add source to this project's executable.
file(GLOB BMCE_SOURCE
	"main.cpp"
	"main.h"
	"../libs/glad/src/glad.c"
	"../libs/imgui/*.cpp"
	"../libs/imgui/backends/imgui_impl_glfw.cpp"
	"../libs/imgui/backends/imgui_impl_opengl3.cpp"
)
add_executable(BMC-ENGINE ${BMCE_SOURCE})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BMC-ENGINE PROPERTY CXX_STANDARD 20)
endif()