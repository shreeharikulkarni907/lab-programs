#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
    char name[100];
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
NODE insert_end(NODE first,char name[],int data)
{
    NODE last;
    NODE new_node;
    new_node=getNode();
    strcpy(new_node->name,name);
    new_node->cost=data;
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
void display(NODE first)
{

    NODE temp;
    if(first==NULL)
    {
        printf("List Is Empty\n");
    }
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        printf("NAME:%s\t\n",temp->name);
        printf("COST:%d\t\n",temp->cost);

    }
}
void less_than(NODE first)
{

    int sum=0;
    NODE temp;
    if(first==NULL)
    {
        printf("List Is Empty\n");
    }
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        if(temp->cost<=1000)
        {
          sum++;
          printf("NAME:%s\t\n",temp->name);
          printf("COST:%d\t\n",temp->cost);
        }
    }
    printf("Number Of Books With Cost Less Than 1000 are %d\n",sum);
}
void update(NODE first)
{

    int sum=0;
    NODE temp;
    if(first==NULL)
    {
        printf("List Is Empty\n");
    }
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        if(temp->cost>=1000)
        {
            temp->cost=temp->cost - (int)(((20*temp->cost)/(100)));
        }
        else
        {
           temp->cost=temp->cost - (int)(((10*temp->cost)/(100)));
        }
    }
}

