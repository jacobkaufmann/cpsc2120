// Jacob Kaufmann
// CharRecord.cpp

#include "CharRecord.h"

CharRecord::CharRecord() : charString(""), count(0)
{
}

CharRecord::CharRecord(string s, int c) : charString(s), count(c)
{
}

string CharRecord::getCharString()
{
    return charString;
}

int CharRecord::getCount()
{
    return count;
}

bool CharRecord::operator<(const CharRecord &other) const
{
    return count < other.count || (count == other.count && charString < other.charString);
}

bool CharRecord::operator>(const CharRecord &other) const
{
    return count > other.count;
}

CharRecord::~CharRecord()
{
}
