// Jacob Kaufmann
// StackDriver.cpp

#include <iostream>
#include "LinkedStack.h"

int main(int argc, char *argv[])
{
    LinkedStack A;
    LinkedStack B;
    StackType s[argc-1];
    for(int i = 1; i < argc; i++)
        s[i-1] = argv[i];

    for(int i = 0; i < argc - 1; i++)
    {
        if(A.isEmpty())
 	    A.push(s[i]);
	else
	{
	    while(!(A.isEmpty()) && s[i] > A.peek())
            {
	        B.push(A.pop());
	    }
	    A.push(s[i]);
	    while(!(B.isEmpty()))
 	        A.push(B.pop());
	}
    }
    while(!(A.isEmpty()))
        cout << A.pop() << " ";
    cout << endl;
    return 0;
}
