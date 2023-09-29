CC = g++
CXXFLAGS = -std=c++11 

exe = p

$(exe): main.o maze.o node.o stack.o queue.o
	$(CC) main.o maze.o node.o stack.o queue.o -o $(exe)

main.o: main.cpp maze.hpp
	$(CC) $(CXXFLAGS) -c -o main.o main.cpp 

maze.o: maze.cpp maze.hpp stack.hpp queue.hpp node.hpp
	$(CC) $(CXXFLAGS) -c -o maze.o maze.cpp

node.o: node.cpp node.hpp
	$(CC) $(CXXFLAGS) -c -o node.o node.cpp

stack.o: stack.cpp stack.hpp node.hpp
	$(CC) $(CXXFLAGS) -c -o stack.o stack.cpp 

queue.o: queue.cpp queue.hpp node.hpp
	$(CC) $(CXXFLAGS) -c -o queue.o queue.cpp

run: $(exe)
	./$(exe)

clean:
	rm *.o
	rm -f $(exe)
