// Jacob Kaufmann
// Runner.cpp

#include <iostream>
#include "Wart.h"
#include "Digraph.h"
using namespace std;

int main()
{
    string file, sentence;
    cout << "Enter file name for digraph: ";
    getline(cin, file);
    Digraph A;
    Digraph D(file);
    cout << "Enter sentence terminated by <ENTER>: ";
    getline(cin, sentence);
    cout << "This gets a score of: " << D.getScore(sentence) << endl;
    Wart W(sentence);
    W.decode(D);
    cout << "The decoded sentence is: " << endl << W << endl;
    return 0;
}
