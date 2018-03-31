// Jacob Kaufmann
#ifndef NUMBERCOUNT_H
#define NUMBERCOUNT_H

class NumberCount {
    private:
        int min, max;
        int count = 0;
        int *A;
    public:
        NumberCount(int minVal, int maxVal);
	~NumberCount();
        void addElement(int number);
        bool removeElement(int number);
        void display();
        int getCount();
};

#endif
