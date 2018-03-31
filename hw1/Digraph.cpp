// Jacob Kaufmann
// Digraph.cpp

#include <iostream>
#include "Digraph.h"
#include <ctype.h>
using namespace std;

// No-argument constructor that sets default proportions
Digraph::Digraph() : digraphScores(), digraphCount(0)
{
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            digraphScores[i][j]=0.0;
        }
    }
    digraphScores[int('t')-97][int('h')-97]=.1;
    digraphScores[int('h')-97][int('e')-97]=.1;
    digraphScores[int('i')-97][int('n')-97]=.1;
    digraphScores[int('e')-97][int('r')-97]=.1;
    digraphScores[int('a')-97][int('n')-97]=.1;
    digraphScores[int('r')-97][int('e')-97]=.1;
    digraphScores[int('n')-97][int('d')-97]=.1;
    digraphScores[int('a')-97][int('t')-97]=.1;
    digraphScores[int('o')-97][int('n')-97]=.1;
    digraphScores[int('n')-97][int('t')-97]=.1;
}


// Constructor takes name of a text file, uses that to determine proportions
// Prints out the digraph with the highest proportion
Digraph::Digraph(string fileName) : digraphScores(), digraphCount(0)
{
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            digraphScores[i][j]=0.0;
        }
    }

    ifstream input(fileName);
    string s;
    char a, b;
    while(input >> s)
    {
        for(int i = 0; i < int(s.length()-1); i++)
        {
            a = s[i];
            b = s[i+1];

            a = tolower(a);
            b = tolower(b);
            if(int(a) > 96 && int(a) < 123 && int(b) > 96 && int(b) < 123)
            {
                digraphScores[int(a)-97][int(b)-97]+=1.0;
                digraphCount++;
            }
        }
    }

    double max = 0.0;
    int max1, max2;
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            digraphScores[i][j] = digraphScores[i][j]/double(digraphCount);
            if(digraphScores[i][j] > max)
            {
                max = digraphScores[i][j];
                max1 = i;
                max2 = j;
            }
        }
    }
    cout << "Most commmon was: " << char(max1+97) << char(max2+97)
         << " with a proportion of " << max << endl;
}

// Takes two chars and returns proportion associated with the digraph
double Digraph::getScore(char a, char b)
{
    return digraphScores[int(a)-97][int(b)-97];
}

// Takes a string and returns the sum of the digraphs in the string
double Digraph::getScore(string &s)
{
    double score = 0.0;
    char a, b;
    for(int i = 0; i < int(s.length()-1); i++)
    {
        a = s[i];
        b = s[i+1];
        a = tolower(a);
        b = tolower(b);
        if(int(a) > 96 && int(a) < 123 && int(b) > 96 && int(b) < 123)
            score += getScore(a, b);
    }
    return score;
}
