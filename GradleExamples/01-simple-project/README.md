# 01-simple-project: базовый проект Gradle и разбор исправлений под Gradle 9

В каталоге сохранены оригинальный файл `build.gradle.orig` (под Gradle 6.7) и исправленный `build.gradle` (под Gradle 8/9):

1. `repositories { jcenter() }` заменен на `mavenLocal()` и `mavenCentral()`, так как JFrog закрыл JCenter, а метод `jcenter()` удален из Gradle 8/9.
2. `mainClass = 'HelloWorld'` заменен на полное имя с пакетом `mainClass = 'org.example.HelloWorld'`, иначе запуск падает с `ClassNotFoundException`.
3. Устаревшее свойство `archivesBaseName` заменено на `archiveBaseName = '01-simple-project'`.
