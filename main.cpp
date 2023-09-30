#include "maze.hpp"

int main(int argc, char **argv)
{
    Maze laber(21, 21);
    laber.print();
    //laber.solve_pila(1,1,20,20);
    laber.solve_cola(1,1,5,5);
    return 0;
}
