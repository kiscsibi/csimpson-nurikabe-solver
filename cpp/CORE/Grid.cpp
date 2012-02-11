#ifndef GRID_CPP
#define GRID_CPP

#include <iostream>
#include <string>
#include <fstream>

#include "CORE/Grid.h"
#include "CORE/CoreDef.h"
using namespace std;

Grid::Grid() : NUM_ROWS(0), NUM_COLS(0) { // must be zero, otherwise deallocation fails
}
Grid::Grid(int _rows, int _cols) {
    allocate(_rows, _cols);
}
Grid::Grid(int _rows, int _cols, int fill_value) {
    allocate(_rows, _cols, fill_value);
}
Grid::Grid(string fname) {
    ifstream infile(fname.c_str());
    if (!infile.good()) {
        allocate(5,5,Grid::ERROR);
    } else {
        
        /* 
            Format:
            NUM_ROWS NUM_COLS
            # # # ... (NUM_COLS times)
            ... (NUM_ROWS times)
            
            Example:
            3 3
            1 0 0
            0 0 3
            1 0 0
            
        */
        
        infile >> NUM_ROWS;
        infile >> NUM_COLS;
        allocate(NUM_ROWS, NUM_COLS);
        
        int i=0; // linear counter for RMO
        while (!infile.eof() && i < NUM_ROWS*NUM_COLS) {
            int t;
            infile >> t;
            if (t == 0) t = Grid::UNKNOWN;
            board[i/NUM_COLS][i%NUM_COLS] = t;
            i++;
        }
        infile.close();
    }
}

int Grid::getNumRows() {
    return NUM_ROWS;
}
int Grid::getNumCols() {
    return NUM_COLS;
}

int Grid::getCell(int r, int c) {
    if (!isValid(r,c)) return Grid::ERROR;
    return board[r][c];
}

bool Grid::isValid(int r, int c) {
    return r>=0 && c>=0 && r<NUM_ROWS && c<NUM_COLS;
}

// static
bool Grid::isPreset(int value) {
    return value >= 1;
}

bool Grid::setCell(int r, int c, int value) {
    if (!isValid(r,c)) return false;
    board[r][c] = value;
    return true;
}

void Grid::printRaw() {
    for (int r=0; r<NUM_ROWS; r++) {
        for (int c=0; c<NUM_COLS-1; c++)
            cout << board[r][c] << " ";
        cout << board[r][NUM_COLS-1] << endl;
    }
}
void Grid::print() {
    for (int r=0; r<NUM_ROWS; r++) {
        for (int c=0; c<NUM_COLS; c++) {
            switch (board[r][c]) {
                case Grid::BLACK:
                    cout << BLACK_CHAR; break;
                case Grid::WHITE:
                    cout << WHITE_CHAR; break;
                case Grid::UNKNOWN:
                    cout << UNKNOWN_CHAR; break;
                case Grid::ERROR:
                    cout << ERROR_CHAR; break;
                default:
                    cout << board[r][c]; // issues with 2-digit+ numbers
            }
            cout << ""; // trailing space, though not a big deal
        }
        cout << endl;
    }
}

// Precondition: 'board' must be deallocated
void Grid::allocate(int _rows, int _cols) {
    allocate(_rows, _cols, Grid::UNKNOWN);
}
void Grid::allocate(int _rows, int _cols, int fill_value) {
    
    NUM_ROWS = _rows;
    NUM_COLS = _cols;
    
    board = new int*[NUM_ROWS];
    for (int r=0; r<NUM_ROWS; r++) {
        board[r] = new int[NUM_COLS];
        for (int c=0; c<NUM_COLS; c++)
            board[r][c] = fill_value;
    }
}
void Grid::deallocate() {
    for (int r=0; r<NUM_ROWS; r++)
        delete[] board[r];
    delete[] board;
}
Grid::~Grid() {
    deallocate();
}
#endif
