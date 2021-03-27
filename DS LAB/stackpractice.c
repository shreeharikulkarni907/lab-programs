#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
    char name[100];
    char time;
    char id[100];
    int cost;
    struct node *next;
};
typedef struct node *NODE;
NODE getNode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
}
NODE insert_end(NODE first,char name[],int data,char ch,char id[])
{
    NODE last;
    NODE new_node;
    new_node=getNode();
    strcpy(new_node->name,name);
    new_node->cost=data;
    new_node->time=ch;
    strcpy(new_node->id,id);
    new_node->next=NULL;
    if(first==NULL)
    {
        return new_node;
    }
    last=first;
    while(last->next!=NULL)
    {
       last=last->next;
    }
    last->next=new_node;
    return first;
}
NODE delete(NODE first,char id[])
{
    NODE prev,cur;
    if(first==NULL)
    {
        printf("List Is Empty And Cannot be deleted\n");
        return first;
    }
    if(strcmp(first->id,id)==0)
    {
        NODE temp=first;
        first=first->next;
        free(temp);
        return first;
    }
    cur=first;
    while(strcmp(cur->id,id)!=0)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=cur->next;
    free(cur);
    return first;
}
void sort(NODE first)
{
    int t;
    char tem[100];
    NODE temp;
    if(first==NULL)
    {
        printf("List Is Empty\n");
        return;
    }
    for(NODE i=first;i!=NULL;i=i->next)
    {
        for(NODE j=i->next;j!=NULL;j=j->next)
        {
            if((i->cost)>(j->cost))
            {
                t=i->cost;
                strcpy(tem,i->name);
                i->cost=j->cost;
                strcpy(i->name,j->name);
                j->cost=t;
                strcpy(j->name,tem);
            }

        }
    }
}
void display(NODE first,char t)
{

    int sum=0;
    NODE temp;
    if(first==NULL)
    {
        printf("List Is Empty\n");
    }
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        if(temp->time==t)
        {
            printf("NAME:%s\t\n",temp->name);
            printf("SALARY:%d\t\n",temp->cost);
            printf("TIMING:%c\t\n",temp->time);
            printf("ID:%s\t\n",temp->id);

        }

    }
}

int main()
{
    int option,data;
    NODE head=NULL;
    char name[100],id[100];
    char t;
    do
    {
        printf("1:Insert Rear\n");
        printf("2:Delete Doctor Details\n");
        printf("4:Display Details\n");
        printf("5:Exit\n");
        printf("Enter Your Choice\n");
        scanf("%d",&option);
        switch(option)
        {

        case 1:
            printf("Enter the cost of the item\n");
            scanf("%d",&data);
            printf("Enter the name of the item\n");
            scanf("%s",name);
            head=insert_end(head,name,data);
            break;
        case 2:
            printf("Enter The ID OF the Doctor who is leaving\n");
            scanf("%s",id);
            head=delete_end(head,id);
            break;
        case 3:
            sort(head);
            break;
        case 4:
            printf("Enter the timing for which whose doctor details you want to display\n");
            scanf("%c",&t);
            display(head,t);
            break;
        }
    }while(option!=5);

}

