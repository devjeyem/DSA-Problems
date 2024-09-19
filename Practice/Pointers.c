#include <stdio.h> 
struct student
{
    int num; //8
    double x; //32
    char c; //48
};
int main() 
{ 
   /* char ch = 10;
    void *ptr = &ch ; 
    printf("%d\n", *(char*)ptr);
    printf("%d",++(*(char*) ptr)); 
    return 0; //10 ,11 */

    /*char ch = 10;
    void *ptr = &ch ; 
    printf("%d,%d", *(char*)ptr,++(*(char*) ptr)); 
    return 0; 11,11*/

  
    struct student s[2]; 
    printf("%d", sizeof(s));
}
