package org.example;

import java.security.InvalidParameterException;

public class MyClass {
    private int a;

    public MyClass(int a) {
        this.a = a;
    }

    public int GetA() {
        return a;
    }

    public int GetPositiveA() throws InvalidParameterException {
        if (a > 0) {
            return a;
        }
        throw new InvalidParameterException("A value less zero");
    }
}
