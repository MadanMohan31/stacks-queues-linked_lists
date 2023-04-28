#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void insert_beginning(struct node **headadd)
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
        (*headadd)->prev = newnode;
        newnode->next = *headadd;
        *headadd = newnode;
    }
}

void delete_beginning(struct node **headadd)
{
    struct node *temp = *headadd;
    if(temp == NULL)
    {
        printf("^^^^^ List Is Empty ^^^^^\n");
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

void delete_end(struct node **headadd)
{
    struct node *temp = *headadd;
    if(temp == NULL)
    {
        printf("^^^^^ List is Empty ^^^^^\n");
    }
    else if(temp->next == NULL)
    {
        printf("!!!  Deleted Element in the List is %d  !!!\n",temp->data);
        *headadd = NULL;
        free(temp);
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        struct node *cur = temp->prev;
        cur->next = NULL;
        printf("!!!  Deleted Element in the List is %d  !!!\n",temp->data);
        free(temp);
    }

}

void insert_spepos(struct node **headadd, int pos)
{
    int i;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    int num;
    scanf("%d %d",&num,&pos);
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
        for(i=1;i<pos;i++)
        {
            temp = temp->next;
        }
        struct node *cur = temp->prev;
        cur->next = newnode;
        temp->prev = newnode;
        newnode->prev = cur;
        newnode->next = temp;
    }
}

void delete_spepos(struct node **headadd, int pos)
{
    int i;
    scanf("%d",&pos);
    struct node *temp = *headadd;
    if(temp == NULL)
    {
        printf("^^^^^ List is Empty ^^^^^\n");
    }
    else if(pos == 1 && temp->next == NULL)
    {
        printf("!!!  Deleted Element in the List is %d  !!!\n",temp->data);
        *headadd = NULL;
        free(temp);
    }
    else
    {
        while(pos-1 > 0)
        {
            temp = temp->next;
            pos--;
        }
        struct node *prevnode = temp->prev;
        struct node *nextnode = temp->next;
        nextnode->prev = prevnode;
        prevnode->next = nextnode;
        printf("!!!  Deleted Element in the List is %d  !!!\n",temp->data);
        free(temp);
    }
}

void display(struct node **headadd)
{
    struct node *temp = *headadd;
    if(temp == NULL)
    {
        printf("^^^^^ List Is Empty ^^^^^\n");
        return;
    }
    while(temp != NULL)
    {
        printf("%d  ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void display_reverse(struct node **headadd)
{
    struct node *temp = *headadd;
    if(temp == NULL)
    {
        printf("^^^^^ List Is Empty ^^^^^\n");
        return;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        while(temp->prev != NULL)
        {
            printf("%d  ",temp->data);
            temp = temp->prev;
        }
        printf("%d",temp->data);
        printf("\n");
    }
}

int main()
{
    struct node *head = NULL;
    int p;
    while(1)
    {
        int choice;
        printf("\n1. Insert At Beginning\n2. Delete At Beginning\n3. Insert At End\n4. Delete At End\n5. Insert At Specific Position\n6. Delete At Specific Position\n7. Display\n8. Display Reverse\n9. Exit\nEnter the Choice : ");
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
            insert_spepos(&head, p);
            break;
        case 6:
            delete_spepos(&head, p);
            break;
        case 7:
            display(&head);
            break;
        case 8:
            display_reverse(&head);
            break;
        case 9:
            exit(0);
        default:
            printf("### Enter Valid Choice ###");

        }
    }
    return 0;
}
