#include<stdio.h>

struct complex{
    int real;
    int imag;
} complex;

void printComplexArray( struct complex* Array,int size){
    for(int i =0; i<size; i++){
        printf("%d + %di \n", Array[i].real, Array[i].imag);
    }
}
// find first complex number whose real part is equal to imaginary part in array in c

void firstComplexNumberEqual(struct complex* Array, int size){
    int count = 0;
    for(int i =0; i<size; i++){
        if(Array[i].real == Array[i].imag){
            //printf("Complex number whose real part is equal to its imaginary part: %d + %di\n", Array[i].real, Array[i].imag);
            count++;
            //return;
        }
        // else{
        //     count++;
        // }
        
    }
    // printf("No complex number with real part equal to imaginary part found.\n");
    printf("%d", count);

}

int main(){
    
    int size=4;
    //scanf("%d", &size);
    struct complex Array[size];
    for(int i =0; i<size; i++){
        printf("Complex Number %d\n", i+1);
        scanf("%d", &Array[i].real);
        scanf("%d", &Array[i].imag);
    }
    printf("Complex Array: ");
    printComplexArray(Array, size);
    firstComplexNumberEqual(Array, size);
}