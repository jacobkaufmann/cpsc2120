// Jacob Kaufmann
// Wart.h

#ifndef WART_H
#define WART_H

#include <iostream>
#include "Digraph.h"
using namespace std;

class Wart
{
    public:
        Wart(string m);
        void encode(int width);
        void decode(Digraph & D);

        friend ostream &operator<<(ostream &out, const Wart &myWart);
    private:
        string message;
};

#endif
