// LinkedStack.h
// Jacob Kaufmann

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <string>
using namespace std;

typedef string StackType;
const StackType ERROR = "";

struct SNode {
   StackType data;
   SNode *next;
   SNode( StackType & d, SNode *n) : data(d), next(n) {}
};

class LinkedStack
{
  public:
     LinkedStack( );              // constructor
     ~LinkedStack( );             // destructor
     void push(StackType item);   // pushes object onto stack
     bool isEmpty() const;        // returns whether stack is empty or not
     StackType pop();             // pops and returns top element from stack
     StackType peek() const;      // returns value of data on top of stack

  private:
     SNode *head;
};
#endif
