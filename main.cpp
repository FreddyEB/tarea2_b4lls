#include "maze.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    Maze laber(21, 21);
    laber.print();
    laber.solve_pila(0,0,20,20);
    //laber.solve_cola(0,0,20,20);
    return 0;
}
