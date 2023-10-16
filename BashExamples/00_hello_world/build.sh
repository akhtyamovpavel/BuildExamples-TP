#!/bin/bash

CFLAGS="-std=c++11 -Wall -Werror"
PROJECT_NAME=HelloWorldProject
CXX=${CXX:-g++}

${CXX} ${CFLAGS} main.cpp -o ${PROJECT_NAME}
