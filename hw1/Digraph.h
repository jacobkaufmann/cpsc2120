// Jacob Kaufmann
// Digraph.h

#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <iostream>
#include <fstream>
using namespace std;

class Digraph
{
    public:
        Digraph();
        Digraph(string fileName);
        double getScore(char a, char b);
        double getScore(string & s);
    private:
        double digraphScores[26][26];
        int digraphCount;
};

#endif
