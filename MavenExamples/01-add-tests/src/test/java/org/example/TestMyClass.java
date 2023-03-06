package org.example;

import org.junit.jupiter.api.Test;

import java.security.InvalidParameterException;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

public class TestMyClass {

    @Test
    public void testMyClassA() {
        MyClass myClass = new MyClass(5);

        assertEquals(5, myClass.GetA());
    }

    @Test
    public void testGetPositiveCorrect() {
        MyClass myClass = new MyClass(5);

        assertEquals(5, myClass.GetPositiveA());
    }

    @Test
    public void testGetPositiveException() {
        MyClass myClass = new MyClass(-5);

        assertThrows(InvalidParameterException.class, myClass::GetPositiveA);
    }
}
