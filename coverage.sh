#!/bin/bash

set -e  # Выход при ошибке

echo "Configuring project with coverage..."
mkdir -p build
cd build

# Configure with coverage
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_COVERAGE=ON ..

echo "Building project..."
make

echo "Running tests..."
./tests/runTests

echo "Generating coverage report..."
lcov --directory . --capture --output-file coverage.info
lcov --remove coverage.info '*/usr/*' '*/tests/*' '*/extern/*' '*/_deps/*' --output-file coverage.info
genhtml coverage.info --output-directory coverage_report

echo "Coverage report generated in build/coverage_report/"
echo "Open build/coverage_report/index.html to view the report"