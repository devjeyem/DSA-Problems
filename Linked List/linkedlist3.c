#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct snode
{
    Item data;
    struct snode *next;
}*SNODE;

typedef struct sll
{
    SNODE head;
    int size;
}*SLL;

SLL createList()
{
    SLL x = (SLL)malloc(sizeof(struct sll));
    if(x!=NULL)
    {
        x->head = NULL;
        x->size = 0;
    }
    return x;
}

void printSLL(SLL sll)
{
    if(sll->size>0)
    {
        SNODE p = sll->head;
        while (p!=NULL)
        {
            printf("%d->",p->data);
            p = p->next; 
        }
    }
}

void addAtEnd(SLL sll, Item data)
{
    SNODE p = sll->head;
    if (p == NULL)
    {
        sll->head = (SNODE)malloc(sizeof(struct snode));
        sll->head->data =  data;
        sll->head->next = NULL;
    }
    else
    {
        while (p->next != NULL)
        {
            p= p->next;
        }
        p->next = (SNODE)malloc(sizeof(struct snode));
        p->next->data =  data;
        p->next->next = NULL;
    }
    sll->size++;
}

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

int main()
{
    //SNODE head = NULL;

    SLL list = createList();

    addAtEnd(list,45);
    addAtEnd(list,98);
    addAtEnd(list,3);
    addAtEnd(list,100);

    printSLL(list);


    /*list->head = (SNODE)malloc(sizeof(struct node));
    list->head->data = 45;
    list->head->next = (SNODE)malloc(sizeof(struct node));
    list->head->next->data= 98;
    list->head->next->next = (SNODE)malloc(sizeof(struct node));
    list->head->next->next->data = 3;
    list->head->next->next->next = NULL;*/

    //SNODE p = list->head;
    /*while(p!=NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }*/
    //printSLL(list);
    printf("\n");
    //countOfNodes(head);
    

}


