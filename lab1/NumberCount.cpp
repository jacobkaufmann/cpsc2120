// Jacob Kaufmann
#include <iostream>
#include "NumberCount.h"
using namespace std;

NumberCount::NumberCount(int minVal, int maxVal) : min(minVal),
               max(maxVal), A(new int[max-min+1])
{
}

NumberCount::~NumberCount() {
    delete A;
}

void NumberCount::addElement(int number)
{
    if(number >= min && number <= max)
    {
        count++;
        A[number-min]++;
    }
    else
        cout << number << " Out of range; ";
}

bool NumberCount::removeElement(int number)
{
    if(number >= min && number <= max && A[number-min] > 0)
    {
        count--;
        A[number-min]--;
	return true;
    }
    else 
    {
	cout << number << " not present; ";
    	return false;
    }
}

void NumberCount::display()
{
    cout << endl;
    for(int i = min; i < max + 1; i++)
    {
        cout << i << ": ";
	while(A[i-min] > 0)
        {
            cout << "* ";
    	    A[i-min]--;
	}
        cout << endl;
    }
}

int main() {
NumberCount N(1,9);
N.addElement(10); N.addElement(4); N.addElement(1);
N.addElement(4); N.removeElement(2); N.addElement(3);
N.addElement(7); N.addElement(3); N.removeElement(4);
N.addElement(8); N.addElement(14);N.addElement(3); 
N.addElement(7); N.removeElement(9);
N.display();

return 0;
}
