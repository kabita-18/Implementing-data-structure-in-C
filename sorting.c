#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Selection Sort

void Selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = 0; j < n - 2; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

// Insertion sort
void Insertionsort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {

        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(&arr[j - 1], &arr[j]);
            j--;
        }
    }
}
// bubble sort
void bubblesort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
            else
            {
                continue;
            }
        }
    }
}

int main()
{
    int arr[5] = {23, 56, 1, 8, 29};

    bubblesort(arr, 5);

    printf("Sorted Array using BubbleSort:");
    for (int i = 0; i < 5; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    Insertionsort(arr, 5);

    printf("Sorted Array using InsertionSort:");
    for (int i = 0; i < 5; i++)
    {
        printf("%d  ", arr[i]);
    }

    printf("\n");

    Selectionsort(arr, 5);

    printf("Sorted Array using SelectionSort:");
    for (int i = 0; i < 5; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}