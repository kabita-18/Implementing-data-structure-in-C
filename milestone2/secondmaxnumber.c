#include <stdio.h>
int secondMax(int *Array, int size){
    if(size < 2){
        return -1;
    }
    int firstMaximum, secondMaximum;
    firstMaximum = secondMaximum = Array[0];
    

    for(int i =1; i< size; i++){
        if(Array[i] > firstMaximum){
            secondMaximum = firstMaximum;
            firstMaximum = Array[i];
        }
        else if(Array[i] > secondMaximum && Array[i] != firstMaximum){
            secondMaximum = Array[i];
        }
        
    }
    return secondMaximum;
}

int main(){
    int Array[] ={ 2, 56, 0, 25, 1, 789,49};
    int size= sizeof(Array)/sizeof(Array[0]);
    int* Arr = Array;

    int result = secondMax(Arr, size);
    printf("second maximum number is %d:", result);     
}