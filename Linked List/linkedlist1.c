#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct snode
{
    Item data;
    struct snode *next;
}*SNODE;

void countOfNodes(SNODE head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("EMPTY");
    }
    SNODE ptr = head;
    while (ptr!=NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("%d", count);
}

void printData(SNODE head)
{
    SNODE p = head;
    while(p!=NULL)
    {
        printf("%d->", p->data);
        p = p ->next;
    }
}

void addAtEnd(SNODE head, int data)
{
    SNODE ptr, temp;
    ptr = head;
    temp =  (SNODE)malloc(sizeof(struct snode));
    temp->data = data;
    temp->next = NULL;
    while (ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next =  temp;
}

int main()
{
    SNODE head = NULL;
    head = (SNODE)malloc(sizeof(struct snode));

    head->data = 45;
    head->next = (SNODE)malloc(sizeof(struct snode));
    head->next->data= 98;
    head->next->next = (SNODE)malloc(sizeof(struct snode));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    SNODE p = head;
    printData(p);
    addAtEnd(head, 100);
    //p = head;
    printData(p);
   
}


