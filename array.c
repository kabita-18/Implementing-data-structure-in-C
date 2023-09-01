#include <stdio.h>
#include <stdlib.h>

void separate_even_odd(int arr[], int arr2[], int n) {
    int *combine_array = (int *)malloc((2 * n) * sizeof(int));

    for (int i = 0; i < n; i++) {
        combine_array[i] = arr[i];
        combine_array[n + i] = arr2[i];
    }

    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            if (combine_array[j] > combine_array[j + 1]) {
                int temp = combine_array[j];
                combine_array[j] = combine_array[j + 1];
                combine_array[j + 1] = temp;
            }
        }
    }

    int x = 0, y = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (combine_array[i] % 2 == 0) {
            arr[x++] = combine_array[i];
        } else {
            arr2[y++] = combine_array[i];
        }
    }

    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

   
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
}


    



int main() {
    int n = 3;
    int arr[3] = {67, 22, 21};
    int arr2[3] = {34, 27, 89};

    separate_even_odd(arr, arr2, n);

   
    return 0;
}
