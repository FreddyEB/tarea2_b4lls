/*
 * Classe Maze
 */

#pragma once
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
typedef unsigned char uchar;

class Maze{
private:
	uchar**  grid;
	int width;
	int height;
	int dir[4];
	void shuffle_dir();
	void delete_maze();
	void visit(int i, int j, std::vector<std::pair<int, int>>& path);
public:
	static const unsigned char WALL;
	static const unsigned char EMPTY;
	static const unsigned char SOLUTION;
	static const int NORTH;
	static const int SOUTH;
	static const int EAST;
	static const int WEST;
	Maze(int h, int  w);
	void generate_maze(int h, int w);
	void reset_maze(int h, int w);
	bool inRange(int i, int j);
	void solve_pila(int f1, int c1, int f2, int c2);
	void solve_cola(int f1, int c1, int f2, int c2);
	void dfsPath(std::pair<int,int>, std::pair<int,int>);
	void print();
};
