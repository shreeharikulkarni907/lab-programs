#include<stdio.h>
#include<stdlib.h>
#define max 5
void insert_by_priority();
void delete_by_priority();
void check(int);
void display();
int q[max];
int front=-1;
int rear=-1;
int main()
{
    int option;
    int data;
    printf("*****************MAIN MENU*****************\n");
    do
    {
           printf("1: Insert\n");
           printf("2: Delete\n");
           printf("3:Display\n");
           printf("4: Exit");
           printf("Enter Your Choice\n");
           scanf("%d",&option);
           switch(option)
           {
           case 1:
            insert_by_priority();
            break;
           case 2:
            delete_by_priority();
           case 3:
            display();
           case 4:
            exit(0);
           }
    }while(option!=4);
}
void insert_by_priority()
{
    int num;
    printf("Enter the Number to Be Added\n");
    scanf("%d",&num);
    if(rear==max-1)
    {
        printf("Queue Overflow\n");
    }
    if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        q[rear]=num;
    }
    else
    {
        check(num);
    }
}
void check(int data)
{
    for(int i=0;i<=rear;i++)
    {
        if(data>=q[i])
        {
            for(int j=rear+1;j>i;j--)
            {
                q[j]=q[j-1];
            }
        }
        q[i]=data;
        return;
    }
}
void delete_by_priority()
{
    if(front==-1||front>rear)
    {
        printf("Queue Is Empty\n");
    }
    printf("Element Deleted is %d\n",q[front]);
}
void display()
{
    if(front<=rear)
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",q[i]);
        }
    }
    else
    {
        for(int i=front;i<=max-1;i++)
        {
            printf("%d\t",q[i]);
        }
        for(int i=0;i<front;i++)
        {
            printf("%d\t",q[i]);
        }
    }
}
