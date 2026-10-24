package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class HelloWorldTest {
    @Test
    void greetingMatchesExpected() {
        assertEquals("Hello World", HelloWorld.greeting());
    }
}
