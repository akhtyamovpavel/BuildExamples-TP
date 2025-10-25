# Пример 07: Создание собственных Find-модулей

## Описание

Этот пример демонстрирует создание пользовательских Find-модулей для поиска библиотек, которые не предоставляют собственные CMake конфигурационные файлы.

## Что демонстрирует этот пример

1. **Создание Find-модулей** (FindXXX.cmake)
2. **CMAKE_MODULE_PATH** - настройка путей поиска модулей
3. **find_library()** и **find_path()** - поиск библиотек и заголовков
4. **Установка переменных** для использования найденной библиотеки
5. **Переиспользование установленных библиотек** из других проектов

## Зависимости

Этот пример использует библиотеку `fc`, созданную в примере **02_multiple_projects**. Сначала нужно собрать и установить ее:

```bash
# 1. Соберите и установите библиотеку fc
cd ../02_multiple_projects
mkdir build && cd build
cmake ..
make
make install

# Библиотека будет установлена в dist/
# - dist/lib/libfc.so (или .dylib на macOS)
# - dist/include/FirstClass.h
```

## Структура проекта

```
07-find-module/
├── CMakeLists.txt           # Главная конфигурация
├── main.cpp                 # Программа, использующая библиотеку fc
├── cmake/                   # Директория с Find-модулями
│   └── FindFC.cmake         # Модуль для поиска библиотеки fc
└── README.md                # Этот файл
```

## Как собрать и запустить

```bash
mkdir build
cd build
cmake ..
make
./main
```

## Ключевые концепции

### CMAKE_MODULE_PATH

```cmake
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" ${CMAKE_SOURCE_DIR}/cmake)
```

Добавляет директорию `cmake/` в список путей, где CMake ищет модули `Find<Package>.cmake`.

**По умолчанию CMake ищет в:**
- Стандартных системных путях
- `${CMAKE_ROOT}/Modules/`

**После добавления также ищет в:**
- `${CMAKE_SOURCE_DIR}/cmake/`

### Структура Find-модуля

Типичный Find-модуль должен:

1. Искать заголовочные файлы (`find_path`)
2. Искать библиотеки (`find_library`)
3. Устанавливать переменные для использования
4. Обрабатывать REQUIRED и QUIET
5. Использовать `find_package_handle_standard_args`

**Пример FindFC.cmake:**

```cmake
# Поиск заголовочного файла
find_path(FC_INCLUDE_DIR
    NAMES FirstClass.h
    PATHS /path/to/dist/include
    DOC "Path to FC headers"
)

# Поиск библиотеки
find_library(FC_LIBRARIES
    NAMES fc
    PATHS /path/to/dist/lib
    DOC "Path to FC library"
)

# Получение директории библиотеки
get_filename_component(FC_LIBRARY_DIR ${FC_LIBRARIES} DIRECTORY)

# Проверка, что все найдено
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(FC
    REQUIRED_VARS FC_LIBRARIES FC_INCLUDE_DIR
)

# Создание IMPORTED target (рекомендуется)
if(FC_FOUND AND NOT TARGET FC::fc)
    add_library(FC::fc UNKNOWN IMPORTED)
    set_target_properties(FC::fc PROPERTIES
        IMPORTED_LOCATION "${FC_LIBRARIES}"
        INTERFACE_INCLUDE_DIRECTORIES "${FC_INCLUDE_DIR}"
    )
endif()
```

### find_path()

```cmake
find_path(<VAR> NAMES <name> PATHS <path1> <path2> ...)
```

Ищет директорию, содержащую указанный файл.

**Параметры:**
- `<VAR>` - переменная для результата
- `NAMES` - имя искомого файла
- `PATHS` - где искать
- `PATH_SUFFIXES` - поддиректории для поиска
- `DOC` - описание для cmake-gui

### find_library()

```cmake
find_library(<VAR> NAMES <name> PATHS <path1> <path2> ...)
```

Ищет файл библиотеки (.so, .a, .dylib, .lib).

**Особенности:**
- Автоматически добавляет префиксы (lib) и суффиксы (.so, .a)
- Ищет в стандартных системных путях
- Можно указать `NAMES libfc fc` для разных вариантов

### find_package_handle_standard_args

```cmake
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(FC
    REQUIRED_VARS FC_LIBRARIES FC_INCLUDE_DIR
    VERSION_VAR FC_VERSION
)
```

Обрабатывает стандартные опции `REQUIRED` и `QUIET`, устанавливает `FC_FOUND`.

## Переменные, создаваемые Find-модулем

После успешного выполнения `find_package(FC)` доступны:

```cmake
FC_FOUND           # TRUE если библиотека найдена
FC_INCLUDE_DIR     # Путь к заголовочным файлам
FC_LIBRARIES       # Путь к библиотеке
FC_LIBRARY_DIR     # Директория с библиотекой
FC_VERSION         # Версия (если определена)
```

## Использование найденной библиотеки

### Устаревший способ

```cmake
target_include_directories(main PRIVATE ${FC_INCLUDE_DIR})
target_link_directories(main PRIVATE ${FC_LIBRARY_DIR})
target_link_libraries(main ${FC_LIBRARIES})
```

### Современный способ (IMPORTED target)

```cmake
target_link_libraries(main FC::fc)
```

IMPORTED target автоматически добавляет include directories и библиотеки.

## Расширенные возможности Find-модулей

### Поддержка версий

```cmake
# В FindFC.cmake
file(READ "${FC_INCLUDE_DIR}/version.h" VERSION_CONTENT)
string(REGEX MATCH "VERSION_MAJOR ([0-9]+)" _ "${VERSION_CONTENT}")
set(FC_VERSION_MAJOR ${CMAKE_MATCH_1})
# ... аналогично для MINOR

set(FC_VERSION "${FC_VERSION_MAJOR}.${FC_VERSION_MINOR}")
```

### Поиск компонентов

```cmake
# find_package(FC COMPONENTS core utils REQUIRED)

foreach(comp ${FC_FIND_COMPONENTS})
    find_library(FC_${comp}_LIBRARY
        NAMES fc_${comp}
        PATHS ${FC_LIBRARY_DIR}
    )
endforeach()
```

### Переменные окружения

```cmake
# Пользователь может установить FC_ROOT=/path/to/fc
find_path(FC_INCLUDE_DIR
    NAMES FirstClass.h
    PATHS $ENV{FC_ROOT}/include
          /usr/local/include
          /usr/include
)
```

## Когда создавать Find-модули

**Создавайте Find-модуль когда:**
- Библиотека не предоставляет CMake config файлы
- Нужна поддержка legacy библиотек
- Требуется особая логика поиска
- Библиотека устанавливается в нестандартные места

**Не нужен Find-модуль когда:**
- Библиотека предоставляет `<Package>Config.cmake`
- Можно использовать `pkg-config` через `pkg_check_modules()`
- Используется header-only библиотека

## Альтернативы Find-модулям

### 1. Config файлы (предпочтительно)

Современные библиотеки предоставляют `<Package>Config.cmake`:

```cmake
find_package(Boost CONFIG REQUIRED)
find_package(OpenCV CONFIG REQUIRED)
```

### 2. pkg-config

```cmake
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0)
target_link_libraries(main ${GLIB_LIBRARIES})
```

### 3. FetchContent (для исходников)

```cmake
include(FetchContent)
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(json)
target_link_libraries(main nlohmann_json::nlohmann_json)
```

## Отладка Find-модулей

```bash
# Показать, где CMake ищет
cmake --trace-expand .. 2>&1 | grep -i findfc

# Показать все переменные
cmake .. -LAH | grep FC

# Использовать find_package в режиме отладки
cmake -DFC_DEBUG=ON ..
```

В FindFC.cmake:
```cmake
if(FC_DEBUG)
    message(STATUS "FC_INCLUDE_DIR: ${FC_INCLUDE_DIR}")
    message(STATUS "FC_LIBRARIES: ${FC_LIBRARIES}")
endif()
```

## Лучшие практики

1. **Используйте find_package_handle_standard_args** для стандартной обработки
2. **Создавайте IMPORTED targets** для современного использования
3. **Документируйте переменные** в комментариях модуля
4. **Поддерживайте REQUIRED и QUIET**
5. **Кешируйте результаты** через CACHE в find_path/find_library
6. **Используйте переменные окружения** для гибкости

## Различия с предыдущими примерами

| Аспект | 03_include_other_libraries | 07-find-module |
|--------|----------------------------|----------------|
| Поиск библиотек | Встроенный FindBoost | Пользовательский FindFC |
| CMAKE_MODULE_PATH | Не нужен | Настраивается |
| Создание модулей | Нет | Да |
| Цель | Использование библиотек | Создание поддержки поиска |

## Что дальше?

Изучите **06-cmake-python** для интеграции C++ с Python через pybind11 и Boost.Python.
