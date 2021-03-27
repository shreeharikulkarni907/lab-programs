#include<stdio.h>
#include<string.h>
#include<ctype.h>
void display();
int front=-1;
int rear=-1;
int q[10];
void push(int);
int pop();
int main()
{
    int c;
    int count=0;
    int array[]={50,40,30,20,10}; //array representing tasks time
    int t=10;
    for(int i=0;i<4;i++)
    {
        push(array[i]);
    }
    while(count<=5)
    {
       for(int i=0;i<5;i++)
       {
           c=pop();
           c=c-t;
           if(c==0)
           {
               count++;
           }
           if(c!=0)
           {
              push(c);
           }
       }
    }
    if(count==5)
    {
        printf("All Process Have Been Successfully Completed\n");
    }
    display();
}
void push(int x)
{
    if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear==4&&front!=0)
    {
        rear=0;
    }
    else
    {
        rear++;
    }
    q[rear]=x;
}

int pop()
{
    int val;
    if(front==-1&&rear==-1)
    {
        return -1;
    }
    val=q[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        if(front==4)
        {
            front=0;
        }
        else
        {
           front++;
        }
    }
    return val;
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
        for(int i=front;i<=4;i++)
        {
            printf("%d\t",q[i]);
        }
        for(int i=0;i<=rear;i++)
        {
            printf("%d\t",q[i]);
        }
    }
}
