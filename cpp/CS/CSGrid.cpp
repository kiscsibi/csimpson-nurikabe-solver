#ifndef CSGRID_CPP
#define CSGRID_CPP

#include "CS/CSGrid.h"

void CSGrid::doAllAlgorithms() {
    for (int i=0; i<CSGrid::NUM_ALGORITHMS; i++)
        doAlgorithm(i);
}

void CSGrid::doAlgorithm(int num) {

}

#endif
