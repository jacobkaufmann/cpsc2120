// Jacob Kaufmann
// Square.cpp

#include "Square.h"

Square::Square() : state(Square::openChar)
{
}

char Square::getState()
{
    return state;
}

void Square::setState(char s)
{
    state = s;
}

int Square::getTileNum()
{
    return tileNumber;
}

void Square::setTileNum(int n)
{
    tileNumber = n;
}

void Square::reset()
{
    state = Square::openChar;
}

char Square::openChar = '.';
char Square::forbiddenChar = '#';
bool Square::charsSet = false;
