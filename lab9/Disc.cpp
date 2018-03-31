// Jacob Kaufmann
// Disc.cpp

#include "Disc.h"

Disc::Disc() : width(0)
{
}

Disc::Disc(int w) : width(w)
{
}

int Disc::getWidth()
{
    return width;
}

bool Disc::operator<(const Disc &other)
{
    return width < other.width;
}

bool Disc::operator>(const Disc &other)
{
    return width > other.width;
}

ostream &operator<<(ostream &out, const Disc &other)
{
    out << other.width;
    return out;
}
