#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

Node* sum(Node* l1, Node* l2)
{
    Node* result = NULL;
    Node* last = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL)
    {
        int sum = carry;
        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        Node* newNode = createNode(sum % 10);

        if (result == NULL)
        {
            result = newNode;
        }
        else
        {
            last->next = newNode;
        }
        last = newNode;

        if (carry > 0)
    {
        Node* newNode = createNode(carry);
        last->next = newNode;
    }
    }
    return result;
}

Node* createList()
{
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    Node* head = NULL;
    Node* last = NULL;

    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        Node* newNode = createNode(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            last->next = newNode;
        }
        last = newNode;
    }
    return head;
}

int main()
{
    printf("Create first list:\n");
    Node* l1 = createList();

    printf("Create second list:\n");
    Node* l2 = createList();

    printf("First list: ");
    printList(l1);

    printf("Second list: ");
    printList(l2);

    Node* result = sum(l1, l2);
    printf("Sum list: ");
    printList(result);

    return 0;
}
