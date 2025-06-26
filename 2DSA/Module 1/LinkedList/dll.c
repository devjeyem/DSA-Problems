#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int Element;

typedef struct dnode
{
    struct dnode* prev;
    Element data;
    struct dnode* next;
}*DNODE;

typedef struct dll
{
    DNODE head,tail;
    int size;
}*DLL;

void printDLL(DLL dll)
{
    DNODE p = dll->head;
    while (p!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    printf("\n");

    p=dll->tail;
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->prev;
    }
    printf("\n");
}

DLL createDLL()
{
    DLL d=(DLL)malloc(sizeof(struct dll));
    d->head = d->tail = NULL;
    d->size = 0;
    return d;
}

void DLL_addLast(DLL dll, Element data)
{
    if (dll->size == 0)
    {
        dll->head = dll->tail = (DNODE)malloc(sizeof(struct dll))
        dll->head->prev = dll->head->next = NULL;
        dll->head->data = data;
    }
    else
    {
        DNODE newNode - (DNODE)malloc(sizeof(struct dnode))
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = dll->tail;
        dll->tail->next = newNode;
        dll->tail = newNode;         
    }
}

void DLL_addFirst(DLL dll, Element data)
{
    if (dll->size == 0)
    {
        dll->head = dll->tail = (DNODE)malloc(sizeof(struct dnode));
        dll->head->prev = dll->head->next = NULL;
        dll->head->data = data;
    }
    else
    {
        DNODE newNode = (DNODE)malloc(sizeof(struct dnode));
        newNode->data = data;
        newNode->next = dll->head;
        newNode->prev = NULL;
        dll->head->prev = newNode;
        dll->head = newNode;
    }
    dll->size++;
}


DLL DLL_removeDuplicates(DLL list)
{
    if (list == NULL || list->size == 0) return list;

    bool flag[10000] = {0};
    DNODE current = list->head;
    while(current!=NULL)
    {
        Element data = current->data;
        if (flag[data+5000])
        {
            if(current->prev)
            {
                current->prev->next = current->next;

            }
            else
            {
                list->head = current->next;
            }
            if (current->next)
            {
                current->next->prev = current->prev;
            }
            else 
            {
                list->tail = current->prev;
            }
            free(current);
            list->size--;
        }
        else
        {
            flag[data+5000] = true;
        }
        current = current->next;
    }
}



int main()
{
    /*DNODE head = (DNODE)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data=10;
    head->next=NULL;*/
        DLL dll = createDLL();

        DLL_addLast(dll, 6);
        DLL_addLast(dll, 2);
        DLL_addLast(dll, 6);
        DLL_addLast(dll, 3);
        DLL_addLast(dll, 7);
        DLL_addLast(dll, 6);
        DLL_addLast(dll, 6);
        DLL_addLast(dll, 5);
        DLL_addLast(dll, 6);
    DLL_addFirst(dll, 1);

    printDLL(dll);

    DLL_removeDuplicates(dll);
    printDLL(dll);

    printf("=======================\n");

    DLL_deleteThreeMaxOccurrenceOfY(dll,6);
    printDLL(dll);






}
