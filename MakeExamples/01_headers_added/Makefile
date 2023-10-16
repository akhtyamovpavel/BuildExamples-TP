CFLAGS=-std=c++11 -Wall

.PHONY: all create_dir
all: create_dir HelloWorldProject


HelloWorldProject: build/main.o build/FirstClass.o
		g++ ${CFLAGS} $? -o $@

build/main.o: src/main.cpp
		g++ ${CFLAGS} -c $? -o $@

build/FirstClass.o: src/FirstClass.cpp
		g++ ${CFLAGS} -c $? -o $@

create_dir:
	mkdir -p build

clean:
		rm -rf build HelloWorldProject
