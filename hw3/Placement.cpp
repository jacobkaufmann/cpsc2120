// Jacob Kaufmann
// Placement.cpp

#include "Placement.h"

Placement::Placement(int rStart, int cStart, bool horizontal, int tileLength) : r(rStart),
	c(cStart), isHorizontal(horizontal), tileLen(tileLength)
{
    if(tileLength == 1) isHorizontal = true;
}

ostream & operator<<(ostream & out, const Placement & other)
{
    out << "uplft= (" << other.r << "," << other.c << ") ";
    if(other.isHorizontal)
	out << "horz";
    else
	out << "vert";
    out << " len= " << other.tileLen;
    return out;
}
