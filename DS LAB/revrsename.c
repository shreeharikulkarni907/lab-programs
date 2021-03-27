#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    char item;
    struct node *next;
};
typedef struct node *Node;
Node getNode()
{
    Node x;
    x=(Node)malloc(sizeof(struct node));
    return x;
}
Node insert_end(Node first,char data)
{
    Node last;
    Node new_node;
    new_node=getNode();
    new_node->item=data;
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
Node reverse(Node first)
{
    Node cur,prev,temp;
    if(first==NULL)
    {
        printf("List Is Empty\n");
        return first;
    }
    cur=NULL;
    while(first!=NULL)
    {
      temp=first;
      first=first->next;
      temp->next=cur;
      cur=temp;
    }
    return cur;
}
void display(Node first)
{

    Node temp;
    if(first==NULL)
    {
        printf("List Is Empty\n");
    }
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        printf("%c",temp->item);
    }
    printf("\n");
}
int main()
{
    Node first=NULL;
    Node name_correct=NULL;
    char name[100];
    printf("Please Enter your name in reverse order\n");
    scanf("%s",name);
    for(int i=0;i<strlen(name);i++)
    {
        first=insert_end(first,name[i]);
    }
    name_correct=reverse(first);
    printf("WELCOME\t");
    display(name_correct);
}

