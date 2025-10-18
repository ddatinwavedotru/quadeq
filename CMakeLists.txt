cmake_minimum_required(VERSION 3.16)

project(quadeq LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_COVERAGE "Enable code coverage reporting" OFF)

if(ENABLE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        message(STATUS "Enabling code coverage")
        add_compile_options(-fprofile-arcs -ftest-coverage)
        add_link_options(-fprofile-arcs -ftest-coverage)

        # Находим lcov и genhtml
        find_program(LCOV_PATH lcov)
        find_program(GENHTML_PATH genhtml)

        if(LCOV_PATH AND GENHTML_PATH)
            set(COVERAGE_AVAILABLE ON)
        else()
            message(WARNING "lcov or genhtml not found - coverage reports disabled")
        endif()
    else()
        message(WARNING "Code coverage is only supported for GCC and Clang")
    endif()
endif()

# Включение CTest
include(CTest)

# Скачивание GoogleTest
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download
)
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download
)


# Добавление поддиректориев
add_subdirectory(src)
add_subdirectory(tests)

# Добавляем цель для генерации coverage отчета
if(ENABLE_COVERAGE AND COVERAGE_AVAILABLE)
    add_custom_target(coverage
        COMMAND ${LCOV_PATH} --directory . --zerocounters
        COMMAND $<TARGET_FILE:runTests>
        COMMAND ${LCOV_PATH} --directory . --capture --output-file coverage.info
        COMMAND ${LCOV_PATH} --remove coverage.info '/usr/*' '*/tests/*' '*/extern/*' --output-file coverage.info
        COMMAND ${GENHTML_PATH} coverage.info --output-directory coverage_report
        COMMAND ${LCOV_PATH} --list coverage.info
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Generating code coverage report"
    )
endif()

