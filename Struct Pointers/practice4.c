#include<stdio.h>

struct student
{
    char *name;
}s;

struct student fun (void)
{
    
    //s.name = "Newton";
    printf("%s\n", s.name);
    s.name = "alan";
    return s;

}

void main()
{
    struct student m = fun();
    //s.name = "turing";
   // printf("%s", m.name);
    //m.name = "turing";
    printf ("%s", s.name);

}