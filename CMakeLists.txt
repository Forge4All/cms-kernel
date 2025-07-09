cmake_minimum_required(VERSION 3.10)
project(cms-kernel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add custom targets for formatting and linting
add_custom_target(
    format
    COMMAND clang-format -i ${ALL_SOURCE_FILES}
)

add_custom_target(
    lint
    COMMAND clang-tidy ${ALL_SOURCE_FILES} -- -I${CMAKE_SOURCE_DIR}/include
)

# Main executable
add_executable(cms-kernel src/main.cpp)

# --- Google Test setup ---
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  kernel_tests
  tests/sanity_test.cpp
)

target_link_libraries(
  kernel_tests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(kernel_tests)
