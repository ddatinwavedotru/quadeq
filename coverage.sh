#!/bin/bash

set -e  # Выход при ошибке

echo "Cleaning previous builds..."
rm -rf build
mkdir -p build
cd build

echo "Configuring project with coverage..."
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_COVERAGE=ON ..

echo "Building project..."
make -j4

echo "Running tests..."
./tests/runTests || true  # Продолжаем даже если тесты падают

echo "Generating coverage report..."

# Создаем отчет с дополнительными опциями для обработки C++ кода
lcov --directory . --capture --output-file coverage.info --rc lcov_branch_coverage=1
lcov --remove coverage.info '*/usr/*' '*/tests/*' '*/extern/*' '*/_deps/*' '*/googletest/*' --output-file coverage.info --rc lcov_branch_coverage=1

# Генерируем HTML с деманглингом C++ имен
genhtml coverage.info --output-directory coverage_report --demangle-cpp --branch-coverage

echo "==========================================="
echo "Coverage report generated in build/coverage_report/"
echo "Open build/coverage_report/index.html to view the report"
echo "==========================================="

# Показываем сводку
lcov --list coverage.info --rc lcov_branch_coverage=1