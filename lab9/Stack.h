// Jacob Kaufmann
// Stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <class E>
class Stack
{
 private:
   E* arr;
   int count;
   static const int capacity = 100; // note: not all compilers allow 
                                    // in-class initialization

 public:
   Stack();
   ~Stack();

   E peek();
   E pop();
   void push(E item);

   bool isEmpty() const
   {
     return (count==0);
   }
   int getCount() const
   {
     return count;
   }

   template< class S >
   friend ostream &operator<<(ostream & out, const Stack<S> & other);

};

#include "Stack.cpp"

#endif

