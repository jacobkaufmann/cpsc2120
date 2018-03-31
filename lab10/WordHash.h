#ifndef WORDHASH_H
#define WORDHASH_H
#include "WordCount.h"
#include <string>
using namespace std;

class WordHash
{
   private:
      int arrayLength;
      WordCount **data;
      int count;

      static unsigned int hashOf(const string & word)
      {
          return hash<string>()(word);
      }
      static constexpr double LOAD_FACTOR = .7;
      void rehash( );
      void insert(const string &word, WordCount** arr, int len);

   public:
      WordHash(int arraylength);
      ~WordHash( );
      void addWord(const string & word);
      void printCommon() const;
      void display();
};

#endif
