#!/bin/bash

CFLAGS="-std=c++11 -Wall -Werror"
PROJECT_NAME=HelloWorldProject

g++ ${CFLAGS} main.cpp -o ${PROJECT_NAME}
