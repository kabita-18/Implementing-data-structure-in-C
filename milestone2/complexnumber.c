#include <stdio.h>

typedef struct  Complex
{
    int real;
    float imag;
} c1;

void add_complex(c1 complex1, c1 complex2, c1 *result){
    result->real = complex1.real + complex2.real;
    result->imag = complex1.imag + complex2.imag;

//     printf("\nresult.real = %d\n", result->real);
//     printf("result.imag = %.1f i", result->imag);

    printf("\n add of complex number is: %d + %.1f i", result->real, result->imag );
}

int main(){
    c1 Complex1;
    c1 Complex2;
    c1 result;

    printf("Enter first real and imaginary number");
    scanf("%d", &Complex1.real);
    scanf("%f", &Complex1.imag);

    printf("Enter second real and imaginary number");
    scanf("%d", &Complex2.real);
    scanf("%f", &Complex2.imag);

    add_complex(Complex1, Complex2, &result);

}
