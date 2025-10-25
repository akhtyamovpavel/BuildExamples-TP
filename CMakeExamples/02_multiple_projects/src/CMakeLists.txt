# ============================================================================
# CMakeLists.txt для библиотеки FirstClass
# ============================================================================

cmake_minimum_required(VERSION 3.10)
project(FirstClassLibrary)

# Исходные файлы библиотеки
set(SOURCE_LIB FirstClass.cpp)

# Создаем ДИНАМИЧЕСКУЮ библиотеку (SHARED)
# Альтернатива: STATIC для статической библиотеки
add_library(fc SHARED ${SOURCE_LIB})

# Добавляем путь к заголовочным файлам для компиляции библиотеки
# Используем переменную родительского проекта FirstClassAsLibrary_SOURCE_DIR
target_include_directories(fc PRIVATE ${FirstClassAsLibrary_SOURCE_DIR}/include)

# Рекурсивно находим все заголовочные файлы в директории include
# GLOB_RECURSE - поиск во всех поддиректориях
file(GLOB_RECURSE LIBRARY_HEADERS "${FirstClassAsLibrary_SOURCE_DIR}/include/*.h")

# Помечаем заголовочные файлы как PUBLIC_HEADER
# Это нужно для их автоматической установки
set_target_properties(fc PROPERTIES PUBLIC_HEADER ${LIBRARY_HEADERS})

# Установка библиотеки и заголовков
install(
    TARGETS fc
    LIBRARY DESTINATION lib              # Куда установить .so/.dylib файл
    PUBLIC_HEADER DESTINATION include    # Куда установить заголовочные файлы
)
