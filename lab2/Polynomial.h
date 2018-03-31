// Jacob Kaufmann
// Polynomial.h

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Pair.h"
#include <iostream>
using namespace std;

class Polynomial {
    public:
        Polynomial();
        ~Polynomial();
        void incrementBy(int c, int p);
        int getCount() const;
        bool operator==(const Polynomial& other) const;

        friend ostream &operator<<(ostream &out, const Polynomial &poly);

    private:
        Pair *list;
        int powerCount;
};
#endif
