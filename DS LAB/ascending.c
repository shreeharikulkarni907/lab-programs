#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define max 5
int front=-1;
int rear=-1;
int q[max];
void insert(int);
void sort(int q[],int);
int del();
int insert_count=0;
void display();
int main()
{

    for(int i=0;i<max;i++)
    {
        q[i]=32768;
    }
    int option,val;
    int num;
    do
    {

       printf("1:Insert\n");
       printf("2:Delete\n");
       printf("3:Display\n");
       printf("4:Exit\n");
       printf("Enter your Choice\n");
       scanf("%d",&option);
       switch(option)
       {
       case 1:
        insert_count++;
        printf("enter the number to be inserted\n");
        scanf("%d",&num);
        insert(num);
        break;

       case 2:
        val=del();
        if(val!=-1)
            printf("Value Deleted is %d\n",val);
        break;

       case 3:
        display();
        break;




    }
}while(option!=4);
}

void insert(int n)
{
    if(front==0&&rear==max-1)
    {
        printf("Queue Overflow\n");
        exit(0);
    }
    if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        q[rear]=n;
    }
    else if(rear==max-1&&front!=0)
    {
        rear=0;
        q[rear]=n;
        sort(q,insert_count);
    }
    else
    {
        rear++;
        q[rear]=n;
        sort(q,insert_count);
    }
}
int smallest(int a[],int start,int end)
{
    int pos=start;
    int small=a[start];
    for(int i=start+1;i<end;i++)
    {

        if(a[i]<small)
        {
            small=a[i];
            pos=i;
        }
    }
    return pos;
}
void sort(int q[],int n)
{
    int temp,pos;
    for(int i=0;i<n;i++)
    {
        pos=smallest(q,i,n);
        temp=q[i];
        q[i]=q[pos];
        q[pos]=temp;

    }

}

int del()
{
    int val;
    if(front==-1&&rear==-1)
    {
        printf("Queue Is Empty\n");
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
        if(front==max-1)
            front=0;
        else
            front++;
    }
    return val;
}

void display()
{
    if(front==-1||rear==-1)
    {
        printf("Queue Is Empty\n");
    }
    else
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
            for(int i=front;i<max;i++)
                printf("%d\t",q[i]);

            for(int i=0;i<=rear;i++)
            {
                printf("%d\t",q[i]);
            }
            printf("\n");
        }
    }
}
