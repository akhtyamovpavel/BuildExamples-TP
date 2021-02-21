package org.example;


import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class Main {
    public static void main(String[] args) {
        Logger logger = LogManager.getLogger("Main");
        logger.error("Hello World");
    }
}
