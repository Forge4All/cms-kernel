#!/bin/bash

# Run all tests from the root directory
cd build
ctest --output-on-failure
