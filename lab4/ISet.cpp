// Jacob Kaufmann
// ISet.cpp

// Use Gimp to view ppm
// PHASE CHANGE AT .001

#include "ISet.h"
#include <iostream>
using namespace std;

ISet::ISet() : rows(40), cols(40), grid()
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            grid[i][j] = false;
}

void ISet::output()
{
    int redCount = 0;
    int blueCount = 0;
    FILE *output;
    output = fopen("lab4.ppm", "w");
    fprintf(output, "P3\n");
    fprintf(output, "%d %d %d\n", rows, cols, 255);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
      	    if(grid[i][j] && (i+j)%2 == 0)
            {
		blueCount++;
    	        fprintf(output, "%4d%4d%4d", 0, 0, 255);
 	    }
	    else if(grid[i][j] && (i+j)%2 != 0)
 	    {
		redCount++;
 		fprintf(output, "%4d%4d%4d", 255, 0, 0);
	    }
            else
 		fprintf(output, "%4d%4d%4d", 255, 255, 255);
        }
	fprintf(output, "\n");
    }
}

void ISet::evolve(int evolutions, double p)
{
    int r, c;
    bool canBeAdded;
    double result;
    for(int i = 0; i < evolutions; i++)
    {
        canBeAdded = true;
        r = rand()%rows;
        c = rand()%cols;

        if(r > 0 && grid[r-1][c]==true)
            canBeAdded = false;
        if(r < rows - 1 && grid[r+1][c]==true)
            canBeAdded = false;
        if(c > 0 && grid[r][c-1]==true)
            canBeAdded = false;
        if(c < cols - 1 && grid[r][c+1]==true)
            canBeAdded = false;

        result = ((double)rand()/(double)RAND_MAX);
        if(canBeAdded && result <= p)
            grid[r][c] = true;
    }
}


int main()
{
    ISet S;
    int evolutions;
    srand(time(0));
    cout << "Enter number of evolutions: ";
    cin >> evolutions;
    S.evolve(evolutions, .5);
    S.output();
    return 0;
}
