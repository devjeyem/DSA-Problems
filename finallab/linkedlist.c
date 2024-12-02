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

SLL createSLL()
{
   SLL x = (SLL)malloc(sizeof(struct sll));
   if(x!=NULL)
   {
        x->head = NULL;
        x->size = 0;
   }
   return x;
}

void SLL_display(SLL sll)
{
    if (sll->size > 0)
    {
        SNODE p = sll->head;
        while (p!= NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
    else 
    {
        printf("List is empty");
    }
}


void SLL_addLast(SLL sll, Item data)
{
    SNODE newNode = (SNODE)malloc(sizeof(struct snode));
    newNode->data = data;
    newNode->next = NULL;

    SNODE p = sll->head;
    if(p==NULL)
    {
        sll->head = newNode;
    }
    else
    {
        while (p->next!=NULL)
        {
            p = p->next;
        }
        p->next = newNode;
    }
    sll->size++;
}

void addFirst(SLL sll, int data)
{
    SNODE newNode = (SNODE)malloc(sizeof(struct snode));
    newNode->data = data;
    newNode->next = sll->head;

    sll->head = newNode;
    sll->size++;
}

void insertXbetweenBandC(SLL sll, int data)
{
    SNODE newNode = (SNODE)malloc(sizeof(struct snode));
    newNode->data = data;
    newNode->next = NULL;

    SNODE p = sll->head;
    while (p!=NULL)
    {
        if (p->data == 'B' && p->next != NULL && p->next->data == 'C')
        {
            newNode->next = p->next;
            p->next = newNode;
            sll->size++;
            break;
        }
        p = p->next;
    }
}

void deleteData(SLL sll, int data)
{
    SNODE p = sll->head;

    if (p->data == data)
    {
        sll->head = p->next;
        free(p);
        sll->size--;
        return;
    }

    while (p->next!=NULL)
    {
        if (p->next->data == data)
        {
            SNODE temp = p->next;
            p->next=p->next->next;
            free(temp);
            temp = NULL;
            sll->size--;
        }
        p  = p->next;
    }
}

void deleteAll(SLL sll)
{
    SNODE p = sll->head;
    if (p!=NULL)
    {
        SNODE temp = p;
        p=p->next;
        free(temp);
    }
    sll->head = NULL;
    sll->size = 0;
}


void reverseSLL(SLL sll)
{
   SNODE prev = NULL;
   SNODE current = sll->head;
   SNODE next = NULL;


   while (current!=NULL)
   {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
   }

   sll->head  = prev;
}

void SLL_deleteDuplicates(SLL list)
{
    if (list->size > 0)
    {
        SNODE p = list->head;
        while (p!=NULL)
        {
            SNODE q = p;
            while (q->next!=NULL)
            {
                if (p->data == q->next->data)
                {
                    SNODE r = q->next;
                    q->next = r->next;
                    free(r);
                    list->size --;
                }
                else 
                    q = q->next;
            }
            p=p->next;
        }
    }

}

void SLL_sortList(SLL list)
{
    if (list->size > 1)
    {
        SNODE p = list->head;
        while (p->next != NULL)
        {
            SNODE q = p->next;
            while (q!=NULL)
            {
                if (q->data > p->data)
                {
                    int temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
                else
                    q = q->next;
            }
            p = p->next;
        }
    }
}

SLL createSLLDecreasing(int n)
{
	SLL list = (SLL) malloc(sizeof(struct sll));
	list->size = n;
	if(n > 0)
	{
		SNODE p = (SNODE) malloc(sizeof(struct snode));
		p->data = 1;
		p->next = NULL;
		int limit = n+1;
		for(int i=2; i < limit; i++)
		{
			SNODE q = (SNODE) malloc(sizeof(struct snode));
			q->data = i;
			q->next = p;
			p = q;
		}
		list->head = p;
	}
	else
		list->head = NULL;
		
	return list;
}


void SLL_rotateLeft(SLL list, int n)
{
    if (list->size > 1)
    {
        int numRot = n % list->size;

        if (numRot == 0)
            return;

        SNODE newTail = list->head;
        for (int i = 1; i<numRot; i++)
            newTail = newTail->next;
        
        SNODE newHead = newTail->next;
        SNODE end = newHead;

        while (end->next!=NULL)
            end = end ->next;

        end->next = list->head;
        list->head = newHead;
        newTail->next = NULL;
    }
}


void SLL_rotateRight(SLL list, int n)
{
   if (list->size > 1)
   {
        int numRot = n%list->size;

        if (numRot == 0)
            return;

        SNODE newTail = list->head;
        for (int i = 1; i < list->size - numRot; i++)
        {
            newTail = newTail ->next;
        }

        SNODE newHead = newTail->next;
        SNODE end = newHead;

        while (end->next!=NULL)
        {
            end = end ->next;
        }

        end->next = list->head;
        list->head = newHead;
        newTail->next = NULL;
   }
}

SLL mergeList(SLL list1, SLL list2)
{
    SLL newL = (SLL)malloc(sizeof(struct sll));
    newL->size = list1->size + list2->size;
    if(list1->size > 0)
    {
        newL->head = list1->head;
        SNODE p = list1->head;
        while (p->next != NULL)
            p = p->next;
        p->next = list2->head;
    }
    else    
        newL ->head = list2->head;

   //list1->size = list2->size = 0;
    //list1->head = list2->head = NULL;
    return newL;
    
}

  



int main()
{
    SLL l = createSLL();
    SLL_addLast(l, -6);
    SLL_addLast(l, 1);
    SLL_addLast(l, 5);
    SLL_addLast(l, -6);
    SLL_addLast(l, -1);
    SLL_addLast(l, 5);
    SLL_addLast(l, -6);
    SLL_addLast(l, 1);
    SLL_addLast(l, 5);
    SLL_addLast(l, -1);
    SLL_display(l);
    //SLL_deleteDuplicates(l);
    //reverseSLL(l);
    //deleteData(l,5);



    SLL_sortList(l);
    SLL_display(l);
    SLL_rotateLeft(l, 2);
    SLL_display(l);
    SLL_rotateRight(l,2);
    SLL_display(l);

    SLL l2 = createSLL();
    SLL_addLast(l2, -6);
    SLL_addLast(l2, 1);
    SLL_addLast(l2, 5);
    SLL_addLast(l2, -6);
    SLL_addLast(l2, -1);
    SLL_addLast(l2, 5);
    SLL_addLast(l2, -6);
    SLL_addLast(l2, 1);
    SLL_addLast(l2, 5);
    SLL_addLast(l2, -1);
    SLL_display(l2);

    mergeList(l,l2);
    SLL_display(l);
}