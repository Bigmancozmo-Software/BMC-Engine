enable_testing()

add_executable(
  unit_tests
  "GTestExperimentation/add_test.cpp"
)
target_link_libraries(
  unit_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)