# ============================================================================
# Supplementary 02: Опциональные библиотеки
# ============================================================================
# Демонстрирует:
# - Использование option() для создания опций сборки
# - Условную компиляцию с if/endif
# - Добавление опциональных библиотек и определений компилятора
# - Настройку префикса установки

cmake_minimum_required(VERSION 3.10)
project(Math)

# Создаем опцию сборки (можно изменить через cmake -DUSE_MYMATH=OFF)
# option создает булеву переменную, которую можно переключать
option(USE_MYMATH "Use Module Math" ON)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 11)

# Устанавливаем префикс установки (куда будут устанавливаться файлы)
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/dist)

# Настройка путей вывода
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Условная компиляция: подключаем библиотеку только если опция включена
if (USE_MYMATH)
    # Добавляем макрос USE_MYMATH для условной компиляции в коде
    add_compile_definitions(USE_MYMATH)

    # Добавляем директорию с заголовочными файлами библиотеки
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")

    # Подключаем поддиректорию с библиотекой
    add_subdirectory(MathFunctions)

    # Добавляем библиотеку к списку для линковки
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif(USE_MYMATH)

# Создаем исполняемый файл
add_executable(Math main.cpp)

# Линкуем с дополнительными библиотеками (если они были добавлены)
target_link_libraries(Math ${EXTRA_LIBS})

# Установка
install(TARGETS Math DESTINATION bin)



