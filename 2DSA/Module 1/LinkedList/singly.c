#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct snode
{
    Item data;
    struct snode  *next;
}*SNODE;

typedef struct sll
{
    SNODE head;
    int  size;
}*SLL;

SLL createList()
{
    SLL list = (SLL)malloc(sizeof(struct sll));
    if (list!=NULL)
    {
        list->head = NULL;
        list->size = 0;
    }
    return list;
}

void printSLL(SLL sll)
{
    if (sll->size>0)
    {
        SNODE p = sll->head;
        while (p!=NULL)
        {
            printf("%d -> ", p->data);
            p = p->next;
        }
        printf("\n");
    }
    else
    {
        printf("List is empty\n");
    }
}

void addLast(SLL sll, Item data)
{
    SNODE newNode = (SNODE)malloc(sizeof (struct snode));
    newNode->data = data;
    newNode->next = NULL;

    SNODE p = sll->head;

    if (p == NULL)
    {
        sll->head = newNode;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newNode;
    }
    sll->size++;
}

void addFirst(SLL sll, Item data)
{
    SNODE newNode = (SNODE)malloc(sizeof(struct snode));
    newNode->data = data;
    newNode->next = NULL;

    SNODE p = sll->head;
    if (p == NULL)
    {
        sll->head = newNode;
    }
    else
    {
        newNode->next = p;
        sll->head = newNode;
    }
    sll->size++;
}

void insertDatabetween7and8(SLL sll, int data)
{
    SNODE newNode = (SNODE)malloc(sizeof(struct snode));
    newNode->data = data;
    newNode->next = NULL;

    SNODE p = sll->head;
    while (p!=NULL)
    {
        if (p->data == 7 && p->next != NULL && p->next->data == 8)
        {
            newNode->next = p->next;
            p->next = newNode;
            sll->size++;
            break ;
        }
        p=p->next;
    }
}

void deleteData(SLL sll, int data)
{
    SNODE p = sll->head;
    if (p->data == data)
    {
        sll->head = p->next; //NULL
        free(p);
        sll->size--;
        return;
    }
    while (p->next!=NULL)
    {
        if (p->next->data == data)
        {
            SNODE temp = p->next;
            p->next = p->next->next;
            free(temp);
            temp = NULL;
            sll->size--;
        }
        p = p->next;
    }
}

void reverseSLL(SLL sll)
{
     SNODE prev = NULL;
     SNODE current = sll->head;
     SNODE next = NULL;

     while (current != NULL)
     {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
     }
     sll->head = prev;
}

int main()
{
    SLL list = createList();
    addLast(list,1);
    addLast(list,2);
    addLast(list,3);
    addLast(list,4);
    addLast(list,5);
    addLast(list,6);
    addLast(list,7);
    addLast(list,8);
    addFirst(list,51);
    insertDatabetween7and8(list,9);
    printSLL(list);
        reverseSLL(list);
    printSLL(list);
    //printf("%d", SLL_checkPairs(list));


   /* addFirst(list,'Z');
    printSLL(list);
    insertXbetweenBandC(list,'X');
    printSLL(list);
    deleteData(list,'X');
    printSLL(list);
    //deleteAll(list);
    //printSLL(list);
    reverseSLL(list);
    printSLL(list);*/

}