# ============================================================================
# Supplementary 01: Версионирование проекта
# ============================================================================
# Демонстрирует:
# - Использование configure_file для генерации конфигурационных файлов
# - Внедрение версии проекта в код через макросы
# - Шаблонизацию заголовочных файлов

cmake_minimum_required(VERSION 3.10)

project(Configurator)

# Определяем версию проекта
# Эти переменные будут использованы в Config.h.in
set(Configurator_VERSION_MAJOR 1)
set(Configurator_VERSION_MINOR 1)

# Генерируем заголовочный файл из шаблона
# configure_file заменяет все @VAR@ или ${VAR} в .in файле
# на значения соответствующих переменных CMake
configure_file(
    ${PROJECT_SOURCE_DIR}/Config.h.in   # Входной шаблон
    ${PROJECT_SOURCE_DIR}/Config.h      # Выходной файл
)

# Настройка путей вывода
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Добавляем директорию с сгенерированным Config.h
include_directories(${PROJECT_SOURCE_DIR})

# Создаем исполняемый файл
add_executable(Configurator ${PROJECT_SOURCE_DIR}/Config.cpp)