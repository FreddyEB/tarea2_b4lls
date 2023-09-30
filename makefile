CC = g++
FLAGS = -std=c++11 

exe = tarea2

$(exe): main.o maze.o
	$(CC) main.o maze.o -o $(exe)

main.o: main.cpp maze.hpp
	$(CC) $(FLAGS) -c -o main.o main.cpp 

maze.o: maze.cpp maze.hpp
	$(CC) $(FLAGS) -c -o maze.o maze.cpp

clean:
	rm *.o
	rm -f $(exe)
