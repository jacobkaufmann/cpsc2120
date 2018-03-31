// Jacob Kaufmann
// Filler.cpp

#include "Filler.h"

Filler::Filler(string fileName) : Configuration(fileName)
{
}

void Filler::greedyFill(int tileLength)
{
    for(int i = 0; i < rows; i++)
    {
	for(int j = 0; j < cols; j++)
	{
	    if(fitsHorizontally(i, j, tileLength))
	        placeTileAt(i+1, j+1, true, tileLength);
	}
    }
    for(int i = 0; i < cols; i++)
    {
	for(int j = 0; j < rows; j++)
	{
	    if(fitsVertically(j, i, tileLength))
	        placeTileAt(j+1, i+1, false, tileLength);
	}
    }
}

void Filler::betterFill(int tileLength)
{
    for(int i = 0; i < rows; i++)
    {
	for(int j = 0; j < cols; j++)
	{
	    if(fitsHorizontally(i, j, tileLength) && !(fitsVertically(i, j, tileLength)))
		placeTileAt(i+1, j+1, true, tileLength);
	    else if(fitsVertically(i, j, tileLength) && !(fitsHorizontally(i, j, tileLength)))
                placeTileAt(i+1, j+1, false, tileLength);
	    else
	    {
		if(fitsHorizontally(i, j, tileLength) && fitsVertically(i, j, tileLength))
		{
		    placeTileAt(i+1, j+1, true, tileLength);
		}
	    }
	}
    }
}

Filler::~Filler()
{
}
