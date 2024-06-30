cmake_minimum_required (VERSION 3.8)

project(TestRunner)

file(GLOB _SOURCES
	"translator_keys.cpp"
)

add_executable(TestRunner ${_SOURCES})


# Testing
add_subdirectory (extern/GTest)
enable_testing()
target_link_libraries(TestRunner PUBLIC gtest_main BMC-ENGINE)
