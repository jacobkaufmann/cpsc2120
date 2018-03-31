// Jacob Kaufmann
// Configuration.cpp

#include "Configuration.h"

Configuration::Configuration(int rr, int cc) : rows(rr), cols(cc), open(Square::openChar),
				forbidden(Square::forbiddenChar), countOfTiles(0)
{
    board = new Square*[rr];
    for(int i = 0; i < rr; i++)
        board[i] = new Square[cc];
}

Configuration::Configuration(string fileName) : countOfTiles(0)
{
    ifstream input(fileName);

    // get values for board dimensions
    input >> rows;
    input >> cols;

    // get values for the open and forbidden characters
    input >> open;
    input >> forbidden;


    // initialize the board
    board = new Square*[rows];
    for(int i = 0; i < rows; i++)
        board[i] = new Square[cols];

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
	    board[i][j].setState(open);

    // update the squares
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
	{
	    char state;
	    input >> state;
	    if(state == forbidden) forbid(i+1,j+1);
	}
    }
}

bool Configuration::placeTileAt(int rStart, int cStart, bool isHorizontal, int tileLength)
{
    // adjust rStart and cStart to correspond to appropriate indexes
    rStart--;
    cStart--;

    // check to see if starting position is valid
    if(rStart < 0 || rStart >= rows || cStart < 0 || cStart >= cols)
    {
	cout << "Starting tile position is not valid" << endl;
	return false;
    }

    // check for negative tileLength
    if(tileLength < 0)
    {
	cout << "Tiles must have a length greater than 0" << endl;
	return false;
    }

    // check to see if tile goes off board
    if((isHorizontal && cStart+tileLength > cols) || (!isHorizontal && rStart+tileLength > rows))
    {
	cout << "Tile goes off board" << endl;
	return false;
    }

    // check to see if the tile will fit on the board horizontally
    if(isHorizontal)
    {
	if(!fitsHorizontally(rStart, cStart, tileLength))
	{
	    cout << "At least one square is covered/forbidden" << endl;
	    return false;
	}

	countOfTiles++;
	for(int j = cStart; j < cStart+tileLength; j++)
	{
	    board[rStart][j].setState('c');
	    board[rStart][j].setTileNum(countOfTiles);
	}
	tilesOnBoard.emplace_front(rStart+1, cStart+1, isHorizontal, tileLength);
	return true;
    }

    // check to see if the tile will fit on the board vertically
    else if(!isHorizontal)
    {
        if(!fitsVertically(rStart, cStart, tileLength))
	{
	    cout << "At least one square is covered/forbidden" << endl;
	    return false;
	}

	countOfTiles++;
        for(int j = rStart; j < rStart+tileLength; j++)
        {
            board[j][cStart].setState('c');
            board[j][cStart].setTileNum(countOfTiles);
        }
	tilesOnBoard.emplace_back(rStart+1, cStart+1, isHorizontal, tileLength);
	return true;
    }
    return false;
}

void Configuration::forbid(int r, int c)
{
    // adjust the indexes
    r--;
    c--;

    if(r < 0 || r >= rows || c < 0 || c > cols || board[r][c].getState() != open) return;

    board[r][c].setState(forbidden);
}

void Configuration::dumpToScreen() const
{
    // find which characters to use
    char o, f;
    if(Square::charsSet)
    {
        o = Square::openChar;
        f = Square::forbiddenChar;
    }
    else
    {
	o = open;
	f = forbidden;
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
	{
	    if(board[i][j].getState() == open) cout << o;
	    else if(board[i][j].getState() == forbidden || board[i][j].getTileNum() == 0) cout << f;
	    else
	    {
		if(board[i][j].getTileNum() < 10) cout << board[i][j].getTileNum();
		else cout << char(55 + board[i][j].getTileNum());
	    }
	}
    cout << endl;
    }
}

list<Placement> Configuration::getPossiblePlacements(int tileLength)
{
    list<Placement> possiblePlacements;
    for(int i = 0; i < rows; i++)
    {
	for(int j = 0; j < cols; j++)
	{
	    if(fitsHorizontally(i, j, tileLength))
		possiblePlacements.emplace_front(i+1, j+1, true, tileLength);
	    if(fitsVertically(i, j, tileLength))
		possiblePlacements.emplace_back(i+1, j+1, false, tileLength);
	}
    }
    return possiblePlacements;
}

bool Configuration::fitsHorizontally(int rStart, int cStart, int tileLength)
{
    if(cStart+tileLength > cols) return false;
    for(int i = cStart; i < cStart+tileLength; i++)
        if(board[rStart][i].getState() != open) return false;
    return true;
}

bool Configuration::fitsVertically(int rStart, int cStart, int tileLength)
{
    if(rStart+tileLength > rows) return false;
    for(int i = rStart; i < rStart+tileLength; i++)
        if(board[i][cStart].getState() != open) return false;
    return true;
}

Configuration::~Configuration()
{
    for(int i = 0; i < rows; i++)
	delete [] board[i];
    delete [] board;
}
