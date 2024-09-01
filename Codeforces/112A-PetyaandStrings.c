#include <stdio.h>
#include <ctype.h>

int main() {
    char str1[101], str2[101];

    // Read the two strings
    scanf("%s", str1);
    scanf("%s", str2);

    // Compare the strings lexicographically while ignoring case
    for (int i = 0; str1[i] != '\0'; i++) 
    {
        // Convert both characters to lowercase for comparison
        char c1 = tolower(str1[i]);
        char c2 = tolower(str2[i]);

        // If the characters are different, return the result
        if (c1 != c2) 
        {
            printf("%d\n", (c1 < c2) ? -1 : 1);
            return 0;
        }
    }

    // If the loop completes without finding a difference, the strings are equal
    printf("0\n");
    return 0;
}