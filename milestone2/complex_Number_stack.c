#include <stdio.h>
#include <stdlib.h>

typedef struct complex_Number_stack
{
    int real;
    int imag;
} Complex;

typedef struct Stack
{
    int top;
    int capacity;
    Complex* array;
} Stack;

Stack* createStack(int capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (Complex*)malloc(capacity * sizeof(Complex)); // Allocate memory for the array based on capacity
    return stack;
}

int isEmpty(Stack* stack)
{
    return (stack->top == -1);
}

void push(Stack* stack, Complex data)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = data;
}

Complex pop(Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("Error: Stack is empty.\n");
        // Return some default value or handle the error appropriately in your use case
        Complex defaultComplex = { 0, 0 };
        return defaultComplex;
    }

    return stack->array[stack->top--];
}

void printComplexArray(Complex* stack, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d + %di \n", stack[i].real, stack[i].imag);
    }
}

int main()
{
    int size = 4;
    Stack* S1 = createStack(4);
    Complex ComplexArray[4] = {
        {1, 1}, {2, 5}, {4, 4}, {6, 9}
    };
    
    for (int i = 0; i < size; i++)
    {
        push(S1, ComplexArray[i]);
    }

    printComplexArray(ComplexArray, size);
    
    Complex popped1 = pop(S1);
    
    Complex popped2 = pop(S1);
    

    printf("Popped complex number 1: %d + %di\n", popped1.real, popped1.imag);
    printf("Popped complex number 2: %d + %di\n", popped2.real, popped2.imag);

    
    printComplexArray(ComplexArray, size-2);

    return 0;
}
