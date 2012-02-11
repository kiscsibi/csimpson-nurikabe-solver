#include <iostream>
#include "CORE/Grid.h"
#include "CS/CSGrid.h"
using namespace std;

int main() {
    
    //Grid g(5,5,10);
    CSGrid g("DATA/grid_01.txt");
    
    g.print();
    g.setCell(0,0,Grid::BLACK);
    g.setCell(3,4,Grid::WHITE);
    cout << endl;
    g.print();
    cout << g.getCell(0,0) << endl;
    system("pause");
    return 0;
}
