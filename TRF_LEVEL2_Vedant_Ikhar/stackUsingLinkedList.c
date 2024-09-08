#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*free(nodePtr);
    I Defined Node* head as global so need to pass to functions
    and used a copy of head in printList () to not disturb my head pointer
    i am Legend
*/

typedef struct Node {
    int data;
    struct Node* link;
}Node;

Node* head = NULL;
int size = -1;

bool isEmpty () {
    if (head == NULL) 
    return true;
    else 
    return false;
}

int sizeOfStack () {
    return size + 1;
}

int peak () {
    return head->data;
}

void push (int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->link = head;
    head = new_node;
    size++;
}

int pop () {
    Node* next_node = NULL;
    Node* current_node = head;
    int data = current_node->data;
    next_node = current_node->link;
    free(current_node);
    current_node = NULL;
    head = next_node;
    size--;
    return data;
}

void printList () {
    Node* copy = head;
    while (copy != NULL) {
        printf("%d <- ",copy->data);
        copy = copy->link;
    }
    copy = NULL;
    printf("NULL");
}

int main () {
    Node* head = NULL;
    bool status = isEmpty();
    int num = sizeOfStack();
    printf("Is empty = %d\nSize of stack = %d\n",status,num);
    push(1);
    push(2);
    push(3);
    status = isEmpty();
    num = sizeOfStack();
    printf("Is empty = %d\nSize of stack = %d\n",status,num);
    printList();  
    num = pop();
    printf("\n%d\n",num);
    printList();
}