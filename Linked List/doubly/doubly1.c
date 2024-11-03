#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Element;

typedef struct dnode {
	Element data;
	struct dnode *prev, *next;
} *DNODE;

typedef struct dll
{
	DNODE head, tail;
	int size;
} *DLL;

void printDLL(DLL dll)
{
	DNODE p = dll->head;
	while(p != NULL){
		printf("%d->", p->data);
		p = p->next;
	}
	printf("\n");

	p = dll->tail;
	while(p != NULL){
		printf("%d->", p->data);
		p = p->prev;
	}
	printf("\n");
}

typedef struct cnode{
	Element data;
	struct cnode *next;
} *CNODE;

typedef struct cll{
	CNODE head;
	int size;
} *CLL;

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

DLL createDLL()
{
	DLL d = (DLL) malloc(sizeof(struct dll));
	d->head = d->tail = NULL;
	d->size = 0;
	return d;
}

void DLL_addFirst(DLL dll, Element data)
{
	if(dll->size == 0)
	{
		dll->head = dll->tail = (DNODE) malloc(sizeof(struct dnode));
		dll->head->prev = dll->head->next = NULL;
		dll->head->data = data;
	}
	else
	{
		DNODE d = (DNODE) malloc(sizeof(struct dnode));
		d->data = data;
		d->next = dll->head;
		d->prev = NULL;
		dll->head->prev = d;
		dll->head = d;
	}
	dll->size++;
}

void DLL_addLast(DLL dll, Element data)
{
	if(dll->size == 0)
	{
		dll->head = dll->tail = (DNODE) malloc(sizeof(struct dnode));
		dll->head->prev = dll->head->next = NULL;
		dll->head->data = data;
	}
	else
	{
		DNODE d = (DNODE) malloc(sizeof(struct dnode));
		d->data = data;
		d->prev = dll->tail;
		d->next = NULL;
		dll->tail->next = d;
		dll->tail = d;
	}
	dll->size++;
}

CLL createCLL()
{
	CLL c = (CLL) malloc(sizeof(struct cll));
	c->head = NULL;
	c->size = 0;
	return c;
}

void CLL_addFirst(CLL cll, Element data)
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
		cll->head = c;
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

DLL DLL_removeDuplicates(DLL list)
{
	if (list == NULL || list->size<=1)
	{
	    return list;
	}
	bool flag[10000] = {0};
	
	DNODE current = list->head;
	while (current!=NULL)
	{
	    int data = current->data;
	    DNODE nextNode = current->next;
	    if (flag[data+5000])
	    {
	        if (current->prev)
	        {
	            current->prev->next = current->next;
	        }
	        else
	        {
	            list->head = current->next;
	        }
	        if(current->next)
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
	    current = nextNode;
	}
	return list;
}

int main()
{
	DLL dll = createDLL();

	//6-2-6-3-7-6-6-5-6
	//0-6-0-2-0-6-0-3-7-0-6-0-0-6-0-5-0-6-0

	DLL_addLast(dll, 6);
	DLL_addLast(dll, 2);
	DLL_addLast(dll, 6);
	DLL_addLast(dll, 3);
	DLL_addLast(dll, 7);
	DLL_addLast(dll, 6);
	DLL_addLast(dll, 6);
	DLL_addLast(dll, 5);
	DLL_addLast(dll, 6);
    //DLL_addFirst(dll,100);

	printDLL(dll);
	printf("Size: %d\n", dll->size);

	addZeroBeforeAndAfterX(dll, 6);

	printf("----------\n");
	printDLL(dll);
	printf("Size: %d\n", dll->size);

	return 0;
}
