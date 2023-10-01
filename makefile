CC = g++
FLAGS = -std=c++11 

exe = tarea2

$(exe): main.o maze.o node.o stack.o queue.o
	$(CC) main.o maze.o node.o stack.o queue.o -o $(exe)

main.o: main.cpp maze.hpp
	$(CC) $(FLAGS) -c -o main.o main.cpp 

maze.o: maze.cpp maze.hpp
	$(CC) $(FLAGS) -c -o maze.o maze.cpp

node.o: node.cpp node.hpp
	$(CC) $(FLAGS) -c -o node.o node.cpp
	
stack.o: stack.cpp stack.hpp node.hpp
	$(CC) $(FLAGS) -c -o stack.o stack.cpp

queue.o: queue.cpp queue.hpp node.hpp
	$(CC) $(FLAGS) -c -o queue.o queue.cpp

clean:
	rm *.o
	rm -f $(exe)
