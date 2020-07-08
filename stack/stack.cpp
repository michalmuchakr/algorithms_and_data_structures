#include "stack.h"

Stack::stack {
    int val;
    stack* next;
};

Stack::Stack() {
    stack = new stack();
}

void Stack::push() {
    stack *ptr = new stack;
    ptr->val = x;
    ptr->next = stack;
    stack = ptr;
};

Stack*::pop() {
    stack *ptr = stack;
    stack = ptr->next;
    return ptr;
};

void Stack::isEmpty() {
    return stack == NULL;
};

void Stack::top() {
    if (stack == NULL)
        cout << "Stack is empty"
    else
        cout << stack->val;
};