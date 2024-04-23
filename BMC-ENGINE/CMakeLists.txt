# CMakeList.txt : CMake project for BMC-ENGINE, include source and define
# project specific logic here.

# Add source to this project's executable.
file(GLOB BMCE_SOURCE
	"*.cpp"
	"*.h"
	"../libs/glad/src/glad.c"
	"../libs/imgui/*.cpp"
	"../libs/imgui/backends/imgui_impl_glfw.cpp"
	"../libs/imgui/backends/imgui_impl_opengl3.cpp"
	"../extern/glfw/src/*.cpp"
)

add_executable(BMC-ENGINE ${BMCE_SOURCE})

find_package(OpenGL REQUIRED)

target_link_libraries(BMC-ENGINE glfw)
target_link_libraries(BMC-ENGINE OpenGL::GL)

# target_link_libraries(BMC-ENGINE PRIVATE GLFW)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BMC-ENGINE PROPERTY CXX_STANDARD 20)
endif()