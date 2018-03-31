#include <iostream>
using namespace std;
#include "Wart.h"
#include "Digraph.h"

int main()
{
    int width;
    cin >> width;
    Wart W("Orange rules");
    cout << "Width: " << width << endl;
    W.encode(width);
    cout << "Encoded: " << W;
    Digraph D("kafka.txt");
    W.decode(D);
    cout << endl << "Decoded: " << W << endl;
    return 0;
}
