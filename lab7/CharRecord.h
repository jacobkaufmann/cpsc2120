// Jacob Kaufmann
// CharRecord.h

#ifndef CHARRECORD_H
#define CHARRECORD_H

#include <iostream>
using namespace std;

class CharRecord {

    private:
	string charString;
	int count;

    public:
	CharRecord();
	CharRecord(string s, int c);
	string getCharString();
	int getCount();
	bool operator<(const CharRecord & other) const;
	bool operator>(const CharRecord & other) const;
	~CharRecord();
};

#endif
