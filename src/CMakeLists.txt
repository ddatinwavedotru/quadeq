# Создание библиотеки
add_library(solve solve.cpp)

# Интерфейс библиотеки (заголовки)
target_include_directories(solve PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

