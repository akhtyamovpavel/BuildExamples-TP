package org.example;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class TestMyClassSetUp {

    private MyClassSetUp myClass;

    @BeforeEach
    public void initMyClass() {
        System.out.println("Set Up called");
        this.myClass = new MyClassSetUp();
    }

    @Test
    public void testAString() {
        assertEquals("A", myClass.aString);
    }

    @Test
    public void testBString() {
        assertEquals("B", myClass.bString);
    }

    @AfterEach
    public void tearDown() {
        System.out.println("Tear Down called");
    }
}
