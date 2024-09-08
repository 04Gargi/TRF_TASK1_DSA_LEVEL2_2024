#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
}Node;

void insertAtBegin (Node** head_ref, int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->link = *head_ref;
    *head_ref = new_node;
}

void printList (Node* node) {
    while (node != NULL) {
        printf("%d->",node->data);
        node = node->link;
    }
    printf("NULL");
}

void insertAtEnd (Node** head_ref, int data) {
    Node* new_node = malloc(sizeof(Node));
    Node* last = *head_ref;
    new_node->data = data;
    new_node->link = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->link != NULL)
    {
        last = last->link;
    }
    last->link = new_node;
}

int extractReverseNum (Node* node) {
    int num = 0, temp;
    while (node != NULL)
    {   
        temp = node->data;
        num = num*10 + temp;
        node = node->link;
    }
    return num;
}

int main () {
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head3 = NULL;
    int remain = 0;
    insertAtEnd(&head1, 1);
    insertAtEnd(&head1, 2);
    insertAtEnd(&head1, 3);
    insertAtEnd(&head2, 9);
    insertAtEnd(&head2, 8);
    printList(head1);
    printf("\n");
    printList(head2);
    int num1 = extractReverseNum(head1);
    int num2 = extractReverseNum(head2);
    int sum = num1 + num2;
    printf("\nsum = %d",sum);
    while (sum != 0) {
        remain = sum % 10;
        insertAtEnd(&head3, remain);
        sum = sum / 10;
    }
    printf("\n");
    printList(head3);
}
