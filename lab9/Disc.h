// Jacob Kaufmann
// Disc.h

#ifndef DISC_H
#define DISC_H

#include <iostream>
using namespace std;

class Disc {

    public:
	Disc();
	Disc(int w);
	int getWidth();
	bool operator<(const Disc &other);
	bool operator>(const Disc &other);

	friend ostream &operator<<(ostream &out, const Disc &other);

    private:
	int width;

};

#endif
