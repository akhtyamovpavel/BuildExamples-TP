# ============================================================================
# Пример 07: Создание собственных Find-модулей
# ============================================================================
# Демонстрирует:
# - Создание и использование пользовательских Find-модулей
# - Настройку CMAKE_MODULE_PATH для поиска модулей
# - Использование find_package с пользовательским модулем

cmake_minimum_required(VERSION 3.13)

# Опция для новой политики поиска пакетов (при необходимости)
# cmake_policy(SET CMP0074 NEW)

project(IncludeLibrary)

# Добавляем директорию с нашими Find-модулями в путь поиска
# CMAKE_MODULE_PATH - список путей, где CMake ищет модули Find<Package>.cmake
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" ${CMAKE_SOURCE_DIR}/cmake)

# Используем наш пользовательский Find-модуль для поиска библиотеки FC
# CMake будет искать файл FindFC.cmake в директориях из CMAKE_MODULE_PATH
# REQUIRED - сборка прервется, если пакет не найден
find_package(FC REQUIRED)

# Выводим информацию о найденной библиотеке
message(INFO ${FC_LIBRARY_DIR})

# Создаем исполняемый файл
add_executable(main main.cpp)

# Добавляем пути к заголовочным файлам найденной библиотеки
target_include_directories(main PRIVATE ${FC_INCLUDE_DIR})

# Добавляем пути к файлам библиотек
target_link_directories(main PRIVATE ${FC_LIBRARY_DIR})

# Линкуем с найденными библиотеками
target_link_libraries(main ${FC_LIBRARIES})

