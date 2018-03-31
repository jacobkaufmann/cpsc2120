// Jacob Kaufmann
// Filler.h

#ifndef FILLER_H
#define FILLER_H

#include "Configuration.h"

class Filler : public Configuration
{
    public:
	Filler(string fileName);
	void greedyFill(int tileLength);
	void betterFill(int tileLength);
	~Filler();
};

#endif
