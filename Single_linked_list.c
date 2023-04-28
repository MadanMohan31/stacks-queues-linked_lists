#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void insert_beginning(struct node **headadd)
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
        newnode->link = *headadd;
        *headadd = newnode;
    }
}

void delete_beginning(struct node **headadd)
{
    struct node *temp = *headadd;
    if(*headadd == NULL)
    {
        printf("List is Empty.\n");
    }
    else if(temp->link == NULL)
    {
        *headadd = NULL;
        printf("!!!  Deleted Element in the List is %d  !!!\n",temp->data);
        free(temp);
    }
    else
    {
        struct node *temp = *headadd;
        *headadd = (*headadd)->link;
        printf("!!!  Deleted Element in the List is %d  !!!\n",temp->data);
        free(temp);
    }
}

void insert_end(struct node **headadd)
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

void delete_end(struct node **headadd)
{
    struct node *temp = *headadd;
    struct node *cur = temp;
    if(temp == NULL)
    {
        printf("^^^^^ List is Empty ^^^^^\n");
    }
    else if(temp->link == NULL)
    {
        *headadd = NULL;
        printf("!!!  Deleted Element in the List is %d\n",temp->data);
        free(temp);
    }
    else
    {
        while(temp->link != NULL)
        {
            cur = temp;
            temp = temp->link;
        }
        cur->link = NULL;
        printf("!!!  Deleted Element in the List is %d\n",temp->data);
        free(temp);
    }
}

void insert_spepos(struct node **headadd, int pos)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    int num, i;
    scanf("%d %d",&num, &pos);

    newnode->data = num;
    newnode->link = NULL;
    if(*headadd == NULL)
    {
        *headadd = newnode;
    }
    else
    {
        struct node *temp = *headadd;
        struct node *cur = temp;
        for(i=1;i<pos;i++)
        {
            cur = temp;
            temp = temp->link;
        }
        cur->link = newnode;
        newnode->link = temp;
    }
}

void delete_spepos(struct node **headadd, int pos)
{
    scanf("%d",&pos);
    struct node *temp = *headadd;
    struct node *prev = temp;
    if(pos == 1 && *headadd == NULL)
    {
        printf("^^^^^ List Is Empty ^^^^^\n");
    }
    else if(pos==1 && temp->link == NULL)
    {
        *headadd = NULL;
        printf("!!!  Deleted Element in the List is %d  !!!\n",temp->data);
        free(temp);
    }
    else
    {
        while(pos-1 > 0)
        {
            prev = temp;
            temp = temp->link;
            pos--;
        }
        prev->link = temp->link;
        free(temp);
    }
}

void display(struct node **headadd)
{
    struct node *temp = *headadd;
    if(temp == NULL)
    {
        printf("^^^^^ List is Empty ^^^^^\n");
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

void display_reverse(struct node *headadd)
{
    struct node *temp = headadd;
    if(temp->link != NULL)
    {
        display_reverse(temp->link);
    }
    printf("%d  ",temp->data);
    return;
}

int main()
{
    struct node *head = NULL;
    int pos;
    while(1)
    {
        int choice;
        printf("\n1. Insert At Beginning\n2. Delete At Begnning\n3. Insert At End\n4. Delete At End\n5. Insert At Specific Position\n6. Delete At Specific Position\n7. Display\n8. Display Reverse\n9. Exit\n\nEnter the Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert_beginning(&head);
            break;
        case 2:
            delete_beginning(&head);
            break;
        case 3:
            insert_end(&head);
            break;
        case 4:
            delete_end(&head);
            break;
        case 5:
            insert_spepos(&head, pos);
            break;
        case 6:
            delete_spepos(&head, pos);
            break;
        case 7:
            display(&head);
            break;
        case 8:
            display_reverse(head);
            break;
        case 9:
            exit(0);
        default:
            printf("Enter the Valid Choice.");
        }
    }
    return 0;
}
