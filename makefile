CC = g++
CXXFLAGS = -std=c++11 

exe = p

$(exe): main.o maze.o
	$(CC) main.o maze.o -o $(exe)

main.o: main.cpp maze.hpp
	$(CC) $(CXXFLAGS) -c -o main.o main.cpp 

maze.o: maze.cpp maze.hpp
	$(CC) $(CXXFLAGS) -c -o maze.o maze.cpp

run: $(exe)
	./$(exe)

clean:
	rm *.o
	rm -f $(exe)
