CFLAGS=-std=c++11 -Wall

all: HelloWorldProject

HelloWorldProject: build/main.o build/FirstClass.o create_dir
		g++ ${CFLAGS} build/main.o build/FirstClass.o -o HelloWorldProject

build/main.o: src/main.cpp create_dir
		g++ ${CFLAGS} -c src/main.cpp -o build/main.o

build/FirstClass.o: src/FirstClass.cpp create_dir
		g++ ${CFLAGS} -c src/FirstClass.cpp -o build/FirstClass.o

create_dir:
		mkdir -p build

clean:
		rm -rf build HelloWorldProject
