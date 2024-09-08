#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct Node* addLists(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* temp, *prev = NULL;
    int carry = 0, sum;

    while (head1 != NULL || head2 != NULL) {
        sum = carry + (head1 ? head1->data : 0) + (head2 ? head2->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;

        temp = createNode(sum);

        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;

        if (head1) head1 = head1->next;
        if (head2) head2 = head2->next;
    }

    if (carry > 0) {
        temp->next = createNode(carry);
    }

    return result;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* inputList(int n) {
    struct Node* head = NULL;
    struct Node* temp, *prev = NULL;
    int data;

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);

        temp = createNode(data);

        if (head == NULL) {
            head = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
    }

    return head;
}

int main() {
    int n1, n2;

    printf("Enter the number of elements in the first list: ");
    scanf("%d", &n1);
    struct Node* list1 = inputList(n1);

    printf("Enter the number of elements in the second list: ");
    scanf("%d", &n2);
    struct Node* list2 = inputList(n2);

    printf("First List: ");
    printList(list1);

    printf("Second List: ");
    printList(list2);

    list1 = reverseList(list1);
    list2 = reverseList(list2);

    struct Node* result = addLists(list1, list2);

    printf("Resultant Sum List (in reversed form): ");
    printList(result);

    return 0;
}
