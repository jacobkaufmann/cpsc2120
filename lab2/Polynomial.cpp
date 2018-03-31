// Jacob Kaufmann
// Polynomial.cpp

#include "Polynomial.h"
#include <iostream>
using namespace std;

Polynomial::Polynomial() : list(new Pair[100]), powerCount(0)
{
}

Polynomial::~Polynomial()
{
    delete list;
}
void Polynomial::incrementBy(int c, int p)
{
    if(c != 0 && p != 0)
    {
        bool powerExists = false;
        for(int i = 0; i < powerCount; i++)
        {
            if(list[i].getY() == p)
            {
                list[i].setX(c + list[i].getX());
                powerExists = true;
            }
        }
        if(!powerExists)
        {
            list[powerCount].setX(c);
            list[powerCount].setY(p);
            powerCount++;
        }

        int j;
        Pair temp;
        for(int i = 1; i < powerCount; i++)
        {
            j = i;
            while(j > 0 && list[j-1].getY() < list[j].getY())
            {
                temp = list[j];
                list[j] = list[j-1];
                list[j-1] = temp;
                j--;
            }
        }
    }
}

int Polynomial::getCount() const
{
    return powerCount;
}

bool Polynomial::operator==(const Polynomial& other) const
{
    if(powerCount != other.powerCount)
        return false;

    for(int i = 0; i < powerCount; i++)
    {
        if(list[i].getX() != other.list[i].getX() || list[i].getY()
           != other.list[i].getY())
            return false;
    }
    return true;
}

ostream &operator<<(ostream &out, const Polynomial &poly)
{
    for(int i = 0; i < poly.getCount(); i++)
    {
        out << (poly.list[i].getX() < 0 && i > 0 ? poly.list[i].getX() * -1 :
             poly.list[i].getX()) << "x^" << poly.list[i].getY();

        if(i < poly.getCount()-1 && poly.list[i+1].getX() > 0)
            out << " + ";
        else if(i < poly.getCount()-1 && poly.list[i+1].getX() < 0)
            out << " - ";
    }
    return out;
}
