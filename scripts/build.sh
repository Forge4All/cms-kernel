#!/bin/bash

# Build the project from the root directory
mkdir -p build
cd build
cmake ..
cmake --build .
