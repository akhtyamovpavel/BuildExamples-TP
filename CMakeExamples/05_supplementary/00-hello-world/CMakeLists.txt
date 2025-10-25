# ============================================================================
# Supplementary 00: Hello World (альтернативный вариант)
# ============================================================================
# Демонстрирует альтернативные способы настройки путей вывода

cmake_minimum_required(VERSION 2.8)

project(Hello)

# Устанавливаем директорию для всех бинарных файлов
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)

# Устанавливаем путь для исполняемых файлов
# EXECUTABLE_OUTPUT_PATH - устаревшая переменная (для совместимости)
# Рекомендуется использовать CMAKE_RUNTIME_OUTPUT_DIRECTORY
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Устанавливаем путь для библиотек
# LIBRARY_OUTPUT_PATH - устаревшая переменная (для совместимости)
# Рекомендуется использовать CMAKE_LIBRARY_OUTPUT_DIRECTORY
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Добавляем директорию проекта в пути поиска заголовочных файлов
# Устаревший способ - рекомендуется использовать target_include_directories
include_directories(${PROJECT_SOURCE_DIR})

# Создаем исполняемый файл
add_executable(hello ${PROJECT_SOURCE_DIR}/hello_world.cpp)
