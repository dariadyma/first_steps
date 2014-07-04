#pragma once

struct Stack;

Stack *createStack();
void deleteStack(Stack *stack);
void push(Stack *stack, int val );
int pop(Stack *stack);
int emptyStack(Stack *stack);
