#include <stdio.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

int main() {
    char username[101];
    bool present[ALPHABET_SIZE] = {false};
    int distinct_count = 0;
    
    // Read the username
    scanf("%s", username);
    
    // Count distinct characters
    for (int i = 0; username[i] != '\0'; i++) 
    {
        int index = username[i] - 'a';  // Convert character to index (0-25)
        if (!present[index]) 
        {
            present[index] = true;
            distinct_count++;
        }
    }
    
    // Determine the gender based on the number of distinct characters
    if (distinct_count % 2 == 0) 
    {
        printf("CHAT WITH HER!\n");
    } 
    else 
    {
        printf("IGNORE HIM!\n");
    }
    
    return 0;
}
