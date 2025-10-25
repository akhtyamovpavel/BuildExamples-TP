# ============================================================================
# Пример 02: Создание и использование библиотеки
# ============================================================================
# Демонстрирует:
# - Создание динамической библиотеки
# - Подключение поддиректорий с отдельными CMakeLists.txt
# - Линковку библиотеки с исполняемым файлом
# - Установку проекта (install)
# - Настройку RPATH для корректной работы после установки

cmake_minimum_required(VERSION 3.10)

project(FirstClassAsLibrary)

# Настройка RPATH - пути поиска динамических библиотек во время выполнения
# Это необходимо, чтобы исполняемый файл нашел библиотеку после установки
if (NOT APPLE)
    # Linux: $ORIGIN - директория исполняемого файла
    set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
else()
    # macOS: @loader_path - аналог $ORIGIN
    set(CMAKE_INSTALL_RPATH "@loader_path/../lib")
endif()

# Определяем исходники главной программы
set(MAIN_SOURCE main.cpp)

# Создаем исполняемый файл
add_executable(FirstClassAsLibrary ${MAIN_SOURCE})

# Добавляем директорию с заголовочными файлами
# PRIVATE - включаемые файлы доступны только этой цели
target_include_directories(FirstClassAsLibrary PRIVATE include)

# Добавляем поддиректорию src, содержащую отдельный CMakeLists.txt
# В этой поддиректории создается библиотека fc
add_subdirectory(src)

# Линкуем нашу программу с библиотекой fc
target_link_libraries(FirstClassAsLibrary fc)

# Настройка установки: копирование файлов при выполнении 'make install'
# TARGETS - что устанавливаем
# RUNTIME DESTINATION - куда устанавливаем исполняемые файлы
install(
    TARGETS FirstClassAsLibrary
    RUNTIME DESTINATION bin
)

