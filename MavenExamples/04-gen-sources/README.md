## Code generation

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

