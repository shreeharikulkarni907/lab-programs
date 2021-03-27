#include<stdio.h>
#include<string.h>
#include<ctype.h>
# define max 3
int topi=-1;
int topo=-1;
int inst[7];
int outst[3];
void first_stack();
void second_stack();
void pushinput1(int x);
void pushinput2(int x);
int pop();
void display();
void merge_sort();
void sort(int a[]);
int main()
{
    int option,num,val,choice;
    do{
    printf("1: 1st stack\n");
    printf("2: 2nd stack\n");
    printf("3: display\n");
    printf("4:Exit\n");
    printf("Enter Your Choice\n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        first_stack();
        break;

    case 2:
        second_stack();
        break;


    case 3:
        merge_sort();
        break;

    }

    }while(option!=4);

}

void first_stack()
{
    int option,num,val;
       do
       {
           printf("*********1st Stack************\n");
            printf("1:Insert\n");
            printf("2:Delete\n");
            printf("3:Exit\n");
            printf("Enter Your Option\n");
            scanf("%d",&option);
            switch(option)
            {
              case 1:
                printf("Enter number to be inserted\n");
                scanf("%d",&num);
                pushinput1(num);
                break;
              case 2:
                val=pop(topi);
                if(val!=-1)
                {
                    printf("Item Deleted is %d\n",val);
                }
                break;

            }
         }while(option!=3);


}

void second_stack()
{
    int option,num,val;
       do
       {
           printf("*********2nd Stack************\n");
            printf("1:Insert\n");
            printf("2:Delete\n");
            printf("3:Exit\n");
            printf("Enter Your Option\n");
            scanf("%d",&option);
            switch(option)
            {
              case 1:
                printf("Enter number to be inserted\n");
                scanf("%d",&num);
                pushinput2(num);
                break;
              case 2:
                val=pop(topi);
                if(val!=-1)
                {
                    printf("Item Deleted is %d\n",val);
                }
                 break;
        }

    }while(option!=3);
}


void pushinput1(int x)
{
    if(topi==5)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        topi++;
        inst[topi]=x;
    }
}

void pushinput2(int x)
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
int pop()
{
    int val;
    if(topo==-1)
    {
        printf("Stack Empty\n");
        return -1;
    }
    val=outst[topo];
    topo--;
    return val;
}
void merge_sort()
{
    int val;
    while(topo>=0)
    {
        val=pop();
        pushinput1(val);
    }
    sort(inst);
}

void sort(int a[])
{
    int i,j,temp;
        for (i = 0; i<5; i++){
          for (j = 0; j < 6- i - 1; j++) {
        if (a[j] < a[j+1])
        {
          temp = a[j];
          a[j] = a[j+1];
          a[j+1] = temp;
        }
      }
    }
    display();
}

void display()
{
    if(topi==-1)
    {

        printf("Stack Empty\n");
    }
    printf("Merged And Sorted Stack is \n");
    for(int i=0;i<=topi;i++)
    {
        printf("%d\t",inst[i]);
    }
    printf("\n");
}





