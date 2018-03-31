// Jacob Kaufmann
// Recursion.h

#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
#include <fstream>
using namespace std;

class Recursion
{
    public:
        Recursion(string inputFile);
        void print();
        void printGroupWith(int i, int j);
    private:
        int grid[10][10];
        bool marked[10][10];
};

#endif
