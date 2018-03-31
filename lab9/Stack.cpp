// Jacob Kaufmann
// Stack.cpp
// note that this is #included from Stack.h
// and not compile separately

#include <iostream>
using namespace std;

  template< class E >
  Stack<E>::Stack()
    : arr( new E[capacity] ), count(0)
  {
  }

  template< class E >
  Stack<E>::~Stack()
  {
    delete [] arr;
  }

  template< class E >
  E Stack<E>::peek()
  {
       if(count > 0)
           return arr[count-1];
       else
	   return nullptr;
  }

  template< class E >
  E Stack<E>::pop()
  {
       count--;
       return arr[count];
  }

  template< class E >
  void Stack<E>::push(E item)
  {
    arr[count] = item;
    count++;
  }


  template< class S >
  ostream &operator<<(ostream &out, const Stack<S> &other)
  {
    out << "From bottom to top: ";
    for(int i = 0; i < other.count; i++)
    {
	out << *(other.arr[i]) << " ";
    }
    out << endl;
    return out;
  }
