#include <stdio.h>
#include <stdlib.h>

typedef char Item;

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
===    {
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
    
    SNODE newNode = (SNODE) malloc(sizeof(struct snode));
    newNode->data = data;
    newNode->next = NULL;
    
    if (p == NULL) 
    {
        sll->head = newNode;
    }
    else
    {
        while(p->next!=NULL) 
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
    newNode->next = sll->head;
    sll->head = newNode;
    sll->size++;
}

void insertXbetweenBandC(SLL sll, Item data)
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

void deleteData(SLL sll, Item data)
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

SLL mergeSortedLists(SLL l1, SLL l2) 
{
    SLL mergedList = createList();
    SNODE p1 = l1->head;
    SNODE p2 = l2->head;
    
    while(p1!=NULL && p2!=NULL) 
    {
        if(p1->data<=p2->data) 
        {
            addLast(mergedList,p1->data);
            p1 = p1->next;
        }
        else
        {
            addLast(mergedList,p2->data);
            p2 = p2->next;
        }
    }
    
    while (p1!=NULL) 
    {
           addLast(mergedList,p1->data);
           p1 = p1->next;
    }
    
    while (p2!=NULL) 
    {
        addLast(mergedList,p2->data);
        p2 = p2->next;
    }
   return mergedList;
}

void reverseSLL(SLL sll) 
{
    SNODE prev = NULL;
    SNODE current = sll->head;
    SNODE next = NULL;
    
    while(current!=NULL) 
    {
        next = current->next;
        current->next= prev;
        prev=current;
        current=next;
    }
    sll->head=prev;
}

void removeDuplicates(SLL sll) 
{
    SNODE current = sll->head;
    while (current!=NULL && current ->next != NULL) 
   {
         if(current->data == current->next->data) 
         {
             SNODE temp = current->next;
             current->next = current->next->next;
             free(temp);
             sll->size--;
         }
         else
             current = current->next;
    }
}

// Swap data between two nodes in the list
/*void swapData(SLL sll, Item data1, Item data2)
{
    if (data1 == data2) // No need to swap identical data
        return;

    SNODE node1 = NULL, node2 = NULL;
    SNODE temp = sll->head;

    // Traverse the list to find both nodes
    while (temp != NULL)
    {
        if (temp->data == data1)
            node1 = temp;
        else if (temp->data == data2)
            node2 = temp;
        
        temp = temp->next;
    }

    // If both nodes are found, swap their data
    if (node1 != NULL && node2 != NULL)
    {
        Item tempData = node1->data;
        node1->data = node2->data;
        node2->data = tempData;
    }
    else
    {
        printf("Swap not possible: One or both elements not found in the list.\n");
    }
}*/

void swapData(SLL sll, Item data1, Item data2) 
{
    if (data1==data2)
        return;
        
    SNODE node1 = NULL, node2 = NULL;
    SNODE temp = sll->head;
    
    while(temp!=NULL)   
    {
        if (temp->data == data1) 
            node1 = temp;
        else if (temp->data == data2)    
            node2 = temp;
        temp = temp->next;    
    } 
    
    if (node1 != NULL && node2 != NULL)   
    {
        Item temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }
}

int main()
{
    SLL list = createList();
    addLast(list,'A');
    addLast(list,'B');
    addLast(list,'C');
    printSLL(list);
    addFirst(list,'Z');
    printSLL(list);
    insertXbetweenBandC(list,'X');
    printSLL(list);
    deleteData(list,'X');
    printSLL(list);
    reverseSLL(list);
    printSLL(list);

    // Uncomment and use these for testing the new functions:

    SLL list1 = createList();
    SLL list2 = createList();

    // Creating first sorted linked list: A -> B -> C
    addLast(list1, 'A');
    addLast(list1, 'B');
    addLast(list1, 'C');

    // Creating second sorted linked list: B -> C -> D
    addLast(list2, 'B');
    addLast(list2, 'C');
    addLast(list2, 'D');

    // Merging the two sorted lists
    SLL mergedList = mergeSortedLists(list1, list2);
    printf("Merged List: ");
    printSLL(mergedList);

    // Removing duplicates from the merged list
    removeDuplicates(mergedList);
    printf("Merged List after removing duplicates: ");
    printSLL(mergedList);

    // Swapping data between two nodes
    swapData(mergedList, 'A', 'C'); // Swap 'A' and 'C'
    printf("Merged List after swapping A and C: ");
    printSLL(mergedList);

    swapData(mergedList, 'D', 'C'); // Attempt to swap 'B' and 'X' (X doesn't exist)
    printSLL(mergedList);

    return 0;
}