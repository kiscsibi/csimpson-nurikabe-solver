#ifndef CSGRID_H
#define CSGRID_H

#include "CORE/Grid.h"

class CSGrid : public Grid {

    public:
        
        static const int NUM_ALGORITHMS = 1; // total number of algorithms
        
        // inheritance
        //CSGrid() : Grid() {}; // inherited by default
        CSGrid(string fname) : Grid(fname) {};
        CSGrid(int _rows, int _cols) : Grid(_rows,_cols) {};
        CSGrid(int _rows, int _cols, int fill_value) : Grid(_rows,_cols,fill_value) {};
        
        // substance
        void doAllAlgorithms(); // do each algorithm once. not very useful for any cumulative algorithms
        void doAlgorithm(int num); // zero-based
};

#endif
