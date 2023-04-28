#include <stdio.h>
#include <stdlib.h>
int f=-1, r=-1;

int isEmpty()
{
    if((f==-1 && r==-1) || f>r)
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
    if(r==n-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enque(int queue[], int n)
{
    if(isFull(n))
    {
        printf("^^^^^ Queue Is Full ^^^^^\n");
    }
    else
    {
        int data;
        scanf("%d",&data);
        if(isEmpty())
        {
            f++;
            r++;
        }
        else
        {
            r++;
        }
        queue[r] = data;
    }
}

void deque(int queue[])
{
    if(isEmpty())
    {
        printf("^^^^^ Queue is Empty ^^^^^\n");
    }
    else
    {
        printf("Deleted Element is %d\n",queue[f]);
        f++;
    }
}

void display(int queue[])
{
    if(isEmpty())
    {
        printf("^^^^^ Queue Is Empty ^^^^^\n");
    }
    else
    {
        int i;
        for(i=f;i<=r;i++)
        {
            printf("%d  ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Size of Queue = ");
    scanf("%d",&n);
    int queue[n];
    int choice;
    while(1)
    {
        printf("\n1.Push\t2.Pop\t3.Display\t4.Is Empty\t5.Is Full\t6.Exit\nEnter the Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enque(queue,n);
                break;
            case 2:
                deque(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                if(isEmpty() == 1)
                {
                    printf("!!! Queue Is Empty !!!\n");
                }
                else
                {
                    printf("!!! Queue Is Not Empty !!!\n");
                }
                break;
            case 5:
                if(isFull(n) == 1)
                {
                    printf("!!! Queue is Full !!!\n");
                }
                else
                {
                    printf("!!! Queue Is Not Full!!!\n");
                }
                break;
            case 6:
                return 0;
            default:
                printf("#### Enter the Valid Choice ####\n");
        }
    }
    return 0;
}
