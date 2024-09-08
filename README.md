# TRF_TASK1_DSA_LEVEL2_2024

Hello EveryOne
Submit Your Task In Any Preffered Programming Language.  
Submit your program file Folders With Name as TRF_LEVEL_2_<Your_name>   

  
You are given two non-empty linked lists representing two non-negative integers.   
The digits are stored in reverse order, and each of their nodes contains a single digit.   
Add the two numbers and return the sum as a linked list.  

You may assume the two numbers do not contain any leading zero, except the number 0 itself.  

![image](addtwonumber1.jpg)

Example 1:

Input:   
l1 = [2,4,3],   
l2 = [5,6,4]  
Output: [7,0,8]  
Explanation: 342 + 465 = 807.  
  
Example 2:  
 
Input:  
l1 = [0],  
l2 = [0]  
Output: [0]  

Example 3:  

Input:  
l1 = [9,9,9,9,9,9,9],  
l2 = [9,9,9,9]  
Output: [8,9,9,9,0,0,0,1]  

CODE:
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

