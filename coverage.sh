#!/bin/bash

# Create build directory
mkdir -p build
cd build

# Configure with coverage
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_COVERAGE=ON ..

# Build
make

# Run tests
./tests/runTests

# Generate coverage report
lcov --directory . --capture --output-file coverage.info
lcov --remove coverage.info '/usr/*' '*/tests/*' '*/extern/*' --output-file coverage.info
genhtml coverage.info --output-directory coverage_report

echo "Coverage report generated in build/coverage_report/"