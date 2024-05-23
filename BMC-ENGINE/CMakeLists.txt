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

file(GLOB OTHER_SOURCE
	"window/*.cpp"
)

file(GLOB CLASSES_SOURCE
	"classes/*.cpp"
)

file(GLOB FULL_SRC
	${ROOT_SOURCE}
	${RENDERING_SOURCE}
	${FILES_SOURCE}
	${OTHER_SOURCE}
	${CLASSES_SOURCE}
)

# resources dir
add_custom_target(copy_resources ALL)

add_custom_command(
    TARGET copy_resources POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        ${CMAKE_BINARY_DIR}/BMC-ENGINE/resources
    COMMENT "Copying resources directory to build tree"
)

if(WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Release")
	add_executable(BMC-ENGINE WIN32 ${FULL_SRC})
else()
	add_executable(BMC-ENGINE ${FULL_SRC})
endif()

find_package(OpenGL REQUIRED)

target_link_libraries(BMC-ENGINE glfw)
target_link_libraries(BMC-ENGINE OpenGL::GL)

set_target_properties(BMC-ENGINE PROPERTIES
    LINK_FLAGS "/ENTRY:mainCRTStartup"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BMC-ENGINE PROPERTY CXX_STANDARD 20)
endif()