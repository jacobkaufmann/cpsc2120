// Jacob Kaufmann
// Pair.h

#ifndef PAIR_H
#define PAIR_H

class Pair {
    private:
        int x, y;
    public:
        Pair();
        Pair(int xx, int yy);
        void setX(int xx);
        void setY(int yy);
        int getX() const;
        int getY() const;
};

#endif
