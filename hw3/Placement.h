// Jacob Kaufmann
// Placement.h

#ifndef PLACEMENT_H
#define PLACEMENT_H

#include <iostream>
using namespace std;

class Placement {

    public:
	Placement(int rStart, int cStart, bool horizontal, int tileLength);

	friend ostream & operator<<(ostream & out, const Placement & other);

    private:
	int r, c;
	bool isHorizontal;
	int tileLen;
};

#endif
