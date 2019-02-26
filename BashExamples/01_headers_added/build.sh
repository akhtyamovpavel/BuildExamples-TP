#!/bin/bash

CFLAGS="-std=c++11 -Wall"

SOURCE_DIR=src
BUILD_DIR=build

mkdir -p ${BUILD_DIR}
g++ ${CFLAGS} -o ${BUILD_DIR}/FirstClass.o -c ${SOURCE_DIR}/FirstClass.cpp
g++ ${CFLAGS} -o ${BUILD_DIR}/main.o -c ${SOURCE_DIR}/main.cpp
g++ ${CFLAGS} -o FirstClassProject ${BUILD_DIR}/main.o ${BUILD_DIR}/FirstClass.o


