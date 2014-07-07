#include <QCoreApplication>
#include <QtCore/QDebug>

#include <iostream>

#include "stackclasses.h"

using namespace std;

/*struct list{
    int val;
    list *next;
};

int fibonachi (int n)
{

    if (n>2)
    return fibonachi (n-1) + fibonachi (n-2);
    else
        return 1;

}

int main()
{
//    int x=0;
//    cin >> x;
//    qDebug() << "Hello, world" << x;

//    int a[10]={0};
//    for (int element : a)    // выводит все элементы массива
//        cout << element << endl;
//    for (int i=0; i<10; ++i)
 //int p=0;
// cin >> p;
//cout << fibonachi(6);
  //  return 0;

    int *a = new int[10];
    int *b = a;

    *a = 1; //разименование(то есть работа как с обычной переменной), в ячейку куда указывало а, написало 1
    int b = 0;
    a = &b; //в а присваивается адрес б, теперь а указывает на б

    cout << *a << endl;
    a = nullptr;
    delete [] a;

    int const c = 0; // не дает менять переменную

    int const * const a = nullptr;





    // struct

    list el;
    el.val = 10;
    el.next = nullptr;


    list *elem = new list;
    elem->value = 10;  // (*elem).value = 10;
    elem->next = nullptr;

   delete elem;



    list *elem1 = new list;
    elem1->value = 10;  // (*element).value = 10;
    elem1->next = nullptr;

    list *elem2 = new list;
    elem2->value = 20;  // (*element).value = 20;
    elem2->next = nullptr;

    elem1->next = elem2; // elem2 - это уже адрес



}
*/
\



/*
#include <stack.h> ili <massivestack.h>
int main ()
{
    char val = 0;
    Stack *stack = createStack();
    while (cin >> val, val != 'q')
    {
        if (val != ' ')
            push(stack, val-'0');
    }
    while (!emptyStack(stack))
        cout << pop(stack) << endl;
    deleteStack(stack);

    return 0;
}
*/



int main ()
{
    cout << "Please, for massivestack tape '1', for pointerstack tape '2', for stackcalculator tape '3'" <<endl;
    int variant;
    cin >> variant;
    cout << "Please, type symbols till =" <<endl;
    switch (variant)
    {
    case 1:
    {
        stack *massivstack = new MassivStack();
        char val = 0;
        while (cin >> val, val != '=')
        {
            if (val != ' ')
                massivstack->push(val);
        }
        while (!massivstack->emptyStack())
            cout << massivstack->pop() << endl;
    }
    break;

    case 2:
    {
        stack *pointerstack = new PointerStack();
        char val = 0;
        while (cin >> val, val != '=')
        {
            if (val != ' ')
                pointerstack->push(val);
        }
        while (!pointerstack->emptyStack())
            cout << pointerstack->pop() << endl;
    }
    break;

    case 3:
    {
        stack *typestack = new PointerStack();
        Calculator *calcul = new Calculator(typestack);
        char val = 0;
        while (cin >> val, val != '=')
            calcul->calculator(val);
        cout << calcul->result();
    }
    break;

    default: cout << "ERROR" ;
    }
    return 0;
}
