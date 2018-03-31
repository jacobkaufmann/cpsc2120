// Jacob Kaufmann
// Recursion.cpp

#include "Recursion.h"
#include <iostream>
using namespace std;

Recursion::Recursion(string fileName) : grid(), marked()
{
    ifstream input(fileName);
    char a;
    int i = 0;
    int j = 0;
    while(input >> a)
    {
        if(a == '.')
           grid[i][j] = 0;
        else
            grid[i][j] = 1;
        j++;
        if(j==10)
        {
            j=0;
            i++;
        }
    }
}

void Recursion::print()
{
    int group = 1;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(grid[i][j] != 0 && !marked[i][j])
            {
                cout << "Group " << group << ": ";
	        printGroupWith(i,j);
                group++;
		cout << endl;
 	    }
        }
    }
}

void Recursion::printGroupWith(int i, int j)
{
    if(i>=0 && i<10 && j>=0 && j<10 && !marked[i][j])
    {
        if(grid[i][j] != 0)
        {
      	    cout << "(" << i << "," << j << "), ";
            marked[i][j] = true;
            printGroupWith(i-1, j);
            printGroupWith(i+1, j);
            printGroupWith(i, j-1);
            printGroupWith(i, j+1);
        }
    }
}

int main()
{
    cout << "Enter filename: ";
    string name;
    getline(cin, name);
    Recursion R(name);
    R.print();
    return 0;
};
