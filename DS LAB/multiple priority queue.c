#include<stdio.h>
#include<string.h>
#define n 3
int front[3]={-1,-1,-1};
int rear[3]={-1,-1,-1};
int q[3][n];
void insert(int);
void del();
void display();
int main()
{
    int option,pr;
    do{
    printf("1: Insert\n");
    printf("2: Delete\n");
    printf("3: Display\n");
    printf("4: Exit");
    printf("Enter Your Option\n");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        printf("Enter the priority\n");
        scanf("%d",&pr);
        if(pr>0&&pr<4)
        {
            insert(pr-1);
        }
        else
        {
            printf("Three Priorities Allowed\n");
        }
        break;
    case 2:
        del();
        break;
    case 3:
        display();
        break;

    }
}while(option!=4);
}

void insert(int pr)
{
    int num;
    printf("Enter the Number to be inserted\n");
    scanf("%d",&num);
    if(rear[pr]==n-1)
    {
        printf("Queue Overflow\n");
    }
    else if(front[pr]==-1&&rear[pr]==-1)
    {
        front[pr]=0;
        rear[pr]=0;
    }
    else
    {
        rear[pr]++;
    }
    q[pr][rear[pr]]=num;
}

void del()
{
    for(int i=0;i<n;i++)
    {
        if(front[i]==-1)
        {
            printf("Queue Empty\n");
        }
        printf("Deleted Item Is %d from queue %d\n",q[i][front[i]]);
        if(front[i]>rear[i])
        {
            front[i]=-1;
            rear[i]=-1;
        }
        else
        {
            front[i]++;
        }
    }
}

void display()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(front[i]==-1)
        printf("Queue Is Empty\n");
        else
        {
          printf("Elements of queue %d\n",(i+1));
          for(int j=front[i];j<=rear[i];j++)
          {
            printf("%d\n",q[i][j]);
          }
        }
    }

}


