#!/bin/bash

CFLAGS="-std=c++11 -Wall"

SOURCE_DIR=src
BUILD_DIR=build
CXX=${CXX:-g++}

mkdir -p ${BUILD_DIR}
${CXX} ${CFLAGS} -o ${BUILD_DIR}/FirstClass.o -c ${SOURCE_DIR}/FirstClass.cpp
${CXX} ${CFLAGS} -o ${BUILD_DIR}/main.o -c ${SOURCE_DIR}/main.cpp
${CXX} ${CFLAGS} -o FirstClassProject ${BUILD_DIR}/main.o ${BUILD_DIR}/FirstClass.o


