// Jacob Kaufmann
// Wart.cpp

#include <iostream>
#include "Wart.h"
using namespace std;

// Constructor takes a string  and sets message to that string
Wart::Wart(string m) : message(m)
{
}

void Wart::encode(int width)
{
    string encoded;
    int row = 0;
    int rows;
    if(message.length()%width == 0)
        rows = message.length()/width;
    else
        rows = message.length()/width + 1;

    for(int i = 0; i < width; i++)
    {
        while(row < rows)
        {
            if(i + (row*width) < int(message.length()))
                encoded = encoded + message[i + (row*width)];
            else if(i + (row*width) == (rows*width) - 1)
                encoded = encoded + ".";
            else
                encoded = encoded + " ";
            row++;
        }
        row = 0;
    }
    message = encoded;
}

void Wart::decode(Digraph & D)
{
    double max = 0.0;
    string temp, decoded;
    int col = 0;
    int cols;
    int rows;
    for(int i = 1; i <= int(message.length()); i++)
    {
        if(message.length()%i==0)
        {
            for(int j = 0; j < int(message.length()/i); j++)
            {
                cols = i;
                rows = message.length()/cols;
                while(col < cols)
                {
                    temp += message[j + (col*rows)];
                    col++;
                }
                col = 0;
            }
            if(D.getScore(temp) > max)
            {
                decoded = temp;
                max = D.getScore(decoded);
            }
            temp.clear();
        }
    }
    message = decoded;
}

ostream &operator<<(ostream &out, const Wart& myWart)
{
    cout << myWart.message;
    return out;
}
