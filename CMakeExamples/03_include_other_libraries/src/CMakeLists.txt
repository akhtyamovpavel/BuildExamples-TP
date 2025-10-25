# ============================================================================
# CMakeLists.txt для библиотеки ListDir
# ============================================================================

cmake_minimum_required(VERSION 3.10)
project(ListDir)

# Создаем динамическую библиотеку
add_library(ListDir SHARED ListDir.cpp)

# Линкуем с Boost::filesystem
# Используем современный синтаксис с IMPORTED targets (Boost::filesystem)
# Это автоматически добавляет необходимые include-директории и флаги
target_link_libraries(ListDir Boost::filesystem)

# Добавляем наши заголовочные файлы
target_include_directories(ListDir PRIVATE ${ListDirectory_SOURCE_DIR}/include)

# Для современных версий CMake с IMPORTED targets следующие строки не нужны,
# но оставлены для совместимости со старыми версиями
target_include_directories(ListDir PRIVATE ${Boost_INCLUDE_DIRS})
target_link_directories(ListDir PRIVATE ${Boost_LIBRARY_DIRS})

