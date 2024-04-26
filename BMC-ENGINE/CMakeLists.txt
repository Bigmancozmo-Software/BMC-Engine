# CMakeList.txt : CMake project for BMC-ENGINE, include source and define
# project specific logic here.

# Add source to this project's executable.
file(GLOB RENDERING_SOURCE
	"rendering/*.cpp"
	"rendering/debugger/*.cpp"
	"rendering/shaders/*.cpp"
)

file(GLOB FILES_SOURCE
	"files/*.cpp"
	"files/image/*.cpp"
)

file(GLOB ROOT_SOURCE
	"*.cpp"
	"*.h"
	"../libs/glad/src/glad.c"
	"../libs/imgui/*.cpp"
	"../libs/imgui/backends/imgui_impl_glfw.cpp"
	"../libs/imgui/backends/imgui_impl_opengl3.cpp"
	"../extern/glfw/src/*.cpp"
)

# resources dir
add_custom_target(copy_resources ALL)

add_custom_command(
    TARGET copy_resources PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        ${CMAKE_BINARY_DIR}/BMC-ENGINE/resources
    COMMENT "Copying resources directory to build tree"
)

add_executable(BMC-ENGINE ${ROOT_SOURCE} ${RENDERING_SOURCE} ${FILES_SOURCE})

find_package(OpenGL REQUIRED)

target_link_libraries(BMC-ENGINE glfw)
target_link_libraries(BMC-ENGINE OpenGL::GL)

# target_link_libraries(BMC-ENGINE PRIVATE GLFW)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BMC-ENGINE PROPERTY CXX_STANDARD 20)
endif()