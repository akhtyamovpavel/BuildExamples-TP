## Code generation

Данный проект демонстрирует процесс генерации ресурсов во время сборки. Поддерживаются два системы сборки: Maven и Gradle.

# Maven Build Process Diagram

```mermaid
graph TB
    Start([mvn package])
    
    Start --> Validate[Validate]
    Validate --> Compile[Compile Sources]
    Compile --> Test[Run Tests]
    Test --> GenerateRes[Generate Resources]
    
    GenerateRes --> DOT[Execute dot command]
    DOT --> |input.dot -> graph.png| DOTOutput[graph.png created]
    DOTOutput --> CopyRes[Copy Resources]
    CopyRes --> |graph.png| CopyToTarget[graph.png -> target/generated-resources/output]
    CopyToTarget --> AddRes[Add Resource to Classpath]
    AddRes --> Package[Package Phase]
    
    Package --> Assembly[Create JAR with Dependencies]
    Assembly --> Manifest[Add Manifest with MainClass]
    Manifest --> Final[(Final JAR Ready)]
    
    subgraph "Generate Resources Phase"
        DOT
        DOTOutput
        CopyRes
        CopyToTarget
        AddRes
    end
    
    subgraph "Package Phase"
        Assembly
        Manifest
    end
    
    style Start fill:#e1f5ff
    style GenerateRes fill:#fff3e0
    style Package fill:#f3e5f5
    style Final fill:#e8f5e9
```

## Описание процесса сборки

1. **Generate Resources Phase** (фаза генерации ресурсов):
   - `exec-maven-plugin` запускает команду `dot` для конвертации `input.dot` в `graph.png`
   - `maven-resources-plugin` копирует сгенерированный `graph.png` в `target/generated-resources/output`
   - `build-helper-maven-plugin` добавляет этот ресурс в classpath приложения

2. **Package Phase** (фаза упаковки):
   - `maven-assembly-plugin` создает JAR-файл со всеми зависимостями
   - Добавляется манифест с указанием главного класса `ru.akhcheck.Main`

3. **Результат**: 
   - Приложение `Main.java` загружает `graph.png` из ресурсов и отображает его в Swing-окне

# Gradle Build Process

Gradle эквивалент использует те же этапы сборки, но с использованием Gradle плагинов:

## Сборка проекта (Gradle)

```bash
./gradlew build
```

или

```bash
./gradlew shadowJar
```

## Описание процесса сборки (Gradle)

1. **Генерация ресурсов**:
   - Задача `generateGraph` запускает команду `dot -Tpng input.dot -o graph.png`
   - Задача `copyGraphToResources` копирует `graph.png` в `build/generated/resources`
   - Процесс ресурсов (`processResources`) включает сгенерированный файл в classpath

2. **Упаковка**:
   - Плагин `shadow` создает uber JAR со всеми зависимостями
   - Манифест содержит указание главного класса `ru.akhcheck.Main`

3. **Результат**:
   - Приложение `Main.java` загружает `graph.png` из ресурсов и отображает его в Swing-окне

## Структура задач Gradle

- `generateGraph` - генерирует graph.png из input.dot
- `copyGraphToResources` - копирует graph.png в директорию ресурсов
- `processResources` - обрабатывает ресурсы (зависит от copyGraphToResources)
- `shadowJar` - создает uber JAR с зависимостями и main-классом

## Требования

Для генерации графа необходимо установить Graphviz:
```bash
sudo apt-get install graphviz  # Debian/Ubuntu
brew install graphviz         # macOS
choco install graphviz        # Windows (Chocolatey)
```
