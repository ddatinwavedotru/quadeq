cmake_minimum_required(VERSION 3.16)

project(quadeq LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(quadeq main.cpp)

include(GNUInstallDirs)
install(TARGETS quadeq
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
