/*
Grid.h - Nurikabe Grid container

This class stores information about the Nurikabe puzzle and provides
constants for cell types.
*/

#ifndef GRID_H
#define GRID_H

#include <string>
using namespace std;

class Grid {
    private:
        int NUM_ROWS, NUM_COLS;
        int **board;
        
        bool isValid(int r, int c); // determine whether values reside in grid
        void allocate(int _rows, int _cols); // allocate(_rows,_cols,Grid::UNKNOWN);
        void allocate(int _rows, int _cols, int fill_value); // allocate memory for board and fill
        void deallocate();
        void init();
        
    public:
        
        static const int UNKNOWN = -1,
                        WHITE = -2,
                        BLACK = -3,
                        ERROR = -4;
        
        static bool isPreset(int value); // return whether the number is a valid preset (aka cluster number/preset) instead of flag
        
        char UNKNOWN_CHAR, WHITE_CHAR, BLACK_CHAR, ERROR_CHAR;
        
        // --------------------------------------------
        
        Grid();
        Grid(int _rows, int _cols);
        Grid(int _rows, int _cols, int fill_value);
        Grid(string fname); // read data from file
        ~Grid();
        
        int getNumRows();
        int getNumCols();
        
        void printRaw(); // print raw board (ints)
        void print(); // print with ASCII formatting
        int getCell(int r, int c); // retrieve value of cell (r,c)
        bool setCell(int r, int c, int value); // set cell (r,c) to 'value', returns success        
};

#endif
