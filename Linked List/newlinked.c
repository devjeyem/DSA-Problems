#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct node
{
    Item data;
    struct node* next;
}*SNODE;

void countNodes(SNODE head)
{
    int ctr = 0;
    SNODE p = head;
    while (p != NULL)
    {
        ctr++;
        p = p->next;
    }
    printf("\nNumber of nodes: %d\n", ctr);
}

void printData(SNODE head)
{
    SNODE p = head;
    if (p == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    //printf("NULL\n");
}

void addAtEnd(SNODE head, int data)
{
    SNODE ptr, temp;
    ptr = head;
    temp = (SNODE)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

SNODE addAtBeg(SNODE head, int data)
{
    SNODE ptr = (SNODE)malloc(sizeof(struct node));
    ptr->data  = data;
    ptr->next = head;
    head = ptr;
    return head;
}

void addAtBeg1(SNODE *head, int data)
{
    SNODE ptr = (SNODE)malloc(sizeof(struct node));
    ptr->data  = data;
    ptr->next = *head;
    *head = ptr;
}

SNODE insertNode(SNODE head, int data)
{
    SNODE ptr, ptr2;
    ptr = head;
    ptr2 = (SNODE)malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->next = NULL;
    while(ptr != NULL)
    {
        if(ptr->data == 3)
        {
            ptr2->next = ptr->next;
            ptr->next = ptr2;
            break;
        }
        ptr = ptr->next;
    }
    return head;
}

SNODE delFirst(SNODE head)
{
    if(head == NULL)
    {
        printf("EMPTY LIST\n");
        return head;
    }
    else
    {
        SNODE temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}

SNODE delLast(SNODE head)
{
    if (head == NULL)
    {
        printf("EMPTY LIST\n");
        return head;
    }
    else if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        SNODE temp = head;
        SNODE temp2 = head;
        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
        temp = NULL;
        return head;
    }
}

int main()
{
    // Creating a linked list with 3 nodes
    SNODE head = (SNODE)malloc(sizeof(struct node));
    head->data = 45;
    head->next = (SNODE)malloc(sizeof(struct node));
    head->next->data = 98;
    head->next->next = (SNODE)malloc(sizeof(struct node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    // Print initial list
    printf("Initial list: ");
    printData(head);
    printf("\n");

    // Add a node at the end
    addAtEnd(head, 100);
    //printf("After adding at the end: ");
    printData(head);
    printf("\n");

    // Insert a node after value 3
    head = insertNode(head, 67);
    //printf("After inserting node after 3: ");
    printData(head);
    printf("\n");

    // Delete the first node
    head = delFirst(head);
   // printf("After deleting the first node: ");
    printData(head);
    printf("\n");

    // Delete the last node
    head = delLast(head);
    //printf("After deleting the last node: ");
    printData(head);
    printf("\n");

    return 0;
}
