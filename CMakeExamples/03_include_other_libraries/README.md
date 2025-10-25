# Пример 03: Использование внешних библиотек

## Описание

Этот пример демонстрирует подключение и использование внешних библиотек в проекте CMake. В качестве примера используется библиотека Boost (компоненты filesystem и system).

## Что демонстрирует этот пример

1. **find_package()** - автоматический поиск установленных библиотек
2. **Указание компонентов библиотеки** (COMPONENTS)
3. **Использование IMPORTED targets** (современный подход)
4. **Установку стандарта C++** через CMAKE_CXX_STANDARD
5. **Комбинирование собственных и внешних библиотек**

## Требования

Для сборки этого примера необходимо установить Boost:

```bash
# Ubuntu/Debian
sudo apt-get install libboost-filesystem-dev libboost-system-dev

# macOS (Homebrew)
brew install boost

# Fedora/RHEL
sudo dnf install boost-devel
```

## Структура проекта

```
03_include_other_libraries/
├── CMakeLists.txt           # Главный файл конфигурации
├── main.cpp                 # Главная программа
├── include/                 # Заголовочные файлы
│   └── ListDir.h
├── src/                     # Исходники библиотеки
│   ├── CMakeLists.txt       # Конфигурация библиотеки
│   └── ListDir.cpp          # Реализация с использованием Boost
└── README.md                # Этот файл
```

## Как собрать и запустить

```bash
mkdir build
cd build
cmake ..
make

# Запуск (покажет содержимое директории)
./ListDirectory /path/to/directory
```

## Ключевые концепции

### find_package

```cmake
find_package(Boost COMPONENTS filesystem system REQUIRED)
```

**find_package** ищет установленную библиотеку в системе и создает переменные для ее использования:

- `COMPONENTS` - указывает конкретные компоненты библиотеки
- `REQUIRED` - сборка прервется с ошибкой, если библиотека не найдена
- `QUIET` - подавить сообщения (опционально)

**Создаваемые переменные:**
- `Boost_FOUND` - найден ли Boost
- `Boost_INCLUDE_DIRS` - пути к заголовочным файлам
- `Boost_LIBRARIES` - библиотеки для линковки
- `Boost_VERSION` - версия найденной библиотеки

### IMPORTED targets (современный подход)

```cmake
target_link_libraries(ListDir Boost::filesystem)
```

Начиная с CMake 3.5+, **find_package** создает IMPORTED targets (например, `Boost::filesystem`). Это современный и рекомендуемый способ работы с библиотеками.

**Преимущества IMPORTED targets:**
- Автоматически добавляют include directories
- Автоматически добавляют необходимые флаги компиляции
- Транзитивные зависимости обрабатываются автоматически
- Более чистый и понятный код

### Устаревший подход (для справки)

```cmake
# Устаревший способ (НЕ рекомендуется для новых проектов)
target_include_directories(ListDir PRIVATE ${Boost_INCLUDE_DIRS})
target_link_directories(ListDir PRIVATE ${Boost_LIBRARY_DIRS})
target_link_libraries(ListDir ${Boost_LIBRARIES})
```

Эти строки оставлены в коде для совместимости со старыми версиями CMake, но при использовании IMPORTED targets они не нужны.

### Установка стандарта C++

```cmake
set(CMAKE_CXX_STANDARD 11)
```

Устанавливает стандарт C++ для всего проекта. Boost требует как минимум C++11.

**Альтернативные способы:**

```cmake
# Для конкретной цели
set_target_properties(MyTarget PROPERTIES CXX_STANDARD 11)

# С требованием строгого соблюдения
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```

### Опции конфигурации Boost

```cmake
#set(Boost_USE_STATIC_LIBS ON)        # Использовать статические библиотеки
#set(Boost_USE_MULTITHREADED ON)      # Использовать многопоточные версии
```

Эти опции нужно установить **до** вызова find_package(Boost).

## Как CMake находит библиотеки

CMake ищет библиотеки в нескольких местах:

1. **CMAKE_PREFIX_PATH** - пользовательские пути
2. Системные пути (/usr, /usr/local и т.д.)
3. Переменные окружения (например, BOOST_ROOT)

Если библиотека установлена в нестандартное место:

```bash
cmake -DCMAKE_PREFIX_PATH=/path/to/boost ..
# или
cmake -DBOOST_ROOT=/path/to/boost ..
```

## Поиск доступных компонентов

Чтобы узнать, какие компоненты доступны в библиотеке:

```bash
# Показать все найденные переменные Boost
cmake .. -LAH | grep Boost

# Получить список компонентов
ls /usr/lib/x86_64-linux-gnu/libboost_*.so
```

## Отладка проблем с find_package

```cmake
# Добавьте в CMakeLists.txt для отладки
set(Boost_DEBUG ON)
find_package(Boost COMPONENTS filesystem system REQUIRED)
```

Это выведет детальную информацию о процессе поиска.

## Различия с предыдущим примером

| Аспект | 02_multiple_projects | 03_include_other_libraries |
|--------|----------------------|----------------------------|
| Внешние библиотеки | Нет | Да (Boost) |
| find_package | Не используется | Используется |
| Стандарт C++ | Не указан | C++11 |
| IMPORTED targets | Нет | Да (Boost::filesystem) |

## Что дальше?

Следующий пример **04_generate_code_from_python** покажет, как генерировать код во время сборки с помощью Python скриптов.
