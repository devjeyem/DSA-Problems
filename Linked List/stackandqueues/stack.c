#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef int Element;

typedef struct _stack
{
    Element* storage;
    int top;
    int capacity;
}*STACK_ARR;

STACK_ARR createStack(int capacity)
{
    STACK_ARR st = (STACK_ARR)malloc(sizeof(struct _stack));
    st->top = 0;
    st->capacity = capacity;
    st->storage = (Element*)malloc(sizeof(Element)*capacity);
    for(int i = 0; i<capacity; i++)
    {
        st->storage[i] = 0;
    }
    return st;
}

int isFull(STACK_ARR stack)
{
    return stack->top == stack->capacity;
}

int isEmpty(STACK_ARR stack)
{
    return stack->top == 0;
}

void push(STACK_ARR stack, Element data)
{
    if(!isFull(stack))
        stack->storage[stack->top++] = data;
}

Element pop(STACK_ARR stack)
{
    return (isEmpty(stack)) ? -1 : stack->storage[--(stack->top)];
}

Element peek(STACK_ARR stack)
{
    return (isEmpty(stack)) ? -1 : stack->storage[stack->top - 1];
}

STACK_ARR reverseStack(STACK_ARR original) 
{
    STACK_ARR reversed = createStack(original->capacity);
    STACK_ARR temp = createStack(original->capacity);

    while (!isEmpty(original)) 
    {
        push(temp, pop(original));
    }

    while (!isEmpty(temp)) 
    {
        push(reversed, pop(temp));
    }

    free(temp->storage);
    free(temp);

    return reversed;
}

int isMatchingPair(char open, char close) 
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isValidParentheses(const char* str) 
{
    int n = strlen(str);
    STACK_ARR stack = createStack(n);

    for (int i = 0; i < n; i++) 
    {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') 
        {
            // Push opening brackets
            push(stack, ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') 
        {
            // Check if the stack is empty or does not match
            if (isEmpty(stack) || !isMatchingPair(pop(stack), ch)) 
            {
                free(stack->storage);
                free(stack);
                return 0; // Invalid
            }
        }
    }

    // Check if the stack is empty after processing
    int result = isEmpty(stack);
    free(stack->storage);
    free(stack);
    return result;
}


int main() 
{
char *str = "823^/23*+51*-";
    STACK_ARR val = createStack(100);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            push(val,str[i] - '0');
        else
        {
            Element r = pop(val);
            Element l = pop(val);
            switch(str[i])
            {
                case '+' : push(val, l+r); break;
                case '-' : push(val, l-r); break;
                case '*' : push(val, l*r); break;
                case '/' : push(val, l/r); break;
                case '^' : push(val, (int)pow(l,r)); break;
                case '%' : push(val, l%r); break;
            }
        }
    }
    printf("Answer: %d",pop(val));
    
    const char* test1 = "(){}[]";
    const char* test2 = "({[()]})";
    const char* test3 = "(]";
    const char* test4 = "({[)}";

    printf("Test 1: %s -> %s\n", test1, isValidParentheses(test1) ? "Valid" : "Invalid");
    printf("Test 2: %s -> %s\n", test2, isValidParentheses(test2) ? "Valid" : "Invalid");
    printf("Test 3: %s -> %s\n", test3, isValidParentheses(test3) ? "Valid" : "Invalid");
    printf("Test 4: %s -> %s\n", test4, isValidParentheses(test4) ? "Valid" : "Invalid");
}


