#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

// Insert Node from End
struct Node *insertNodeAtEnd(struct Node *head, int val)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Failed memory allocation");
        return head;
    }
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
        // head = newNode;
        // newNode->next = NULL;
        // return head;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

// create node and add from starting of Linked List
struct Node *createNode(struct Node *List, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Failed Memory allocation");
        return List;
    }
    newNode->data = val;
    newNode->next = List;
    return newNode;
}

//  insert Node Afte rSpecific Node

struct Node *insertAfterSpecificNode(struct Node *head, int specificVal, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
        return head;

    newNode->data = val;
    newNode->next = NULL;

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        if (temp->data == specificVal)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

// Delete From last

struct Node *Deletefromlast(struct Node *head)
{

    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Underflow");
    }

    if (head->next == NULL)
    {
        head = NULL;
    }

    while (temp->next->next != NULL)
    {

        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

// Delete from start

struct Node *DeletefromStart(struct Node *head)
{

    if (head == NULL)
    {
        printf("UnderFlow");
    }

    struct Node *temp = head;
    if (head->next == NULL)
    {
        head = NULL;
    }
    else{
         head = temp->next;
         free(temp);
    }
    
    
    return head;
}

//Reverse Linked List

struct Node* ReverseList(struct Node* head){
    struct Node* prev = NULL;
    struct Node* Next = NULL;
    struct Node* temp = head;

    while(temp != NULL){
        Next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = Next;
    }
    head = prev;
    return head;
}

// Sorting using selection sort

struct Node *SelectionSort(struct Node *head){

    struct Node*temp = head;

    while(temp){
        struct Node* min = temp;
        struct Node* right = min->next;

        while(right){
            if(min->data > right->data){
                min = right;
            }
            right = right->next;
        }
        

        int x = temp->data;
        temp->data = min->data;
        min->data = x;

        temp = temp->next;
    }
    return head;
}

// Print LinkedList
struct Node *printList(struct Node *List)
{
    while (List != NULL)
    {
        printf("%d ->", List->data);
        List = List->next;
    }
}

int findMinimum(struct Node *List){
    int mini = List->data;
    struct Node *temp = List;
    
    while(temp->next != NULL){
        if(mini > temp->data){
            mini = temp->data;
        }
        temp = temp->next;
    }
    return mini;
}

int main()
{
    struct Node *List = NULL;

    struct Node *node1;
    node1 = (struct Node *)malloc(sizeof(struct Node));
    node1->data = 23;
    node1->next = NULL;
    List = node1;

    struct Node *node2 = (struct Node *)malloc(sizeof(struct Node));
    node2->data = 34;
    node2->next = NULL;
    node1->next = node2;

    List = createNode(List, -1);
    List = createNode(List, -5);

    List = insertNodeAtEnd(List, 0);

    List = insertAfterSpecificNode(List, 23, 56);

    printf("\n");
    printf("Lists are: ");
    printList(List);

    int minimum = findMinimum(List);
    printf("\n");
    printf("Minimum value in list is:%d", minimum);

    printf("\n");
    printList(List);

    printf("\n");

    List = Deletefromlast(List);
    List = DeletefromStart(List);

    printf("Lists are: ");
    printList(List);

    printf("\n");

    List = ReverseList(List);

    List = SelectionSort(List);

    printf("Reverse Lists are:");
    printList(List);
    return 0;
}