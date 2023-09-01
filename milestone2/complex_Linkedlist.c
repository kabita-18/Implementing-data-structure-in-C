#include <stdio.h>
#include <stdlib.h>

typedef struct complex {
    int real;
    int imag;
} Complex;

struct Node {
    Complex data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(Complex data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void pushAtBeginning(Node** headRef, Complex data) {
    Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void pushAtEnd(Node** headRef, Complex data) {
    Node* newNode = createNode(data);

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void pushInBetween(Node* prevNode, Complex data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d + %di -> ", temp->data.real, temp->data.imag);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int size;

    printf("Enter the number of complex numbers: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        Complex data;
        printf("Enter the real and imaginary parts of complex number %d: ", i + 1);
        scanf("%d %d", &data.real, &data.imag);
        pushAtEnd(&head, data);
    }

    // Call pushAtBeginning
    Complex dataBegin = { 10, 20 };
    pushAtBeginning(&head, dataBegin);

    // Call pushInBetween
    Complex dataInBetween = { 100, 200 };
    Node* temp = head;
    int pos = 2; // Assuming you want to insert after the second node
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp != NULL) {
        pushInBetween(temp, dataInBetween);
    } else {
        printf("Invalid position.\n");
    }

    printf("Linked List after pushAtBeginning and pushInBetween: ");
    displayList(head);

    return 0;
}
