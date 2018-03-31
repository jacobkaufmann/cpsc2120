// LinkedStack.cpp
// Jacob Kaufmann

#include "LinkedStack.h"

LinkedStack::LinkedStack() : head(nullptr)
{
}

LinkedStack::~LinkedStack()
{
    while(head!=nullptr)
    {
        SNode *grab = head->next;
	delete grab;
        head = grab;
    }
}

void LinkedStack::push(StackType item)
{
    SNode *newNode = new SNode(item, head);
    head = newNode;
}

bool LinkedStack::isEmpty() const
{
    return (head==nullptr);
}

StackType LinkedStack::pop()
{
    StackType val = head->data;
    if(isEmpty())
        return ERROR;
    SNode *hold = head->next;
    delete head;
    head = hold;
    return val;
}

StackType LinkedStack::peek() const
{
    return head->data;
}
