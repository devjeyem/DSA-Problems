#include <stdio.h>
#include <stdlib.h>

typedef char Item;

typedef struct snode
{
    Item  data;
    struct snode* next;
}*SNODE;

void countHead(SNODE head)
{
    int count = 0;
    SNODE ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    printf("\n%d", count);
}

int main()
{
    SNODE head = NULL;
    head = (SNODE) malloc(sizeof(struct snode));
    head->data = 'A';
    head->next = (SNODE) malloc(sizeof(struct snode));
    head->next->data = 'B';
    head->next->next = (SNODE) malloc(sizeof(struct snode));
    head->next->next->data = 'C';
    head->next->next->next = NULL;

    SNODE p = head;
    while (p!=NULL)
    {
        printf("%c->", p->data);
        p = p->next;
    }

}