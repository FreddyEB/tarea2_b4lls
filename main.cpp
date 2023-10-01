#include "maze.hpp"
#include <iostream>
#include <string.h>

using namespace std;


int main(int argc, char **argv)
{
    if (argc != 8) {
        std::cout << "numero de argumentos no válido" << std::endl;
        exit(1);
    }

    int alto = atoi(argv[1]);
    int ancho = atoi(argv[2]);
    int x1 = atoi(argv[3]);
    int y1 = atoi(argv[4]);
    int x2 = atoi(argv[5]);
    int y2 = atoi(argv[6]);
    
    Maze laber(alto, ancho); 
    laber.print();

    if (*argv[7] == 'p') {
        laber.solve_pila(x1, y1, x2, y2);

    } else if (*argv[7] == 'c') {
        laber.solve_cola(x1, y1, x2, y2);
    }

    return 0;
}
