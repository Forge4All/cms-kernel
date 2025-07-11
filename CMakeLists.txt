cmake_minimum_required(VERSION 3.10)
project(cms-kernel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# --- Source Files ---
set(KERNEL_SOURCES
    src/main.cpp
    src/core/kernel.cpp
    src/core/logger.cpp
    src/core/config.cpp
)

set(TEST_SOURCES
    tests/sanity_test.cpp
    tests/kernel_test.cpp
    tests/logger_test.cpp
    tests/config_test.cpp
)

# --- Include Directories ---
include_directories(${CMAKE_SOURCE_DIR}/include)

# --- Formatting and Linting Targets ---
add_custom_target(format
    COMMAND clang-format -i ${KERNEL_SOURCES} ${TEST_SOURCES}
)

add_custom_target(lint
    COMMAND clang-tidy ${KERNEL_SOURCES} ${TEST_SOURCES} -- -I${CMAKE_SOURCE_DIR}/include
)

# --- Main Executable ---
add_executable(cms-kernel ${KERNEL_SOURCES})

# --- Google Test Setup ---
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# --- Test Executable ---
add_executable(kernel_tests ${TEST_SOURCES} src/core/kernel.cpp src/core/logger.cpp src/core/config.cpp)
target_link_libraries(kernel_tests gtest_main)
include(GoogleTest)
gtest_discover_tests(kernel_tests)

configure_file(${CMAKE_SOURCE_DIR}/config-sample.env
               ${CMAKE_BINARY_DIR}/config-sample.env
               COPYONLY)

# --- Copy Config File for Tests ---
add_custom_command(
    TARGET kernel_tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/config-sample.env
        $<TARGET_FILE_DIR:kernel_tests>/config-sample.env
)
