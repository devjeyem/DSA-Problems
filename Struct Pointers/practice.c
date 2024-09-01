/*#include <stdio.h>

struct student
{
    char *name;
};

void main()
{
    struct student s[2], r[2];
    s[1] = s[0] = "alan";
    printf("%s%s", s[0].name, s[1].name);
}*/

#include <stdio.h>

struct student
{
    char *name;
};

int main()  // Use int main() as the standard return type
{
    struct student s[2];

    s[0].name = "alan";
    s[1].name = "alan";

    printf("%s%s\n", s[0].name, s[1].name);

    return 0;  // Return 0 to indicate successful completion
}
