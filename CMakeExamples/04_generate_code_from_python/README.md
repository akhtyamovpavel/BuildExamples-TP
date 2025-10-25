# Пример 04: Генерация кода во время сборки

## Описание

Этот пример демонстрирует генерацию исходного кода во время сборки проекта с помощью Python скрипта. Показывает, как интегрировать внешние инструменты и скрипты в процесс сборки CMake.

## Что демонстрирует этот пример

1. **add_custom_target** - создание пользовательских целей сборки
2. **add_custom_command** - выполнение произвольных команд при сборке
3. **add_dependencies** - управление зависимостями между целями
4. **find_package(Python)** - поиск интерпретатора Python
5. **Генерация графа зависимостей** проекта (Graphviz)

## Требования

```bash
# Python 3 должен быть установлен
python3 --version

# Опционально: для визуализации графа зависимостей
sudo apt-get install graphviz  # Ubuntu/Debian
brew install graphviz          # macOS
```

## Структура проекта

```
04_generate_code_from_python/
├── CMakeLists.txt           # Конфигурация сборки
├── main.cpp                 # Программа, использующая сгенерированный код
├── generate_array.py        # Python скрипт для генерации
├── data.json                # Входные данные (массив чисел)
├── array.h                  # Сгенерированный заголовочный файл (создается при сборке)
└── README.md                # Этот файл
```

## Как это работает

1. Python скрипт `generate_array.py` читает `data.json`
2. Преобразует JSON массив в C++ код: `int arr[] = {1, 2, 4, 5, ...};`
3. Сохраняет результат в `array.h`
4. `main.cpp` включает сгенерированный `array.h`
5. Программа компилируется с использованием сгенерированных данных

## Как собрать и запустить

```bash
mkdir build
cd build
cmake ..
make

# Запуск программы
./GenerateArray

# Просмотр сгенерированного файла
cat array.h
```

## Ключевые концепции

### find_package(Python)

```cmake
find_package(Python COMPONENTS Interpreter REQUIRED)
```

Ищет интерпретатор Python в системе. Создает IMPORTED target `Python::Interpreter`, который можно использовать в командах.

**Компоненты:**
- `Interpreter` - интерпретатор Python
- `Development` - заголовочные файлы и библиотеки для разработки расширений
- `NumPy` - поддержка NumPy (опционально)

### add_custom_target

```cmake
add_custom_target(
  RunGenerator
  BYPRODUCTS array.h
  COMMAND Python::Interpreter ${PROJECT_SOURCE_DIR}/generate_array.py ...
  DEPENDS generate_array.py data.json
  COMMENT "Generating array from json"
)
```

**Параметры:**
- `RunGenerator` - имя цели
- `BYPRODUCTS` - файлы, которые будут созданы (для Ninja generator)
- `COMMAND` - команда для выполнения
- `DEPENDS` - зависимости; если эти файлы изменятся, цель будет пересобрана
- `COMMENT` - сообщение при выполнении

**Важно:** add_custom_target **всегда** выполняется при сборке (если есть зависимости от этой цели).

### add_custom_command vs add_custom_target

| Аспект | add_custom_command | add_custom_target |
|--------|-------------------|-------------------|
| Когда выполняется | Только если выходной файл устарел | Всегда (если есть зависимости) |
| Выходные файлы | Требуются (OUTPUT) | Опциональны (BYPRODUCTS) |
| Имя в make | Нет | Да (можно вызвать `make RunGenerator`) |

### add_dependencies

```cmake
add_dependencies(GenerateArray RunGenerator)
```

Устанавливает зависимость между целями. Гарантирует, что `RunGenerator` будет выполнен **до** сборки `GenerateArray`.

**Без этого:** компиляция может начаться до завершения генерации, что приведет к ошибке.

### Использование сгенерированных файлов

```cmake
target_include_directories(GenerateArray PRIVATE ${CMAKE_BINARY_DIR})
```

Добавляем директорию сборки в пути поиска, потому что `array.h` генерируется именно там.

В `main.cpp`:
```cpp
#include "array.h"  // Сгенерированный файл из CMAKE_BINARY_DIR
```

## Генерация графа зависимостей

```cmake
add_custom_target(graphviz ALL
                  "${CMAKE_COMMAND}" "--graphviz=foo" .
                  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
```

Создает файл `foo.dot` с графом зависимостей проекта.

**Визуализация:**
```bash
cd build
dot -Tpng foo.dot -o graph.png
# или
dot -Tpng file.dot -o file.png
```

**Параметры:**
- `ALL` - выполнять при каждой сборке
- `--graphviz=foo` - имя выходного файла
- `WORKING_DIRECTORY` - где выполнять команду

## Сценарии использования

### 1. Генерация конфигурации

Преобразование JSON/YAML конфигурации в C++ константы:

```python
# config.json → config.h
const char* API_URL = "https://api.example.com";
const int MAX_RETRIES = 3;
```

### 2. Кодогенерация из схем

Генерация C++ классов из JSON Schema, Protocol Buffers, или других схем данных.

### 3. Обработка ресурсов

Встраивание файлов (изображений, шейдеров) в исполняемый файл:

```python
# Convert image.png → image_data.h
const unsigned char image_data[] = {0x89, 0x50, 0x4E, ...};
```

### 4. Генерация таблиц

Создание lookup tables, таблиц CRC, и других предвычисленных данных.

## Практический пример: изменение данных

1. Откройте `data.json` и измените массив:
```json
[100, 200, 300]
```

2. Пересоберите проект:
```bash
cd build
make
```

3. CMake обнаружит изменение `data.json` и автоматически перегенерирует `array.h`

## Отладка

### Проблема: генерация не запускается

```cmake
# Добавьте VERBATIM для точного выполнения команды
COMMAND Python::Interpreter ${PROJECT_SOURCE_DIR}/generate_array.py
VERBATIM
```

### Проблема: файл не найден при компиляции

Убедитесь, что:
1. Добавлена зависимость: `add_dependencies(GenerateArray RunGenerator)`
2. Директория сборки в include paths: `target_include_directories(...)`

### Посмотреть команды

```bash
make VERBOSE=1
```

## Различия с предыдущим примером

| Аспект | 03_include_other_libraries | 04_generate_code_from_python |
|--------|----------------------------|------------------------------|
| Внешние инструменты | Только библиотеки | Python скрипты |
| Генерация кода | Нет | Да |
| add_custom_target | Не используется | Используется |
| Зависимости целей | Неявные | Явные (add_dependencies) |

## Что дальше?

Изучите примеры в **05_supplementary** для специальных возможностей CMake:
- Версионирование проекта
- Опциональные библиотеки
- configure_file для шаблонов

Затем переходите к **07-find-module** для создания собственных Find-модулей.
