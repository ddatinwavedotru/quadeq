# Поиск GoogleTest
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/../googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/../googletest-build)

# Создание тестового исполняемого файла
add_executable(runTests tests.cpp)

# Линковка с GoogleTest и нашей библиотекой
target_link_libraries(runTests 
    GTest::gtest_main 
    solve
)

# Добавление теста в CTest
include(GoogleTest)
gtest_discover_tests(runTests)
