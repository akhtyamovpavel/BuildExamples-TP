#!/bin/bash

g++ -o FirstClass.o -c FirstClass.cpp

g++ -o main.o -c main.cpp

g++ -o FirstClassProject main.o FirstClass.o
