// Jacob Kaufmann
// Square.h

#ifndef SQUARE_H
#define SQUARE_H

class Square {

public:
    Square();
    char getState();
    void setState(char s);
    int getTileNum();
    void setTileNum(int n);
    void reset();

    static char openChar, forbiddenChar;
    static bool charsSet;

    static void setChars(char o, char f)
    {
	openChar = o;
	forbiddenChar = f;
	charsSet = true;
    }

private:
    char state;
    int tileNumber;
};

#endif
