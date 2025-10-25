# Supplementary Examples - Дополнительные примеры CMake

## Описание

Эта директория содержит набор дополнительных примеров, демонстрирующих специальные возможности и продвинутые техники CMake.

## Содержание

### 00-hello-world - Альтернативный Hello World

Альтернативный вариант минимального проекта, демонстрирующий:
- Устаревшие способы настройки путей (для обратной совместимости)
- `EXECUTABLE_OUTPUT_PATH` и `LIBRARY_OUTPUT_PATH`
- Глобальное добавление include директорий через `include_directories()`

**Отличия от основного примера 00:**
- Использование более старых переменных CMake
- Показывает эволюцию практик CMake
- Полезно для понимания legacy кода

**Как собрать:**
```bash
cd 00-hello-world
mkdir build && cd build
cmake .. && make
../bin/hello
```

### 01-versioning - Версионирование проекта

Демонстрирует внедрение информации о версии в код через `configure_file()`.

**Основные концепции:**
- `configure_file()` - генерация файлов из шаблонов
- Замена переменных `@VAR@` или `${VAR}` на их значения
- Внедрение версии, даты сборки, конфигурации в код

**Файлы:**
- `Config.h.in` - шаблон с переменными `@Configurator_VERSION_MAJOR@`
- `Config.h` - сгенерированный файл с фактическими значениями

**Как собрать:**
```bash
cd 01-versioning
mkdir build && cd build
cmake .. && make
../bin/Configurator
```

**Пример Config.h.in:**
```cpp
#define VERSION_MAJOR @Configurator_VERSION_MAJOR@
#define VERSION_MINOR @Configurator_VERSION_MINOR@
```

**После configure_file станет:**
```cpp
#define VERSION_MAJOR 1
#define VERSION_MINOR 1
```

### 02-library - Опциональные библиотеки

Показывает условную компиляцию с использованием опций сборки.

**Основные концепции:**
- `option()` - создание булевых опций для пользователя
- Условная компиляция (`if/endif`)
- `add_compile_definitions()` - добавление макросов препроцессора
- Опциональное подключение библиотек

**Структура:**
```
02-library/
├── CMakeLists.txt
├── main.cpp
└── MathFunctions/
    ├── CMakeLists.txt
    ├── MathFunctions.h
    └── mysqrt.cpp
```

**Как собрать:**
```bash
cd 02-library
mkdir build && cd build

# С библиотекой (по умолчанию)
cmake .. && make

# Без библиотеки
cmake -DUSE_MYMATH=OFF .. && make
```

**В коде:**
```cpp
#ifdef USE_MYMATH
  result = mysqrt(x);  // Своя реализация
#else
  result = sqrt(x);    // Стандартная функция
#endif
```

## Сравнение с основными примерами

| Пример | Основная тема | Аналог в основных примерах |
|--------|---------------|----------------------------|
| 00-hello-world | Устаревшие практики | 00_hello_world (современный подход) |
| 01-versioning | Генерация конфигурации | Уникален |
| 02-library | Условная компиляция | 02_multiple_projects (без условий) |

## Ключевые различия в подходах

### Современный vs Устаревший (00-hello-world)

**Устаревший подход:**
```cmake
include_directories(${PROJECT_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
```

**Современный подход:**
```cmake
target_include_directories(MyTarget PRIVATE ${PROJECT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
```

### configure_file vs Генерация кода (01-versioning)

**configure_file:**
- Простая замена переменных в шаблонах
- Выполняется на этапе конфигурации (cmake)
- Подходит для статической конфигурации

**add_custom_command:**
- Выполнение произвольных команд
- Выполняется на этапе сборки (make)
- Подходит для динамической генерации

## Практические применения

### Версионирование (01-versioning)

```cmake
# CMakeLists.txt
set(PROJECT_VERSION_MAJOR 2)
set(PROJECT_VERSION_MINOR 5)
set(PROJECT_VERSION_PATCH 1)
configure_file(version.h.in version.h)
```

```cpp
// version.h.in
#define VERSION "@PROJECT_VERSION_MAJOR@.@PROJECT_VERSION_MINOR@.@PROJECT_VERSION_PATCH@"
#define BUILD_DATE "@BUILD_DATE@"
```

```cpp
// main.cpp
#include "version.h"
std::cout << "Version: " << VERSION << std::endl;
```

### Опциональные функции (02-library)

**Сценарии использования:**
- Debug vs Release функциональность
- Платформо-специфичный код
- Экспериментальные фичи
- Поддержка различных бэкендов (OpenGL/Vulkan, CPU/GPU)

```cmake
option(ENABLE_GPU "Enable GPU acceleration" OFF)
option(BUILD_TESTS "Build test suite" ON)
option(USE_SYSTEM_LIBS "Use system libraries instead of bundled" OFF)
```

## Полезные команды

```bash
# Просмотр доступных опций
cmake -L

# Просмотр опций с описаниями
cmake -LH

# Изменение опций
cmake -DUSE_MYMATH=OFF -DENABLE_TESTS=ON ..

# Интерактивная настройка
ccmake ..  # или cmake-gui
```

## Рекомендации

1. **Для новых проектов:** используйте современный подход из основных примеров
2. **Для legacy кода:** изучите 00-hello-world для понимания старых практик
3. **Версионирование:** всегда внедряйте версию в код через configure_file
4. **Опции:** используйте option() для всех настраиваемых функций

## Что дальше?

- Изучите **06-cmake-python** для интеграции C++ с Python
- Переходите к **07-find-module** для создания Find-модулей
