all: HelloWorldProject

HelloWorldProject: main.o FirstClass.o
		g++ main.o FirstClass.o -o HelloWorldProject

main.o:
		g++ -c src/main.cpp -o main.o

FirstClass.o:
		g++ -c src/FirstClass.cpp -o FirstClass.o

clean:
		rm -rf *.o HelloWorldProject
