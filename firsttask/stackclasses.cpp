#include "stackclasses.h"


MassivStack::MassivStack()
{
    i = -1;
}

void MassivStack::push(char value)
{
    i++;
    val[i] = value;
}

char MassivStack::pop()
{
    char value=val[i];
    val[i] = 0;
    i--;
    return value;
}

int MassivStack::emptyStack()
{
    if (i == -1)
        return 1;
    return 0;
}







PointerStack::PointerStack()
{
    head = nullptr;
}

void PointerStack::push(char val )
{
    stackElement *newStackelement = new stackElement;
    newStackelement->val = val;
    newStackelement->next = head;
    head = newStackelement;
}

char PointerStack::pop()
{
    stackElement *temp = head;
    head = head->next;
    char val=temp->val;
    delete temp;
    return val;
}

int PointerStack::emptyStack()
{
    if (head == nullptr)
        return 1;
    return 0;
}

PointerStack::~PointerStack()
{
    while (head != nullptr)
        pop();
}




Calculator::Calculator()
{
   calc = new PointerStack();
}



void Calculator::calculator ( char c)
{
    switch (c)
    {
    case '+':
    {
        int a = calc->pop();
        int b = calc->pop();
        calc->push(a + b);
    }
        break;
    case '-':
    {
        int a = calc->pop();
        int b = calc->pop();
        calc->push ( a - b);
    }
        break;
    case '*':
    {
        int a = calc->pop();
        int b = calc->pop();
        calc->push ( a * b );
    }
        break;
    case '/':
    {
        int a = calc->pop();
        int b = calc->pop();
        calc->push ( a / b );
    }
        break;
    default: calc->push (c - '0');
        break;
    }
}

int Calculator::result ( )
{
    return calc->pop();
}
