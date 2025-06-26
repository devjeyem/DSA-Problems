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

void addZeroBeforeAndAfterX(DLL dll, int x)
{
	DNODE p = dll->head;

	if(p->data == x && p->next != NULL)
	{
		DNODE d = (DNODE)malloc(sizeof(struct dnode));
		d->data = 0;
		d->prev = NULL;
		d->next = p;

		dll->head = d;
		p->prev = d;

		d = (DNODE) malloc(sizeof(struct dnode));
		d->data = 0;
		d->prev = p;
		d->next = p->next;

		p->next->prev = d;
		p->next = d;

		p = p->next->next;
		dll->size+=2;
	}

	while(p->next != NULL)
	{
		if(p->data == x)
		{
			DNODE d = (DNODE) malloc(sizeof(struct dnode));
			d->data = 0;
			d->prev = p->prev;
			d->next = p;

			p->prev->next = d;
			p->prev = d;

			d = (DNODE) malloc(sizeof(struct dnode));
			d->data = 0;
			d->prev = p;
			d->next = p->next;

			p->next->prev = d;
			p->next = d;

			dll->size +=2;
			p = p->next->next;
		}
		else
			p = p->next;
	}

	//insert to tail
	if(p->data == x)
	{
		DNODE d = (DNODE)malloc(sizeof(struct dnode));
		d->data = 0;
		d->prev = p->prev;
		d->next = p;

		p->prev->next = d;
		p->prev = d;

		d = (DNODE)malloc(sizeof(struct dnode));
		d->data = 0;
		d->prev = p;
		d->next = p->next;

		p->next = d;

		dll->tail = d;

		dll->size += 2;
		p = p->next->next;
	}

}

void DLL_rotateRight(DLL list, int n)
{
    if (list->size > 0)
    {
        
    }
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
        DNODE newNode = (DNODE)malloc(sizeof(struct dnode));
        newNode->data = data;
        newNode->next= NULL;
        newNode->prev = dll->tail;
        dll->tail->next = newNode;
        dll->tail = newNode;
    }
    dll->size++;
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

void DLL_deleteThreeMaxOccurrenceOfY(DLL list, int y)
{
    if (list == NULL || list->size == 0) return;

    int ctr = 0;

    DNODE current = list->tail;
    while(current!=NULL && ctr < 3)
    {
        if (current->data == y)
        {
            DNODE temp = current;
            if (current->prev)
            {
                current->prev->next = current->next;
            }
            else
            {
                list->head  = current->next;
            }

            if (current->next)
            {
                current->next->prev = current->prev;
            }
            else
            {
                list->tail = current->prev;
            }
            current = current ->prev;
            free(temp);
            list->size--;
            ctr++;
        }
        else
        {
            current = current->prev;
        }
    }
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



// =====================================================================

typedef struct cnode
{
        Element data;
        struct cnode *next;
} *CNODE;

typedef struct cll
{
        CNODE tail,head;
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

void CLL_deleteTail(CLL list)
{
    if(list->size == 1)
    {
        free(list->tail);
        list->tail = NULL;
        list->size--;
    }
	else if(list->size > 0)
	{
	    CNODE p = list->tail;
	    while(p->next != list->tail)
	        p = p->next;
	    CNODE d = list->tail;
	    p->next = d->next;
	    free(d);
	    list->tail = p;
	    list->size--;
	}
}

void CLL_addFirst(CLL cll, Element data)
{
    if(cll->size == 0)
    {
        cll->head = (CNODE)malloc(sizeof(struct cnode));
        cll->head->next = cll->head;
        cll->head->data = data;
    }
    else
    {
        CNODE newNode =  (CNODE)malloc(sizeof(struct cnode));
        newNode->data = data;
        CNODE p = cll->head;
        while (p->next != cll->head)
        {
            p = p->next;
        }
        newNode->next = cll->head;
        p->next = newNode;
        cll->head = newNode;
    }
    cll->size++;
}



void CLL_addLast(CLL cll, Element data)
{
	if(cll->size == 0)
	{
		cll->head = (CNODE) malloc(sizeof(struct cnode));
		cll->head->next = cll->head;
		cll->head->data = data;
	}
	else
	{
		CNODE c = (CNODE) malloc(sizeof(struct cnode));
		c->data = data;
		CNODE p = cll->head;
		while(p->next != cll->head)
			p = p->next;

		c->next = cll->head;
		p->next = c;
	}
	cll->size++;
}

void CLL_rotateRight(CLL l, int n) 
{
    if (l == NULL || l->tail == NULL ||l->size<=1||n<=0)
        return;
    n = n % l->size;

    if (n == 0)
        return;

    CNODE newTail = l->tail;
    for (int i = 1; i < l->size-n ; i++)
        newTail = newTail -> next;

    l->tail = newTail;    
}

void CLL_rotateLeft(CLL l, int n) 
{
    if (l == NULL || l->tail == NULL || n <= 0 || l->size <= 1) 
    {
        return; // No rotation needed if list is empty, single-element, or no effective rotations
    }

    // Step 1: Calculate effective rotations
    n = n % l->size;
    if (n == 0) 
    {
        return; // No rotation needed if n is a multiple of the list's size
    }

    // Step 2: Find the new tail position
    CNODE newTail = l->tail;

    // Traverse `n` times to find the new tail (n steps from current tail)
    for (int i = 0; i < n; i++) {
        newTail = newTail->next;
    }

    // Step 3: Update the tail
    l->tail = newTail;
}

CLL createCLLHex(int n) {
    // Step 1: Create the circular linked list structure in the heapCNw
        CLL list = (CLL)malloc(sizeof(struct cll));
        list->head = NULL;
        list->size = 0;
    // Edge case: If n is 0, add a single node with '0' and return
    if (n == 0) {
        CNODE newNode = (CNODE)malloc(sizeof(struct cnode));
        newNode->data = '0';
        newNode->next = newNode;  // Point to itself, making it circular
        list->head = newNode;
        list->size = 1;
        return list;
    }

    // Step 2: Convert n to hexadecimal and add each digit to the list in correct order
    CNODE tail = NULL;  // Track the last node to form the circular link

    // Temporary array to store hex digits
    char hexDigits[16];
    int digitCount = 0;

    while (n > 0) {
        int hexDigit = n % 16;
        hexDigits[digitCount++] = (hexDigit < 10) ? '0' + hexDigit : 'A' + (hexDigit - 10);
        n /= 16;
    }

    // Step 3: Add each digit from the array to the list (from most significant to least significant)
    for (int i = digitCount - 1; i >= 0; i--) {
        CNODE newNode = (CNODE)malloc(sizeof(struct cnode));
        newNode->data = hexDigits[i];

        if (list->head == NULL) {
            //A
            list->head = newNode;
            newNode->next = newNode;  // Point to itself initially
        } else {
            // Insert at the end and make it circular
            newNode->next = list->head;
            tail->next = newNode;
        }

        tail = newNode;  // Update tail to the new node
        list->size++;
    }

    // Step 4: Make sure the last node links back to the head to complete the circular structure
    if (tail != NULL) {
        tail->next = list->head;
    }

    return list;
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
