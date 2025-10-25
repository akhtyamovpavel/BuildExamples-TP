# BuildExamples-TP

Образовательный репозиторий с примерами использования различных систем сборки проектов.

## Оглавление

- [Описание проекта](#описание-проекта)
- [Глоссарий](#глоссарий)
- [Структура проекта](#структура-проекта)
- [Системы сборки](#системы-сборки)
- [Требования](#требования)
- [Быстрый старт](#быстрый-старт)

---

## Описание проекта

Данный репозиторий представляет собой коллекцию практических примеров работы с популярными системами сборки программного обеспечения. Проект предназначен для обучения и демонстрации различных подходов к организации процесса сборки в современной разработке.

Каждая директория содержит примеры от простых "Hello World" приложений до более сложных сценариев с подключением внешних библиотек, генерацией кода и многомодульными проектами.

---

## Глоссарий

### Общие термины

- **Build System (Система сборки)** — инструмент автоматизации процесса компиляции исходного кода в исполняемые файлы или библиотеки
- **Source File (Исходный файл)** — файл с программным кодом на языке программирования
- **Object File (Объектный файл)** — промежуточный файл, содержащий машинный код после компиляции (расширение `.o` или `.obj`)
- **Executable (Исполняемый файл)** — готовая программа, которую можно запустить
- **Library (Библиотека)** — набор предварительно скомпилированного кода для повторного использования
  - **Static Library (Статическая библиотека)** — встраивается в исполняемый файл (`.a`, `.lib`)
  - **Shared Library (Разделяемая библиотека)** — загружается во время выполнения (`.so`, `.dll`, `.dylib`)
- **Header File (Заголовочный файл)** — файл с объявлениями функций и классов (`.h`, `.hpp`)
- **Include Path** — путь поиска заголовочных файлов при компиляции
- **Linking (Компоновка)** — процесс объединения объектных файлов и библиотек в исполняемый файл
- **Target (Цель)** — конечный результат сборки (исполняемый файл, библиотека и т.д.)
- **Dependency (Зависимость)** — внешняя библиотека или модуль, необходимый для сборки проекта

### Специфичные термины систем сборки

#### CMake
- **CMakeLists.txt** — конфигурационный файл проекта CMake
- **Generator** — инструмент, создающий нативные build-файлы (Makefile, Visual Studio проекты и т.д.)
- **add_executable()** — команда создания исполняемого файла
- **add_library()** — команда создания библиотеки
- **target_link_libraries()** — команда связывания цели с библиотеками
- **find_package()** — поиск и подключение внешних пакетов

#### Make
- **Makefile** — файл с правилами сборки для GNU Make
- **Rule (Правило)** — описание как создать целевой файл из зависимостей
- **Phony Target** — цель, не создающая файл (например, `clean`, `all`)
- **Pattern Rule** — правило с использованием шаблонов (`%.o: %.cpp`)
- **Variable** — переменная в Makefile (например, `CFLAGS`, `CXX`)

#### Bazel
- **BUILD** — файл описания целей сборки Bazel
- **WORKSPACE** — корневой файл рабочей области Bazel
- **cc_binary** — правило для создания C++ исполняемого файла
- **cc_library** — правило для создания C++ библиотеки
- **cc_test** — правило для создания C++ теста

#### Maven
- **pom.xml** — Project Object Model, главный конфигурационный файл Maven
- **Artifact** — результат сборки (JAR, WAR и т.д.)
- **Dependency** — зависимость, описанная через координаты (groupId:artifactId:version)
- **Plugin** — расширение функциональности Maven
- **Phase** — фаза жизненного цикла сборки (compile, test, package и т.д.)

#### Gradle
- **build.gradle** — скрипт сборки Gradle
- **Task** — единица работы в Gradle
- **Plugin** — модуль, добавляющий функциональность (java, application и т.д.)
- **Repository** — источник зависимостей (jcenter, mavenCentral)

#### Cargo (Rust)
- **Cargo.toml** — манифест проекта Cargo
- **Crate** — единица компиляции в Rust (библиотека или исполняемый файл)
- **Edition** — версия языка Rust (2015, 2018, 2021)

#### AutoConf
- **configure.ac** — входной файл для Autoconf
- **Makefile.in** — шаблон Makefile
- **configure** — скрипт конфигурации, генерируемый Autoconf

---

## Структура проекта

```
BuildExamples-TP/
│
├── BashExamples/                    # Примеры сборки с помощью shell-скриптов
│   ├── 00_hello_world/              # Простейший пример
│   │   ├── main.cpp                 # Исходный файл
│   │   └── build.sh                 # Скрипт сборки
│   └── 01_headers_added/            # Пример с заголовочными файлами
│       ├── src/                     # Директория с исходниками
│       │   ├── FirstClass.h         # Заголовочный файл
│       │   ├── FirstClass.cpp       # Реализация класса
│       │   └── main.cpp             # Главный файл
│       ├── build.sh                 # Скрипт сборки
│       └── clean.sh                 # Скрипт очистки
│
├── MakeExamples/                    # Примеры с GNU Make
│   ├── 00_hello_world/              # Hello World с Makefile
│   │   ├── main.cpp
│   │   └── Makefile                 # Файл правил сборки
│   └── 01_headers_added/            # Сборка с заголовками
│       ├── src/ -> ../../BashExamples/01_headers_added/src  # Символическая ссылка
│       └── Makefile
│
├── CMakeExamples/                   # Примеры с CMake
│   ├── 00_hello_world/              # Простейший CMake проект
│   │   ├── main.cpp
│   │   └── CMakeLists.txt           # Конфигурация CMake
│   ├── 01_headers_added/            # Проект с заголовками
│   │   ├── src/ -> ../../BashExamples/01_headers_added/src
│   │   └── CMakeLists.txt
│   ├── 02_multiple_projects/        # Многомодульный проект
│   │   ├── include/                 # Публичные заголовки
│   │   │   └── FirstClass.h
│   │   ├── src/                     # Исходники библиотеки
│   │   │   ├── FirstClass.cpp
│   │   │   └── CMakeLists.txt       # CMake для подпроекта
│   │   ├── main.cpp                 # Главный файл приложения
│   │   └── CMakeLists.txt           # Корневой CMake
│   ├── 03_include_other_libraries/  # Подключение внешних библиотек
│   │   ├── include/
│   │   ├── src/
│   │   ├── main.cpp
│   │   └── CMakeLists.txt
│   ├── 04_generate_code_from_python/# Генерация кода из Python
│   │   ├── generate_array.py        # Python-скрипт генератор
│   │   ├── main.cpp
│   │   └── CMakeLists.txt
│   ├── 05_supplementary/            # Дополнительные примеры
│   │   ├── 00-hello-world/          # Базовый пример
│   │   ├── 01-versioning/           # Версионирование
│   │   └── 02-library/              # Создание библиотеки
│   │       └── MathFunctions/       # Модуль математических функций
│   ├── 06-cmake-python/             # Интеграция Python и C++
│   │   ├── boost-python/            # Примеры с Boost.Python
│   │   └── pybind11/                # Примеры с pybind11
│   │       ├── 00-simple-example/   # Простой пример
│   │       └── 02-python-packages/  # Создание Python пакетов
│   └── 07-find-module/              # Поиск и подключение модулей
│       ├── cmake/                   # Директория с CMake-модулями
│       ├── main.cpp
│       └── CMakeLists.txt
│
├── BazelExamples/                   # Примеры с Bazel
│   ├── 00-hello-world/              # Hello World на Bazel
│   │   └── main/
│   │       ├── hello-world.cpp
│   │       └── BUILD                # Файл сборки Bazel
│   ├── 01-library/                  # Создание библиотеки
│   │   └── BUILD
│   ├── 02-tests/                    # Модульное тестирование
│   │   ├── sqrt/                    # Библиотека с функцией
│   │   │   ├── sqrt.h
│   │   │   ├── sqrt.cpp
│   │   │   └── BUILD
│   │   ├── test/                    # Тесты
│   │   │   ├── sqrt_tests.cpp
│   │   │   └── BUILD
│   │   └── main/                    # Главное приложение
│   │       ├── main.cpp
│   │       └── BUILD
│   └── 03-cmake/                    # Интеграция CMake и Bazel
│       ├── examples/
│       └── main/
│
├── MavenExamples/                   # Примеры с Maven (Java)
│   ├── 00-exec-main-classes/        # Запуск главного класса
│   │   ├── src/
│   │   │   └── main/java/...        # Исходники Java
│   │   └── pom.xml                  # Maven конфигурация
│   ├── 01-add-tests/                # Добавление тестов
│   │   ├── src/
│   │   │   ├── main/java/...
│   │   │   └── test/java/...        # Тесты JUnit
│   │   └── pom.xml
│   ├── 02-libraries/                # Работа с библиотеками
│   │   ├── src/
│   │   └── pom.xml
│   ├── 03-packaging/                # Многомодульный проект
│   │   ├── core/                    # Модуль ядра
│   │   │   ├── src/
│   │   │   └── pom.xml
│   │   ├── service/                 # Модуль сервиса
│   │   │   ├── src/
│   │   │   └── pom.xml
│   │   └── pom.xml                  # Родительский POM
│   └── 04-gen-sources/              # Генерация исходников
│       ├── src/
│       └── pom.xml
│
├── GradleExamples/                  # Примеры с Gradle (Java/Kotlin)
│   ├── 01-simple-project/           # Простой проект
│   │   ├── gradle/                  # Gradle Wrapper
│   │   ├── src/
│   │   │   └── main/java/...
│   │   └── build.gradle             # Скрипт сборки
│   ├── 02-including-other-packages/ # Многомодульный проект
│   │   ├── app/                     # Модуль приложения
│   │   ├── first_class/             # Модуль библиотеки
│   │   ├── gradle/
│   │   └── settings.gradle          # Настройки проекта
│   └── 03-download-libraries/       # Загрузка зависимостей
│       ├── gradle/
│       ├── src/
│       └── build.gradle
│
├── CargoExamples/                   # Примеры с Cargo (Rust)
│   ├── O1-simple-example/           # Простой Rust проект
│   │   ├── src/
│   │   │   └── main.rs              # Исходник Rust
│   │   └── Cargo.toml               # Манифест Cargo
│   ├── O2-code-generation/          # Генерация кода (build.rs)
│   │   ├── src/
│   │   └── Cargo.toml
│   └── O3-native/                   # Интеграция с C/C++
│       ├── src/
│       └── Cargo.toml
│
├── AutoConfExamples/                # Примеры с GNU Autotools
│   ├── 01_hello_world/              # Базовый пример
│   │   ├── src/
│   │   │   └── main.cpp
│   │   └── configure.ac             # Конфигурация Autoconf
│   └── 02_opencv_included/          # Проект с OpenCV
│       └── src/
│           └── main/
│
├── SaltStack/                       # Конфигурации управления (DevOps)
│
├── .gitignore                       # Игнорируемые файлы Git
└── convert_to_tabs.sh               # Утилита конвертации отступов
```

---

## Системы сборки

### 1. Bash Scripts ([BashExamples/](BashExamples/))

**Описание:** Прямая сборка через shell-скрипты с вызовом компилятора.

**Плюсы:**
- Максимальная прозрачность процесса
- Не требует установки дополнительных инструментов
- Полный контроль над флагами компиляции

**Минусы:**
- Отсутствие автоматического определения зависимостей
- Требует ручной перекомпиляции всех файлов
- Плохо масштабируется

**Пример сборки:**
```bash
cd BashExamples/01_headers_added
./build.sh
./FirstClassProject
```

---

### 2. GNU Make ([MakeExamples/](MakeExamples/))

**Описание:** Классическая утилита сборки на основе правил и зависимостей.

**Плюсы:**
- Инкрементальная сборка (пересборка только измененных файлов)
- Широкое распространение в UNIX-системах
- Гибкая система правил

**Минусы:**
- Синтаксис требует привыкания (табуляция, специальные переменные)
- Платформозависимость
- Ручное управление зависимостями проекта

**Пример сборки:**
```bash
cd MakeExamples/01_headers_added
make
./HelloWorldProject
make clean  # Очистка
```

---

### 3. CMake ([CMakeExamples/](CMakeExamples/))

**Описание:** Кроссплатформенная система генерации build-файлов.

**Плюсы:**
- Кроссплатформенность (Windows, Linux, macOS)
- Автоматический поиск библиотек
- Генерация проектов для различных IDE
- Широкая поддержка в C/C++ сообществе
- Мощная система управления зависимостями

**Минусы:**
- Дополнительный уровень абстракции
- Сложность для начинающих
- Иногда избыточен для простых проектов

**Пример сборки:**
```bash
cd CMakeExamples/02_multiple_projects
mkdir build && cd build
cmake ..
cmake --build .
./FirstClassAsLibrary
```

**Установка:**
```bash
cmake --install . --prefix=/path/to/install
```

---

### 4. Bazel ([BazelExamples/](BazelExamples/))

**Описание:** Современная система сборки от Google, ориентированная на большие проекты.

**Плюсы:**
- Быстрая инкрементальная сборка
- Воспроизводимые сборки
- Кэширование результатов
- Поддержка удаленного выполнения
- Масштабируемость для монорепозиториев

**Минусы:**
- Крутая кривая обучения
- Требует строгой структуры проекта
- Менее распространен, чем CMake

**Пример сборки:**
```bash
cd BazelExamples/00-hello-world
bazel build //main:hello-world
bazel run //main:hello-world
```

**Запуск тестов:**
```bash
cd BazelExamples/02-tests
bazel test //test:sqrt_tests
```

---

### 5. Maven ([MavenExamples/](MavenExamples/))

**Описание:** Стандартная система сборки для Java-проектов.

**Плюсы:**
- Декларативная конфигурация (XML)
- Автоматическое управление зависимостями
- Стандартизированная структура проекта
- Огромная экосистема плагинов
- Центральный репозиторий Maven Central

**Минусы:**
- Многословный XML
- Жесткая структура проекта
- Медленнее Gradle

**Пример сборки:**
```bash
cd MavenExamples/01-add-tests
mvn clean compile      # Компиляция
mvn test               # Запуск тестов
mvn package            # Создание JAR
mvn exec:java          # Запуск приложения
```

---

### 6. Gradle ([GradleExamples/](GradleExamples/))

**Описание:** Гибкая система сборки для JVM-языков с DSL на Groovy/Kotlin.

**Плюсы:**
- Более лаконичный синтаксис, чем Maven
- Инкрементальная сборка
- Высокая производительность
- Программируемая конфигурация
- Совместимость с Maven-репозиториями

**Минусы:**
- Сложность отладки build-скриптов
- Большее потребление памяти
- Множество способов решения одной задачи

**Пример сборки:**
```bash
cd GradleExamples/01-simple-project
./gradlew build        # Сборка
./gradlew run          # Запуск
./gradlew test         # Тесты
./gradlew clean        # Очистка
```

---

### 7. Cargo ([CargoExamples/](CargoExamples/))

**Описание:** Официальный менеджер пакетов и система сборки для Rust.

**Плюсы:**
- Интегрированное управление зависимостями
- Простой и понятный синтаксис (TOML)
- Автоматическая загрузка crates
- Встроенная поддержка тестов и бенчмарков
- Отличная документация

**Минусы:**
- Применим только для Rust
- Ограниченная кастомизация процесса сборки

**Пример сборки:**
```bash
cd CargoExamples/O1-simple-example
cargo build            # Сборка (debug)
cargo build --release  # Сборка (release)
cargo run              # Сборка и запуск
cargo test             # Запуск тестов
```

---

### 8. GNU Autotools ([AutoConfExamples/](AutoConfExamples/))

**Описание:** Классический набор инструментов для конфигурирования и сборки под UNIX.

**Плюсы:**
- Автоматическая адаптация к системе
- Проверка наличия библиотек и инструментов
- Стандарт для многих open-source проектов

**Минусы:**
- Сложная система макросов
- Генерирует много служебных файлов
- Плохая поддержка Windows
- Устаревает в пользу CMake

**Пример использования:**
```bash
cd AutoConfExamples/01_hello_world
autoreconf -i          # Генерация configure
./configure            # Конфигурирование
make                   # Сборка
make install           # Установка
```

---

## Требования

### Общие инструменты
- Git
- Компилятор C++ (GCC 7+, Clang 5+, MSVC 2017+)
- Python 3.6+

### По системам сборки

| Система сборки | Требуемая версия | Установка (Ubuntu/Debian) |
|----------------|------------------|---------------------------|
| GNU Make       | 3.81+            | `sudo apt-get install build-essential` |
| CMake          | 3.10+            | `sudo apt-get install cmake` |
| Bazel          | 4.0+             | См. [bazel.build](https://bazel.build/install) |
| Maven          | 3.6+             | `sudo apt-get install maven` |
| Gradle         | 7.0+             | Используется Gradle Wrapper (./gradlew) |
| Cargo          | 1.50+            | `curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs \| sh` |
| Autotools      | 2.69+            | `sudo apt-get install autoconf automake libtool` |

### Дополнительные зависимости

**Для примеров с OpenCV:**
```bash
sudo apt-get install libopencv-dev
```

**Для примеров с Python биндингами:**
```bash
sudo apt-get install python3-dev
pip3 install pybind11
```

---

## Быстрый старт

### 1. Клонирование репозитория
```bash
git clone <repository-url>
cd BuildExamples-TP
```

### 2. Выбор примера

Начните с простых примеров "Hello World" в каждой системе сборки:

**Bash:**
```bash
cd BashExamples/00_hello_world
./build.sh && ./hello_world
```

**Make:**
```bash
cd MakeExamples/00_hello_world
make && ./HelloWorldProject
```

**CMake:**
```bash
cd CMakeExamples/00_hello_world
mkdir build && cd build
cmake .. && cmake --build .
./HelloWorld
```

**Bazel:**
```bash
cd BazelExamples/00-hello-world
bazel run //main:hello-world
```

**Maven:**
```bash
cd MavenExamples/00-exec-main-classes
mvn compile exec:java
```

**Gradle:**
```bash
cd GradleExamples/01-simple-project
./gradlew run
```

**Cargo:**
```bash
cd CargoExamples/O1-simple-example
cargo run
```

### 3. Изучение сложных примеров

После освоения базовых примеров переходите к:
- Многомодульным проектам ([CMakeExamples/02_multiple_projects/](CMakeExamples/02_multiple_projects/))
- Подключению внешних библиотек ([CMakeExamples/03_include_other_libraries/](CMakeExamples/03_include_other_libraries/))
- Генерации кода ([CMakeExamples/04_generate_code_from_python/](CMakeExamples/04_generate_code_from_python/))
- Тестированию ([BazelExamples/02-tests/](BazelExamples/02-tests/), [MavenExamples/01-add-tests/](MavenExamples/01-add-tests/))
- Интеграции Python и C++ ([CMakeExamples/06-cmake-python/](CMakeExamples/06-cmake-python/))

---

## Рекомендации по выбору системы сборки

| Сценарий | Рекомендация |
|----------|--------------|
| Простой C++ проект (1-3 файла) | Bash или Make |
| Кроссплатформенный C++ проект | **CMake** |
| Крупный C++ монорепозиторий | **Bazel** |
| Java корпоративное приложение | **Maven** |
| Android или современный Java/Kotlin | **Gradle** |
| Rust проект | **Cargo** (единственный выбор) |
| Legacy UNIX проект | Autotools |

---

## Дополнительные ресурсы

### CMake
- [Официальная документация](https://cmake.org/documentation/)
- [Modern CMake Tutorial](https://cliutils.gitlab.io/modern-cmake/)

### Bazel
- [Bazel Documentation](https://bazel.build/)
- [Bazel C++ Tutorial](https://bazel.build/tutorials/cpp)

### Maven
- [Maven Getting Started](https://maven.apache.org/guides/getting-started/)
- [Maven Central Repository](https://search.maven.org/)

### Gradle
- [Gradle User Manual](https://docs.gradle.org/current/userguide/userguide.html)
- [Gradle Build Language Reference](https://docs.gradle.org/current/dsl/)

### Cargo
- [The Cargo Book](https://doc.rust-lang.org/cargo/)
- [crates.io](https://crates.io/) - реестр пакетов Rust

---

## Структура учебного процесса

Рекомендуемая последовательность изучения:

1. **Основы компиляции** → [BashExamples/](BashExamples/)
2. **Автоматизация с зависимостями** → [MakeExamples/](MakeExamples/)
3. **Кроссплатформенная сборка** → [CMakeExamples/](CMakeExamples/)
4. **Современные подходы (C++)** → [BazelExamples/](BazelExamples/)
5. **Экосистема JVM** → [MavenExamples/](MavenExamples/) → [GradleExamples/](GradleExamples/)
6. **Rust экосистема** → [CargoExamples/](CargoExamples/)
7. **Legacy системы** → [AutoConfExamples/](AutoConfExamples/)

---

## Лицензия

Данный проект предназначен для образовательных целей.

---

## Контакты

При возникновении вопросов или предложений создавайте Issue в репозитории проекта.
