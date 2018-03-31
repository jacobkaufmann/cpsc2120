// Jacob Kaufmann
// ISet.h

#ifndef ISET_H
#define ISET_H

#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

class ISet
{
    public:
        ISet();
        void output();
        void evolve(int evolutions, double p);
    private:
        int rows, cols;
        bool grid[40][40];
};

#endif
