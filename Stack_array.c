#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int top = -1;

int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(int n)
{
    if(top == n-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int stack[], int n)
{
    if(isFull(n))
    {
        printf("^^^^^Stack Overflow^^^^^\n");
    }
    else
    {
        int data;
        scanf("%d",&data);
        top++;
        stack[top] = data;
    }
}

void pop(int stack[])
{
    if(isEmpty())
    {
        printf("^^^^^Stack Underflow^^^^^\n");
    }
    else
    {
        printf("Deleted element is == %d\n",stack[top]);
        top--;
    }
}

void display(int stack[])
{
    if(isEmpty() == 1)
    {
        printf("^^^^^Stack underflow^^^^^\n");
    }
    else
    {
        int i;
        for(i=top;i>=0;i--)
        {
            printf("%d  ",stack[i]);
        }
        printf("\n");
    }
}

void topElement(int stack[])
{
    if(isEmpty() == 1)
    {
        printf("^^^^^Satck underflow^^^^^\n");
    }
    else
    {
        printf("Top element is == %d\n",stack[top]);
    }
}

int main()
{
    int n;
    printf("Size of Array = ");
    scanf("%d",&n);
    int stack[n];
    int choice;
    while(1)
    {
        printf("\n1.Push\t2.Pop\t3.Display\t4.Top Element\t5.Is Empty\t6.Is Full\t7.Exit\nEnter the Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push(stack,n);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                topElement(stack);
                break;
            case 5:
                if(isEmpty == 1)
                {
                    printf("!!! Stack Is Empty !!!\n");
                }
                else
                {
                    printf("!!! Stack Is Not Empty !!!\n");
                }
                break;
            case 6:
                if(isFull == 1)
                {
                    printf("!!! Stack is Full !!!\n");
                }
                else
                {
                    printf("!!! Stack Is Not Full!!!\n");
                }
                break;
            case 7:
                return 0;
            default:
                printf("#### Enter the Valid Choice ####\n");
        }
    }
    return 0;
}
