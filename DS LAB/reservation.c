#include<stdio.h>
#include<string.h>
#define MAX 10
int q[MAX];
int front=-1;
int rear=-1;
void insert()
{
    int num;
    printf("Enter the PNR number of the Passenger \n");
    scanf("%d",&num);
    if(front==0&&rear==MAX-1)
        printf("ALL TICKETS ARE BOOKED\n");
    else if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        q[rear]=num;
    }
    else
    {
        rear++;
        q[rear]=num;
    }
}
int delete_element()
{
    int val;
    if(front==-1&&rear==-1)
    {
        printf("NO BOOKING DONE\n");
        return -1;
    }
    val=q[front];
    if(front==rear)
        front=rear=-1;
    else
    {
        if(front==MAX-1)
            front=0;
        else
            front++;
    }
    return val;
}
void display()
{
    int i;
    printf("\n");
    if(front==-1&&rear==-1)
        printf("NO BOOKING\n");
    else
    {
        if(front<rear)
        {
            for(i=front;i<=rear;i++)
                printf("%d\n",q[i]);
        }
        else
        {
            for(i=front;i<MAX;i++)
                printf("%d\n",q[i]);
            for(i=0;i<=rear;i++)
                printf("%d\n",q[i]);
        }
    }
}
int main()
{
    int option,val;
    do
    {
        printf("1:Book Ticket\n");
        printf("2:Cancel Ticket\n");
        printf("3:List of passengers who have booked Ticket\n");
        printf("4:EXIT\n");
        printf("ENTER YOU CHOICE\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            insert();
            break;
        case 2:
            val=delete_element();
            if(val!=-1)
            printf("PASSENGER %d CANCELLED HIS TICKET\n",val);
            break;
        case 3:
            display();
            break;
        }
    }while(option!=4);

}




