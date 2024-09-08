#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int ptr = -1, size = 5;
int* stack;

bool isFull () {
    if(ptr == size - 1) 
    return true;
    else
    return false;
}

bool isEmpty () {
    if (ptr == -1)
    return true;
    else
    return false;
}

void push (int num) {
    if(isFull()) 
    return;
    stack[++ptr] = num;
}

int pop () {
    if(!isEmpty()) {
        ptr--;
        return stack[ptr + 1];
    }
}

int sizeOfStack () {
    return ptr + 1;
}

int top () {
    if(!isEmpty()) {
        return stack[ptr];
    }
}

void printStack () {
    for (int i = 0; i<=ptr; i++) {
        printf("%d\t",stack[i]);
    }
}

int main () {
    stack = malloc(size*sizeof(int));
    printf("%d",sizeOfStack());
    printf("\n");
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printStack();
    printf("\n");
    printf("%d",sizeOfStack());
    printf("\n");
    pop();
    pop();
    printf("\n");
    printf("%d",sizeOfStack());
    printf("\n");
    printStack();
    printf("\n");
    pop();
    pop();
    pop();
    printf("\n");
    printf("%d",sizeOfStack());
    printStack();
    printf("\n");

}