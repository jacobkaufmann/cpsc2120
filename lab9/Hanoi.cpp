// Jacob Kaufmann
// Hanoi.cpp

#include "Disc.h"
#include "Stack.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int N = 0;
    if(argc > 1)
        N = atoi(argv[1]);
    else
        cout << "Provide number of discs as command-line argument" << endl;
    Stack<Disc*> pegs[3];
    int possibleMoves[6];
    srand(time(0));

    // push discs onto stack for first peg
    for(int i = N; i > 0; i--)
    {
	Disc* d = new Disc(i);
	pegs[0].push(d);
    }

    cout << "peg 1 " << pegs[0] << "peg 2 " << pegs[1] << "peg 3 " << pegs[2];
    cout << endl;

    int counter = 0;
    int choice1, choice2;

    // loop until all discs are on the third peg
    while(pegs[2].getCount() != N)
    {
	counter = 0;
        for(int i = 0; i < 3; i++)
	{
	    if(i==0)
	    {
	        choice1 = 1;
		choice2 = 2;
	    }
	    else if(i==1)
	    {
		choice1 = 0;
		choice2 = 2;
	    }
	    else
	    {
		choice1 = 0;
		choice2 = 1;
	    }

	    // find possible moves
	    if(pegs[i].getCount() > 0 && (pegs[choice1].getCount() == 0 || *(pegs[i].peek()) < *(pegs[choice1].peek())))
	    {
		possibleMoves[counter] = i * 10 + choice1;
		counter++;
	    }
            if(pegs[i].getCount() > 0 && (pegs[choice2].getCount() == 0 || *(pegs[choice2].peek()) > *(pegs[i].peek())))
            {
                possibleMoves[counter] = i * 10 + choice2;
                counter++;
            }
	}

    // randomly select a move
    int selection = rand() % counter;
    int a, b;
    a = possibleMoves[selection]/10;
    b = possibleMoves[selection]%10;
    pegs[b].push(pegs[a].pop());

    cout << "peg 1 " << pegs[0] << "peg 2 " << pegs[1] << "peg 3 " << pegs[2];
    cout << endl;
    }

    return 0;
}

