# ============================================================================
# Пример 03: Использование внешних библиотек
# ============================================================================
# Демонстрирует:
# - Поиск и подключение внешних библиотек (на примере Boost)
# - Использование find_package для автоматического поиска
# - Указание стандарта C++

cmake_minimum_required(VERSION 3.10)

project(ListDirectory)

# Устанавливаем стандарт C++ для всего проекта
set(CMAKE_CXX_STANDARD 11)

# Опции для конфигурации Boost (закомментированы)
# Раскомментируйте при необходимости использования статических библиотек
#set(Boost_USE_STATIC_LIBS ON)
#set(Boost_USE_MULTITHREADED ON)

# Ищем библиотеку Boost с компонентами filesystem и system
# REQUIRED означает, что сборка прервется, если Boost не найден
# find_package создает переменные: Boost_INCLUDE_DIRS, Boost_LIBRARIES и др.
find_package(Boost COMPONENTS filesystem system REQUIRED)

# Создаем исполняемый файл
add_executable(ListDirectory main.cpp)

# Добавляем наши заголовочные файлы
target_include_directories(ListDirectory PRIVATE include)

# Для современных версий CMake не нужно явно указывать Boost_INCLUDE_DIRS
# Они будут добавлены автоматически через target_link_libraries с Boost::filesystem
# target_include_directories(ListDirectory PRIVATE ${Boost_INCLUDE_DIRS})

# Добавляем поддиректорию с нашей библиотекой ListDir
add_subdirectory(src)

# Для современных версий CMake не нужно явно указывать Boost_LIBRARY_DIRS
# target_link_directories(ListDirectory PRIVATE ${Boost_LIBRARY_DIRS})

# Линкуем с нашей библиотекой ListDir
# Библиотека ListDir уже содержит линковку с Boost::filesystem
target_link_libraries(ListDirectory PRIVATE ListDir)

# Установка проекта
install(
    TARGETS ListDirectory
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
)
