# Пример 02: Создание и использование библиотеки

## Описание

Этот пример демонстрирует создание динамической библиотеки и ее использование в исполняемом файле. Также показано, как установить проект в систему и настроить RPATH для корректной работы после установки.

## Что демонстрирует этот пример

1. **Создание динамической библиотеки** (SHARED library)
2. **Использование add_subdirectory()** для подключения подпроектов
3. **Линковку библиотеки** с исполняемым файлом
4. **Установку проекта** через install()
5. **Настройку RPATH** для поиска библиотек во время выполнения
6. **target_include_directories()** для управления путями заголовков

## Структура проекта

```
02_multiple_projects/
├── CMakeLists.txt           # Главный файл конфигурации
├── main.cpp                 # Главная программа
├── include/                 # Заголовочные файлы
│   └── FirstClass.h
├── src/                     # Исходники библиотеки
│   ├── CMakeLists.txt       # Конфигурация библиотеки
│   └── FirstClass.cpp       # Реализация библиотеки
└── README.md                # Этот файл
```

## Как собрать и установить

```bash
# Сборка
mkdir build
cd build
cmake ..
make

# Запуск (до установки)
./FirstClassAsLibrary

# Установка (по умолчанию в /usr/local или dist/)
make install

# Запуск после установки
cd dist/bin
./FirstClassAsLibrary
```

## Ключевые концепции

### Создание библиотеки

В файле `src/CMakeLists.txt`:

```cmake
add_library(fc SHARED ${SOURCE_LIB})
```

- `fc` - имя библиотеки (будет создан файл libfc.so или libfc.dylib)
- `SHARED` - тип библиотеки (динамическая)
- Альтернатива: `STATIC` для статической библиотеки

### Подключение поддиректорий

```cmake
add_subdirectory(src)
```

Эта команда выполняет CMakeLists.txt из директории `src`, что позволяет организовать проект модульно.

### Линковка библиотеки

```cmake
target_link_libraries(FirstClassAsLibrary fc)
```

Линкует исполняемый файл с библиотекой `fc`.

### RPATH - путь поиска библиотек

```cmake
if (NOT APPLE)
    set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
else()
    set(CMAKE_INSTALL_RPATH "@loader_path/../lib")
endif()
```

**RPATH** (Run-time search Path) указывает, где искать динамические библиотеки при запуске программы:

- **Linux**: `$ORIGIN` - директория, где находится исполняемый файл
- **macOS**: `@loader_path` - аналог `$ORIGIN`
- `$ORIGIN/../lib` означает: "ищи библиотеки в директории lib на уровень выше исполняемого файла"

Это позволяет запускать программу без установки библиотек в системные пути.

### Установка проекта

```cmake
install(
    TARGETS FirstClassAsLibrary
    RUNTIME DESTINATION bin
)

install(
    TARGETS fc
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
```

- `RUNTIME` - куда устанавливать исполняемые файлы
- `LIBRARY` - куда устанавливать библиотеки (.so/.dylib)
- `PUBLIC_HEADER` - куда устанавливать заголовочные файлы

### target_include_directories

```cmake
target_include_directories(FirstClassAsLibrary PRIVATE include)
```

Добавляет директорию `include` в пути поиска заголовочных файлов только для цели `FirstClassAsLibrary`.

**Уровни видимости:**
- `PRIVATE` - только для этой цели
- `PUBLIC` - для этой цели и всех, кто ее использует
- `INTERFACE` - только для тех, кто использует эту цель

### file(GLOB_RECURSE)

```cmake
file(GLOB_RECURSE LIBRARY_HEADERS "${FirstClassAsLibrary_SOURCE_DIR}/include/*.h")
```

Рекурсивно находит все файлы, соответствующие паттерну. Результат сохраняется в переменную `LIBRARY_HEADERS`.

## Различия с предыдущим примером

| Аспект | 01_headers_added | 02_multiple_projects |
|--------|------------------|----------------------|
| Создание библиотеки | Нет | Да (динамическая) |
| Использование add_subdirectory | Нет | Да |
| Установка | Нет | Да (install) |
| RPATH | Не нужен | Настроен |
| Количество CMakeLists.txt | 1 | 2 (главный + для библиотеки) |

## Полезные команды

```bash
# Установка в конкретную директорию
cmake -DCMAKE_INSTALL_PREFIX=/path/to/install ..

# Просмотр связанных библиотек (Linux)
ldd ./FirstClassAsLibrary

# Просмотр связанных библиотек (macOS)
otool -L ./FirstClassAsLibrary
```

## Что дальше?

Следующий пример **03_include_other_libraries** покажет, как использовать внешние библиотеки (на примере Boost).
