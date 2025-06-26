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
    if (sll->size>0)
    {
        SNODE p = sll->head;
        while (p!=NULL)
        {
            printf("%c->",p->data);
            p = p->next; 
        }  
        printf("\n");
    }
    else{
        printf("List is empty\n");
    }
}

void addLast(SLL sll, Item data)
{
    SNODE p = sll->head;

    SNODE newNode =  (SNODE)malloc(sizeof(struct snode));
    newNode->data =  data;
    newNode->next = NULL;

    if (p == NULL)
        sll->head = newNode;
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
    SNODE newNode =  (SNODE)malloc(sizeof(struct snode));
    newNode->data = data;
    newNode->next = NULL;

    SNODE p =  sll->head;

    while (p!=NULL)
    {
        if (p->data == 'B' && p->next != NULL  && p->next->data == 'C')
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
    while (p != NULL)
    {
        SNODE temp = p;
        p = p->next; // Move to the next node
        free(temp);  // Free the current node
    }
    sll->head = NULL; // Set head to NULL after all nodes are deleted
    sll->size = 0;    // Reset size to 0
}


void reverseSLL(SLL sll)
{
    SNODE prev = NULL;
    SNODE current = sll->head;
    SNODE next = NULL;

    while (current != NULL)
    {
        next = current->next; // Save the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move prev to current
        current = next;       // Move current to next
    }
    sll->head = prev; // Set the new head of the reversed list
}

int SLL_checkPairs(SLL list)
{
    if (list->head == NULL)
        return 1;
    int max = list->head->data;
    int min = list->head->data;
    SNODE p = list->head->next;
    while(p!=NULL)
    {
        if (p->data > max)
            max = p->data;
        if (p->data < min)
            min = p->data;
        p = p->next;
    }

    int s = max - min +1;
    int ctr[s];
    for (int i = 0; i < s; i++)
        ctr[i] = 0;

    p = list->head;
    while(p!=NULL)
    {
        ctr[p->data - min]++;
        p = p->next;
    }

    for (int i = 0; i < s; i++)
    {
        if (ctr[i] %2 != 0)
            return 0;
    }
    return 1;
}

int main()
{
    SLL list = createList();
    addLast(list,'1');
    addLast(list,'2');
    addLast(list,'3');
    addLast(list,'3');
    addLast(list,'1');
    addLast(list,'2');
    printSLL(list);
    printf("%d", SLL_checkPairs(list));


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