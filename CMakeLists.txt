cmake_minimum_required(VERSION 3.10)
project(cms-kernel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# In CMakeLists.txt
add_custom_target(
    format
    COMMAND clang-format -i ${ALL_SOURCE_FILES}
)

add_custom_target(
    lint
    COMMAND clang-tidy ${ALL_SOURCE_FILES} -- -I${CMAKE_SOURCE_DIR}/include
)

add_executable(cms-kernel src/main.cpp)

