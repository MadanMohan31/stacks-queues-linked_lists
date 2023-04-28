#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void push(struct node **headadd)
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

void pop(struct node **headadd)
{
    struct node *temp = *headadd;
    if(temp == NULL)
    {
        printf("^^^^^ Stack is Empty ^^^^^\n");
    }
    else if(temp->link == NULL)
    {
        *headadd = NULL;
        printf("!!!  Deleted Element in the Stack is %d\n",temp->data);
        free(temp);
    }
    else
    {
        struct node *cur = temp;
        while(temp->link != NULL)
        {
            cur = temp;
            temp = temp->link;
        }
        cur->link = NULL;
        printf("!!!  Deleted Element in the Stack is %d\n",temp->data);
        free(temp);
    }

}

void display(struct node **headadd)
{
    struct node *temp = *headadd;
    if(temp == NULL)
    {
        printf("^^^^^ Stack is Empty ^^^^^\n");
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
        printf("\n1. Insert into Stack\n2. Delete from Stack\n3. Display the Stack\n4. Exit\nEnter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push(&head);
            break;
        case 2:
            pop(&head);
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
