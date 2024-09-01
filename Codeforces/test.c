#include <stdio.h>
#include <stdlib.h>

void stringLateral();
void arr1();
void doublePointer();
void problem8();
void problem9();

int main() 
{
    stringLateral();
   arr1();
   //doublePointer();
   //problem8();
   //problem9();
}

void stringLateral()
{
    char *s = "algorithms";
   char *p = s+4;
   printf("%c\n", *(p+3));
   printf("%c\n", s[4]);
}

void arr1()
{
    int  arr[6] = {1, 3, 2, 7, 4, 9};
    int *p = arr+6;
    printf("%d\n", (--p)[0]); // 9
    printf("%d\n", ++p[-1]); 
    printf("%d\n", (++p)[-2]);
    printf("%d\n", --p[-2]); 
    printf("%d\n", (--p)[-4]);

}

void doublePointer()
{
    int **p = malloc(sizeof(int*)*3);
    p[0] = malloc(sizeof(int)*3);
    p[1] = malloc(sizeof(int)*2);
    p[2] = malloc(sizeof(int));
    
}

void problem8()
{
    char *s = "datastructures";
    char *p = s;
    printf("%c\n", *(p+5));
    printf("%c\n", s[1]);
    
}

void problem9()
{
    int  arr[6] = {1, 3, 2, 7, 4};
    int *p = arr+3;
    printf("%d\n", (++p)[0]);
    printf("%d\n", p[-2]);
   
}