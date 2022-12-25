#include <iostream>

#include "creature.h"
#include "maze.h"


void test() {

    Maze M("maze.txt");
    Creature C(4, 4);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;

    Maze M1("maze1.txt");
    Creature C1(1, 18);
    cout << "Path: " << C1.solve(M1) << endl;
    cout << M1 << endl;

    Maze M2("maze2.txt");
    Creature C2(5, 20);
    cout << "Path: " << C2.solve(M2) << endl;
    cout << M2 << endl;

    Maze M3("maze3.txt");
    Creature C3(1, 1);
    cout << "Path: " << C3.solve(M3) << endl;
    cout << M3 << endl;

    Maze M4("maze4.txt");
    Creature C4(1, 1);
    cout << "Path: " << C4.solve(M4) << endl;
    cout << M4 << endl;

    Maze M5("maze5.txt");
    Creature C5(1, 1);
    cout << "Path: " << C5.solve(M5) << endl;
    cout << M5 << endl;
}
int main() {
    test();
    cout << "Done!" << std::endl;
    return 0;
}