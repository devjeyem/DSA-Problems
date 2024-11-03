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
        dll->head = dll->tail = (DNODE)malloc(sizeof(struct dnode));
        dll->head->prev = dll->head->next = NULL;
        dll->head->data = data;
    }
    else
    {
        DNODE temp =  (DNODE)malloc(sizeof(struct dnode));
        temp->data = data;
        temp->next = NULL;
        temp->prev = dll->tail;
        dll->tail->next = temp;
        dll->tail = temp;

    }
    dll->size++;
}


DLL_addFirst(DLL dll, Element data)
{
    if (dll->size == 0)
    {
        dll->head = dll->tail = (DNODE)malloc(sizeof(struct dnode));
        dll->head->prev = dll->head->next = NULL;
        dll->head->data = data;
    }
    else
    {
        DNODE temp = (DNODE)malloc(sizeof(struct dnode));
        temp->data = data;
        temp->prev = NULL;
        temp->next = dll->head;
        dll->head->prev = temp;
        dll->head = temp;
    }
    dll->size++;
}


DLL DLL_removeDuplicates(DLL list)
{
    bool flag[10000] = {0};
    if (list==NULL || list->size <= 1)
    {
        return list;
    }

    DNODE current = list->head;
    while (current!=NULL)
    {
        Element data = current->data;
        DNODE nextNode = current->next;
        if (flag[data+5000])
        { 
            if (current->prev)
            {
                current->prev->next = current->next;
            }
            else
            {
                list->head = current -> next;
            }
            if (current->next)
            {
                current->next->prev = current->prev;
            }
            else
            {
                list->tail = current-> prev;
            }
            free(current);
            list->size--;
        }
        else
        {
            flag[data+5000] = true;
        }
        current=current->next;
    }
    return list;
}
 

/*void DLL_deleteThreeMaxOccurrenceOfY(DLL list, int y) {
    if (list == NULL || list->size == 0) {
        return; // Empty list or NULL input, nothing to delete
    }
    
    int count = 0;
    DNODE current = list->tail; // Start from the tail
    
    while (current != NULL && count < 3) {
        if (current->data == y) {
            DNODE temp = current;
            
            // Adjust pointers
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                list->head = current->next; // Update head if it's the first node
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev; // Update tail if it's the last node
            }
            
            current = current->prev; // Move to the previous node
            free(temp); // Free the memory of the deleted node
            list->size--; // Decrease the size of the list
            count++; // Increment the count of deletions
        } else {
            current = current->prev; // Move to the previous node if data doesn't match
        }
    }
}*/

void DLL_deleteThreeMaxOccurrenceOfY(DLL list, int y)
{
    if(list==NULL || list->size ==0) return;
    int count = 0;

    DNODE current = list->tail;
    while (current!=NULL && count < 3)
    {
        if (current->data==y)
        {
            DNODE temp = current;
            if (current->prev)
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
            current = current->prev;
            free(temp);
            list->size--;
            count++;
        }
        else
        {
            current = current->prev;
        }
    }
}



typedef struct cnode
{
	Element data;
	struct cnode *next;
} *CNODE;

typedef struct cll
{
	CNODE head;
	int size;
} *CLL;

CLL createCLL()
{
	CLL c = (CLL) malloc(sizeof(struct cll));
	c->head = NULL;
	c->size = 0;
	return c;
}

void printCLL(CLL cll)
{
	if(cll->head != NULL)
	{
		CNODE p = cll->head;
		do
		{
			printf("%d->", p->data);
			p = p->next;
		} while(p != cll->head);
		printf("\n");
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