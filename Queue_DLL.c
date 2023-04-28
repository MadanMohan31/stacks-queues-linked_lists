#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void enque(struct node **headadd)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    int num;
    scanf("%d",&num);
    newnode->prev = NULL;
    newnode->data = num;
    newnode->next = NULL;
    if(*headadd == NULL)
    {
        *headadd = newnode;
    }
    else
    {
        struct node *temp = *headadd;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void deque(struct node **headadd)
{
    struct node *temp = *headadd;
    if(temp == NULL)
    {
        printf("^^^^^ Queue Is Empty ^^^^^\n");
    }
    else if(temp->next == NULL)
    {
        *headadd = NULL;
        printf("!!!  Deleted Element in the Queue is %d  !!!\n",temp->data);
        free(temp);
    }
    else
    {
        temp = *headadd;
        *headadd = (*headadd)->next;
        (*headadd)->prev = NULL;
        printf("!!!  Deleted Element in the Queue is %d  !!!\n",temp->data);
        free(temp);
    }
}

void display(struct node **headadd)
{
    struct node *temp = *headadd;
    if(temp == NULL)
    {
        printf("^^^^^ Queue Is Empty ^^^^^\n");
        return;
    }
    while(temp != NULL)
    {
        printf("%d  ",temp->data);
        temp = temp->next;
    }
    printf("\n");
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
