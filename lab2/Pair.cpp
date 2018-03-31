// Jacob Kaufmann
// Pair.cpp
#include "Pair.h"

Pair::Pair() : x(0), y(0)
{
}

Pair::Pair(int xx, int yy) : x(xx), y(yy)
{
}

void Pair::setX(int xx)
{
    x = xx;
}

void Pair::setY(int yy)
{
    y = yy;
}

int Pair::getX() const
{
    return x;
}

int Pair::getY() const
{
    return y;
}
