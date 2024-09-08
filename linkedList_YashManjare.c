#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Node* addTwoLists(struct Node* first, struct Node* second) {
    struct Node* result = NULL;
    struct Node* temp, *prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL) {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);

        carry = sum / 10;

        sum = sum % 10;

        temp = newNode(sum);

        if (result == NULL) {
            result = temp;
        } else { 
            prev->next = temp;
        }

        prev = temp;

        if (first) first = first->next;
        if (second) second = second->next;
    }

    if (carry > 0) {
        temp->next = newNode(carry);
    }

    return result;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
        if (head != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main() {
    struct Node* first = newNode(2);
    first->next = newNode(4);
    first->next->next = newNode(3); 

    struct Node* second = newNode(5);
    second->next = newNode(6);
    second->next->next = newNode(4); 

    printf("L1: ");
    printList(first);

    printf("L2: ");
    printList(second);

    struct Node* result = addTwoLists(first, second);

    printf("L3: ");
    printList(result);

    return 0;
}
