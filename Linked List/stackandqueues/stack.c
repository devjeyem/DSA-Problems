#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

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
    for(int i = 0; i < capacity; i++)
    st->storage[i] = 0;
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
    if (!isFull(stack))
    stack->storage[stack->top++] = data;
}

Element pop(STACK_ARR stack)
{
    return (isEmpty(stack)) ? -1 : stack->storage[--(stack->top)];
}

STACK_ARR reverseStack(STACK_ARR original) 
{
    STACK_ARR reversed = createStack(original->capacity);
    STACK_ARR temp = createStack(original->capacity);

    while (!isEmpty(original)) {
    push(temp, pop(original));
    }

    while (!isEmpty(temp)) {
    push(reversed, pop(temp));
    }

    free(temp->storage);
    free(temp);

    return reversed;
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
    return 0;
}


