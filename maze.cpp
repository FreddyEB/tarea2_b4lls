#include "maze.hpp"
#include <queue>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const unsigned char Maze::WALL  = '@';
const unsigned char Maze::EMPTY = '-';
const int Maze::NORTH= 0;
const int Maze::SOUTH= 1;
const int Maze::EAST= 2;
const int Maze::WEST= 3;
Maze::Maze(int h, int w):
		height(h),
		width(w),
		grid(nullptr){
	dir[0] = NORTH;
	dir[1] = SOUTH;
	dir[2] = EAST;
	dir[3] = WEST;
	srand(time(0));
	generate_maze(h, w);

}

void Maze::reset_maze(int h, int w){
	delete_maze();
	height = h;
	width= w;
	grid = new uchar*[height];
	for (int i = 0; i < height; i++){
		grid[i] = new uchar[width];
		for (int j = 0; j < width; j++){
			grid[i][j] = 1;
		}
	}
}

void Maze::generate_maze(int h, int w){
	reset_maze(h, w);
	vector<pair<int, int>> path;
    visit(0, 0, path);
}

void Maze::delete_maze(){
	if (grid != nullptr){
		for (int i = 0; i < height; i++){
			delete[] grid[i];
		}
		delete[] grid;
	}
}

void Maze::shuffle_dir(){
	for (int i = 0; i < 4; i++){
		int r = rand() & 3;
		int aux = dir[r];
		dir[r] = dir[i];
		dir[i] = aux;
	 }
}
bool Maze::inRange(int i, int j){
	return ((i >= 0) && (i< height) && (j >= 0) && (j< width));
}

void Maze::visit(int i, int j, vector<pair<int, int>>& path){

	int dx  = 0;
	int dy = 0;
	int i_next = 0;
	int j_next = 0;
	grid[i][j] = 0;
	shuffle_dir();
	//cout << dir[0] << " " << dir[1] << " " << dir[2] << " "<< dir[3] << endl;
	for(int k = 0; k <  4; k++){
		//cout << dir[k] << endl;
		if (dir[k] == NORTH){
			dy = -1;
			dx = 0;
		}
		else if (dir[k] == SOUTH){
			dy = 1;
			dx = 0;
		}
		else if (dir[k] == EAST){
			dy = 0;
			dx = 1;
		}
		else if (dir[k] == WEST){
			dy = 0;
			dx = -1;
		}
		i_next = i + (dy<<1);
		j_next = j + (dx<<1);
		if (inRange(i_next, j_next) && grid[i_next][j_next] == 1){
			grid[i_next - dy][j_next - dx] = 0;
			path.push_back({i_next, j_next});
			visit(i_next, j_next, path);

		}
	}
}

void Maze::print(){
	char LIMIT = '=';
	cout << " Maze ( "<< height << " x " << width << " ) " << endl;
	cout << " ";
	for (int j = 0; j < width; j++){
		cout << LIMIT;
	}
	cout << " ";
	cout << endl;
	for (int i = 0; i < height; i++){
		cout << "|";
		for (int j = 0; j < width; j++){
			if (grid[i][j] == 0) {
				cout << EMPTY;
			}
			else {
				cout << WALL;
			}
		}
		cout << "|";
		cout << endl;
	}
	cout << " ";
	for (int j = 0; j < width; j++){
		cout << LIMIT;
	}
	cout << " ";
	cout << endl;
}

void Maze::solve_pila(int f1, int c1, int f2, int c2) {
    vector<pair<int, int>> path;
    path.push_back({f1, c1});

    visit(f1, c1, path);
    for (const auto& point : path) {
        cout << "(" << point.first << ", " << point.second << ") " << endl;
    }
    cout << endl;
}

void Maze::solve_cola(int f1, int c1, int f2, int c2) {
    queue<pair<int, int>> cola;
    cola.push({f1, c1});

    while (!cola.empty()) {
        int i = cola.front().first;
        int j = cola.front().second;

        if (i == f2 && j == c2) {
            cout << "Salida del laberinto: (" << i << ", " << j << ")" << endl;
            break;
        }

        cola.pop();

        shuffle_dir();

        for (int k = 0; k < 4; k++) {
            int dy = 0, dx = 0;

            if (dir[k] == NORTH) {
                dy = -1;
            } else if (dir[k] == SOUTH) {
                dy = 1;
            } else if (dir[k] == EAST) {
                dx = 1;
            } else if (dir[k] == WEST) {
                dx = -1;
            }

            int i_next = i + dy;
            int j_next = j + dx;

            if (inRange(i_next, j_next) && grid[i_next][j_next] == 0) {
                // Verifica si la celda no es un muro antes de agregarla a la cola
                cola.push({i_next, j_next});
                // Marca la celda como visitada
                grid[i_next][j_next] = 1;
            }else{
				cout << "no tiene solución de colas o bfs" << endl; 
			}
		}
    }
}
