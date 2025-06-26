#include <stdio.h>
#include <stdlib.h>

void ex1();
void ex2();
void ex3();
void ex4();

int main() 
{
    //ex2();
    //ex3();
    ex4();
}

void ex1()
{
    char data1 = 'X';
    int data2 = 100;
    float data3 = 3.14f;

    void *ptr;

    ptr = &data1;
    printf("data1 = %c\n", *(char*)ptr);

    // Print data2
    ptr = &data2;
    printf("data2 = %d\n", *(int*)ptr);

    // Print data3
    ptr = &data3;
    printf("data3 = %.2f\n", *(float*)ptr);
}

void ex2()
{
        // Step 1: Allocate memory for int, char, and double
    int *a = (int *)malloc(sizeof(int));
    char *b = (char *)malloc(sizeof(char));
    double *c = (double *)malloc(sizeof(double));

    // Step 3: Display the size of memory each pointer points to
    printf("Size of memory referenced by a (int): %zu bytes\n", sizeof(*a));
    printf("Size of memory referenced by b (char): %zu bytes\n", sizeof(*b));
    printf("Size of memory referenced by c (double): %zu bytes\n", sizeof(*c));

    // Optional: Free the allocated memory
    free(a);
    free(b);
    free(c);
}

void ex3()
{

    int *data1 = (int *)malloc(sizeof(int));
    int *data2 = (int *)malloc(sizeof(int));
    int *data3 = (int *)malloc(sizeof(int));
    *data1 = 3;
    *data2 = 5;
    *data3 = 10;

    float *avg = (float *)malloc(sizeof(float));
    
    // Step 4: Compute the average
    *avg = (*data1 + *data2 + *data3) / 3.0f;

    // Step 5: Display the result
    printf("Average: %.2f\n", *avg);

}

void ex4()
{

    int *data1 = (int *)malloc(sizeof(int));
    int *data2 = (int *)malloc(sizeof(int));

    *data1 = 8;   // example value
    *data2 = 4;   // example value

    // TODO: Average and merge data1 and data2 values
    *data1 = (*data1 + *data2) / 2;

    free(data2);  // deallocate data2

    printf("Average stored in data1: %d\n", *data1);

    free(data1);  // optional cleanup


}