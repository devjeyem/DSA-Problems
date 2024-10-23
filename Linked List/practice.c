#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));

    head->data = 45;
    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->data= 55;
    head->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->data = 60;
    head->next->next->next = NULL;

    struct node *p = head;
    while(p!=NULL)
    {
        printf("%d->", p->data);
        p = p->next;

    }


}