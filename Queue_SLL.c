#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};


void enque(struct node **headadd)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    int num;
    scanf("%d",&num);
    newnode->data = num;
    newnode->link = NULL;
    if(*headadd == NULL)
    {
        *headadd = newnode;
    }
    else
    {
        struct node *temp = *headadd;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
}

void deque(struct node **headadd)
{
    struct node *temp = *headadd;
    if(*headadd == NULL)
    {
        printf("Queue is Empty.\n");
    }
    else if(temp->link == NULL)
    {
        *headadd = NULL;
        printf("!!!  Deleted Element in the Queue is %d  !!!\n",temp->data);
        free(temp);
    }
    else
    {
        struct node *temp = *headadd;
        *headadd = (*headadd)->link;
        printf("!!!  Deleted Element in the Queue is %d  !!!\n",temp->data);
        free(temp);
    }
}

void display(struct node **headadd)
{
    struct node *temp = *headadd;
    if(temp == NULL)
    {
        printf("^^^^^ Queue is Empty ^^^^^\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d  ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main()
{
    struct node *head = NULL;
    while(1)
    {
        int choice;
        printf("\n1. Insert into Queue\n2. Delete from Queue\n3. Display the Queue\n4. Exit\nEnter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enque(&head);
            break;
        case 2:
            deque(&head);
            break;
        case 3:
            display(&head);
            break;
        case 4:
            exit(0);
        default:
            printf("Enter the valid choice\n");
        }

    }
}
