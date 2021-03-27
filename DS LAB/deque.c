#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define max 5
void insert_right();
void insert_left();
void delete_right();
void delete_left();
void display();
void input();
void output();
int q[max];
int left=-1;
int right=-1;
int main()
{
    int option;
    printf("1: INPUT RESTRICTED\n");
    printf("2: OUTPUT RESTRICTED\n");
    printf("3: EXIT\n");
    printf("Enter Your Choice \n");
    scanf("%d",&option);
    switch(option)
    {

    case 1:
        input();
        break;
    case 2:
        output();
        break;
    case 3:
        exit(0);
    }

}
void input()
{
    int option;
    do
    {
        printf("1:Insert Right\n");
        printf("2:Delete Right\n");
        printf("3:Delete Left\n");
        printf("4:Display\n");
        printf("5:Exit\n");
        printf("Enter your Option\n");
        scanf("%d",&option);
        switch(option)
        {

        case 1:
            insert_right();
            break;
        case 2:
            delete_right();
            break;
        case 3:
            delete_left();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        }
    }while(option!=5);
}

void output()
{
    int option;
    do
    {
        printf("1:Delete Left\n");
        printf("2:Insert Right\n");
        printf("3:Insert Left\n");
        printf("4:Display\n");
        printf("5:EXIT\n");
        printf("Enter Your Option\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            delete_left();
            break;
        case 2:
            insert_right();
            break;
        case 3:
            insert_left();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        }
    }while(option!=5);
}

void insert_right()
{
    int num;
    printf("Enter The Number To Be Inserted \n");
    scanf("%d",&num);
    if((left==0&&right==max-1)||left==right+1)
    {
        printf("Queue Overflow\n");
        exit(0);
    }
    if(left==-1&&right==-1)
    {
        left=0;
        right=0;
    }
    else
    {
        if(right==max-1)
            right=0;
        else
            right++;
    }
    q[right]=num;
}
void insert_left()
{
    int num;
    printf("Enter The Number To Be Inserted \n");
    scanf("%d",&num);
    if((left==0&&right==max-1)||left==right+1)
    {
        printf("Queue Overflow\n");
        exit(0);
    }
    if(left==-1&&right==-1)
    {
        left=0;
        right=0;
    }
    else
    {
        if(left==0)
            left=max-1;
        else
            left--;
    }
    q[left]=num;
}
void delete_left()
{
    if(left==-1)
    {
        printf("Queue Underflow\n");
    }
    printf("Element Deleted is %d\n",q[left]);
    if(left==right)
    {
        left=-1;
        right=-1;
    }
    else
    {
        if(left==max-1)
            left=0;
        else
            left++;
    }
}
void delete_right()
{
    if(left==-1)
    {
        printf("Queue Underflow\n");
    }
    printf("Element Deleted is %d\n",q[right]);
    if(left==right)
    {
        left=-1;
        right=-1;
    }
    else
    {
        if(right==0)
            right=max-1;
        else
            right--;
    }
}
void display()
{
    int front=left;
    int rear=right;
    if(left==-1)
    {
        printf("Queue Is Empty\n");
        exit(0);
    }
    if(front<=rear)
    {
        while(front<=rear)
        {
            printf("%d\t",q[front]);
            front++;
        }
    }
    else
    {
        while(front<=max-1)
        {
            printf("%d\t",q[front]);
            front++;
        }
        front=0;
        while(front<=rear)
        {
            printf("%d\t",q[front]);
            front++;
        }
    }
}

