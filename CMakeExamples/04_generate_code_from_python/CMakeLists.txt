# ============================================================================
# Пример 04: Генерация кода во время сборки
# ============================================================================
# Демонстрирует:
# - Использование add_custom_target для выполнения скриптов
# - Генерацию кода из данных (JSON -> C++ заголовочный файл)
# - Управление зависимостями между целями
# - Создание графа зависимостей проекта

cmake_minimum_required(VERSION 3.10)

project(GenerateArray)

# Ищем интерпретатор Python
# REQUIRED означает, что сборка прервется, если Python не найден
find_package(Python COMPONENTS Interpreter REQUIRED)

# Создаем пользовательскую цель для генерации кода
# add_custom_target выполняется ВСЕГДА при сборке (если есть зависимости)
add_custom_target(
  RunGenerator
  # BYPRODUCTS - файлы, которые будут созданы этой целью
  BYPRODUCTS array.h
  # COMMAND - команда для выполнения
  # Python::Interpreter - путь к интерпретатору Python (найден через find_package)
  COMMAND Python::Interpreter ${PROJECT_SOURCE_DIR}/generate_array.py ${PROJECT_SOURCE_DIR}/data.json array.h
  # DEPENDS - файлы, от которых зависит генерация
  # Если они изменятся, цель будет пересобрана
  DEPENDS generate_array.py data.json
  # COMMENT - сообщение, выводимое при сборке
  COMMENT "Generating array from json"
)

set(SOURCES main.cpp)

# Создаем исполняемый файл
add_executable(GenerateArray ${SOURCES})

# Добавляем зависимость: GenerateArray должен собираться ПОСЛЕ RunGenerator
# Это гарантирует, что array.h будет создан до компиляции main.cpp
add_dependencies(GenerateArray RunGenerator)

# Создаем граф зависимостей проекта в формате Graphviz
# ALL означает, что эта цель всегда выполняется при сборке
# Результат: файл foo.dot, который можно визуализировать
add_custom_target(graphviz ALL
                  "${CMAKE_COMMAND}" "--graphviz=foo" .
                  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")

# Добавляем директорию сборки в include paths
# Это необходимо, потому что array.h генерируется в CMAKE_BINARY_DIR
target_include_directories(GenerateArray PRIVATE ${CMAKE_BINARY_DIR})
