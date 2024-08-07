enable_testing()

file(GLOB NEEDED_SOURCE
	"BMC-ENGINE/classes/math/Vector.cpp"
)

add_executable(
  tests
  "tests/vectors.cpp"
  ${NEEDED_SOURCE}
)
target_link_libraries(
  tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)