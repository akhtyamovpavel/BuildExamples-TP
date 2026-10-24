plugins {
    java
    application
}

group = "ru.akhcheck.promprog"
version = "1.0.0"

repositories {
    mavenLocal()
    mavenCentral()
}

dependencies {
    implementation(libs.commons.math3)
    testImplementation(libs.junit.jupiter.api)
    testRuntimeOnly(libs.junit.jupiter.engine)
    testRuntimeOnly(libs.junit.platform.launcher)
}

application {
    mainClass.set("ru.akhcheck.promprog.StatsApp")
}

tasks.test {
    useJUnitPlatform()
}

tasks.jar {
    archiveBaseName.set("stats-kotlin-dsl")
    archiveVersion.set("1.0.0")
    manifest {
        attributes("Main-Class" to "ru.akhcheck.promprog.StatsApp")
    }
}
