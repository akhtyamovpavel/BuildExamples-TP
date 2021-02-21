package org.example;

import org.example_other.SecondClass;  // Importing other class from first_class



public class Main {
    public static void main(String[] args) {
        FirstClass firstClass = new FirstClass();
        firstClass.set("Hello");

        System.out.println(firstClass.get());

        System.out.println(SecondClass.get());
    }
}
