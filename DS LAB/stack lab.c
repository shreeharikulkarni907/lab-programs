#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 10
int topi=-1;
int topo=-1;
int inst[max];
int outst[max];
void pushinput(int x);
void pushoutput(int x);
int pop();
void check(int);
void display();
int main()
{
    int option,num,val;
    do
    {
        printf("1:Insert\n");
        printf("2:Delete\n");
        printf("3:Display\n");
        printf("4:Exit\n");
        printf("Enter Your Option\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("Enter number to be inserted\n");
            scanf("%d",&num);
            pushinput(num);
            check(num);
            break;
        case 2:
            val=pop(topi);
            if(val!=-1)
            {
                printf("Item Deleted is %d\n",val);
            }
            break;

        case 3:
            display();
            break;
        }

    }while(option!=4);
}

void pushinput(int x)
{
    if(topi==max-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        topi++;
        inst[topi]=x;
    }
}
void pushoutput(int x)
{
    if(topo==max-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        topo++;
        outst[topo]=x;
    }
}
void check(int x)
{
    int flag=0;
    for(int i=0;i<max;i++)
    {
        if(outst[i]!=x)
        {
            flag=1;
        }
        else
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        pushoutput(x);
    }
}
void display()
{
    printf("******Input Stack*********\n");
    for(int i=0;i<=topi;i++)
    {
        printf("%d\t",inst[i]);
    }
    printf("\n");
    printf("************Output Stack**********\n");
    for(int i=0;i<=topo;i++)
    {
        printf("%d\t",outst[i]);
    }
    printf("\n");
}
int pop()
{
    int val;
    if(topo==-1)
    {
        printf("Stack Empty\n");
        return -1;
    }
    val=inst[topo];
    topo--;
    return val;
}


