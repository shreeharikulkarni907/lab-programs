#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct node
{
    char name[100];
    char mobile[100];
    char place[100];
    struct node *next;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
}
NODE insert_rear(NODE last,char name[],char mobile[100],char place[100])
{
    NODE new_node;
    new_node=getnode();
    strcpy(new_node->name,name);
    strcpy(new_node->mobile,mobile);
    strcpy(new_node->place,place);
    if(last==NULL)
    {
        new_node->next=new_node;
        return new_node;
    }
    else
    {
        new_node->next=last->next;
        last->next=new_node;
        last=new_node;
        return  last;
    }
}
void display(NODE last)
{
    int flag=0;
    NODE i;
    printf("PERSONS FROM BANGALORE ARE\n");
    if(last==NULL)
    {
        printf("List iS empty and Cannot Be Displayed\n");
        return;
    }
    for(i=last->next;i!=last;i=i->next)
    {
        if(strcmp(i->place,"Bangalore")==0)
        {
            flag=1;
            printf("NAME:%s \n",i->name);
            printf("MOBILE:%s: \n",i->mobile);
            printf("PLACE:%s\n",i->place);
        }

    }
    if(strcmp(i->place,"Bangalore")==0)
    {
        flag=1;
        printf("NAME: %s \n",i->name);
        printf("MOBILE: %s \n",i->mobile);
        printf("PLACE: %s\n",i->place);
    }
    if((flag==0))
    {
        printf("SORRY THERE ARE NO CUSTOMERS FROM BANGALORE\n");
    }
}
int main()
{
    int i=0;
    NODE last=NULL;
    int option;
    char name[50];
    char mobile[50];
    char place[50];
    do
    {
        printf("1:Insert Details\n");
        printf("2:Display Customers In Bangalore\n");
        printf("3:EXIT\n");
        printf("Enter your choice\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("Enter the name of customer %d \n",(i+1));
            scanf("%s",name);
            printf("Enter the mobile number of customer %d \n",(i+1));
            scanf("%s",mobile);
            printf("Enter the place of the customer %d \n",(i+1));
            scanf("%s",place);
            last=insert_rear(last,name,mobile,place);
            i++;
            break;
        case 2:
            display(last);
            break;
        }
    }while(option!=3);
}
