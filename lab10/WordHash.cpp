// Jacob Kaufmann
// WordCount.cpp

#include "WordHash.h"
#include <iostream>
using namespace std;

WordHash::WordHash(int arraylength) : arrayLength(arraylength), count(0)
{
    data = new WordCount*[arraylength];
}

WordHash::~WordHash()
{
    for(int i = 0; i < arrayLength; i++)
    {
	if(data[i] != nullptr)
	    delete data[i];
    }
    delete [] data;
}

void WordHash::addWord(const string &word)
{
    insert(word, data, arrayLength);
    if(count/double(arrayLength) >= LOAD_FACTOR)
	rehash();
}

void WordHash::printCommon() const
{
    int index = 0;
    while(data[index] == nullptr)
    {
	index++;
    }
    WordCount *common = data[index];
    for(int i = 0; i < arrayLength; i++)
    {
	if(data[i] != nullptr && data[i]->getCount() > common->getCount())
	    common = data[i];
    }
    cout << common->getWord() << ": " << common->getCount() << endl;
}

void WordHash::rehash()
{
    count = 0;
    WordCount **data2;
    data2 = new WordCount*[arrayLength*2 + 1];
    int oldLen = arrayLength;
    arrayLength = arrayLength*2 + 1;
    for(int i = 0; i < oldLen; i++)
    {
	if(data[i] != nullptr)
	{
	    int frequency = data[i]->getCount();
	    for(int j = 0; j < frequency; j++)
	        insert(data[i]->getWord(), data2, arrayLength);
	}
	delete data[i];
    }
    delete[] data;
    data = data2;
}

void WordHash::insert(const string &word, WordCount** arr, int len)
{
    unsigned int hashVal = hashOf(word)%len;
    unsigned int iterator = hashVal;
    if(arr[iterator] == nullptr)
    {
        arr[iterator] = new WordCount(word);
        count++;
    }
    else
    {
        if(arr[iterator]->getWord() == word)
            arr[iterator]->incrementCount();
        else
        {
            iterator++;
            bool added = false;
            while(!added)
            {
                if(int(iterator) >= len)
                    iterator = 0;
                if(arr[iterator] == nullptr)
                {
                    arr[iterator] = new WordCount(word);
                    count++;
                    added = true;
                }
                else if(arr[iterator]->getWord() == word)
                {
                    arr[iterator]->incrementCount();
                    added = true;
                }
                iterator++;
            }
        }
    }
}

void WordHash::display()
{
    for(int i = 0; i < arrayLength; i++)
    {
	if(data[i] != nullptr)
            cout << data[i]->getWord() << ": " << data[i]->getCount() << endl;
    }
    cout << endl;
}
