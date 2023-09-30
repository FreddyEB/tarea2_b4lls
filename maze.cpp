#include "maze.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

const unsigned char Maze::WALL  = '@';
const unsigned char Maze::EMPTY = '-';
const unsigned char Maze::SOLUTION = '!';
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
			else if (grid[i][j] == 1){
				cout << WALL;
			} else {
				cout << SOLUTION;
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
	if (!inRange(f1, c1) || (grid[f1][c1] == 1) || !inRange(f2, c2) || (grid[f2][c2])) {
		cout << "Coordenadas inválidas" << endl;
		exit(1);
	}

	vector <vector<bool>> visited(height, vector<bool>(width, false));
	std::stack <pair<int, int>> pila;

	pila.push({f1, c1});
	vector<pair<int,int>>camino;

	while (!pila.empty())
	{
		pair<int, int> current = pila.top();
		pila.pop();
		/*
		int f = current.first;
		int c = current.second;
		*/

		if (current.first == f2 && current.second == c2) {
			camino.push_back(current);
			break;
		}

		visited[current.first][current.second] = true;

		int movimientos[4][2] = {{-1, 0}, {1, 0}, {0,-1}, {0, 1}};

		for (int i = 0; i < 4; i++)
		{
			int nuevaF = current.first + movimientos[i][0];
			int nuevaC = current.second + movimientos[i][1];

			if (nuevaF >= 0 && nuevaF < height && nuevaC >= 0 && nuevaC < width && grid[nuevaF][nuevaC] == 0 && !visited[nuevaF][nuevaC]) {
                pila.push(make_pair(nuevaF, nuevaC));
                camino.push_back(make_pair(nuevaF, nuevaC));
            }	
		}
	}

	for (int j = 0; j < camino.size(); j++)
	{
		grid[camino[j].first][camino[j].second] = 3;
	}

	print();
}

void Maze::solve_cola(int f1, int c1, int f2, int c2) {
	if (!inRange(f1, c1) || (grid[f1][c1] == 1) || !inRange(f2, c2) || (grid[f2][c2])) {
		cout << "Coordenadas inválidas" << endl;
		exit(1);
	}

	vector <vector<bool>> visited(height, vector<bool>(width, false));
	std::queue <pair<int, int>> pila;

	pila.push({f1, c1});
	vector<pair<int,int>>camino;

	while (!pila.empty())
	{
		pair<int, int> current = pila.front();
		pila.pop();
		/*
		int f = current.first;
		int c = current.second;
		*/

		if (current.first == f2 && current.second == c2) {
			camino.push_back(current);
			break;
		}

		visited[current.first][current.second] = true;

		int movimientos[4][2] = {{-1, 0}, {1, 0}, {0,-1}, {0, 1}};

		for (int i = 0; i < 4; i++)
		{
			int nuevaF = current.first + movimientos[i][0];
			int nuevaC = current.second + movimientos[i][1];

			if (nuevaF >= 0 && nuevaF < height && nuevaC >= 0 && nuevaC < width && grid[nuevaF][nuevaC] == 0 && !visited[nuevaF][nuevaC]) {
                pila.push(make_pair(nuevaF, nuevaC));
                camino.push_back(make_pair(nuevaF, nuevaC));
            }	
		}
	}

	for (int j = 0; j < camino.size(); j++)
	{
		grid[camino[j].first][camino[j].second] = 3;
	}

	print();
}