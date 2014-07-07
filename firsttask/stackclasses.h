#pragma once

class stack
{
   public:
        stack(){}
        virtual void push(char val)=0;
        virtual char pop()=0;
        virtual int emptyStack()=0;
        virtual ~stack(){}
};

class MassivStack: public stack
{
    public:
        MassivStack();
        void push(char val );
        char pop();
        int emptyStack();
        virtual ~MassivStack(){}
    private:
        int i;
        char val[10] = {0};
};

class PointerStack: public stack
{
    public:
        PointerStack();
        void push(char val );
        char pop();
        int emptyStack();
        virtual ~PointerStack();
    private:
        struct stackElement
        {
            char val;
            stackElement *next;
        };
        stackElement *head;

};


class Calculator
{
public:
    Calculator();
    void calculator(char c);
    int result();
    virtual ~Calculator(){}
private:
    stack *calc;
};

