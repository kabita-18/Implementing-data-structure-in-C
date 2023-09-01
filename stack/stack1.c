#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
    int top;
    unsigned size;
    int* arr;
};

struct Stack* create(unsigned size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->size * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->size - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Overflow\n");
        return -1;
    }
    stack->top++;
    stack->arr[stack->top] = item;
    return item;
}

int pop (struct Stack* stack){
    if(isEmpty(stack)){
        return -1;
    }
    int popValue = stack->arr[stack->top--];

    return popValue;
}

int main() {
    struct Stack* S1;
    int size=3;
    //scanf("%d", &size);
    S1 = create(size);

    push(S1, 50);
    push(S1, 56);
    push(S1, 78);

    
    printf("Stack Array is: ");

    for(int i = 0; i<= S1->top; i++){
        printf("%d ", S1->arr[i]);
    }

    printf("\n");

    int popValue = pop(S1);
    printf("Poped value: %d", popValue);
     printf("\n");

    for(int i =0; i<=S1->top; i++){
        printf("%d  ", S1->arr[i] );
    }

    

    // Don't forget to free the memory allocated for the stack
    free(S1->arr);
    free(S1);

    return 0;
}
