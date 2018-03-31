// Jacob Kaufmann
// Configuration.h

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "Square.h"
#include "Placement.h"
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

class Configuration {

public:
    Configuration(int rr, int cc);
    Configuration(string fileName);
    bool placeTileAt(int rStart, int cStart, bool isHorizontal, int tileLength);
    void forbid(int r, int c);
    void dumpToScreen() const;
    list<Placement> getPossiblePlacements(int tileLength);
    virtual ~Configuration();

protected:
    int rows, cols;
    char open, forbidden;
    Square **board;
    int countOfTiles;
    list<Placement> tilesOnBoard;
    bool fitsHorizontally(int rStart, int cStart, int tileLength);
    bool fitsVertically(int rStart, int cstart, int tileLength);
};

#endif
