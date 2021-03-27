#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int item;
    struct node *next;
};
typedef struct node *Node;
Node getNode()
{
    Node x;
    x=(Node)malloc(sizeof(struct node));
    return x;
}
Node insert_front(Node first,int data)
{
    Node new_node;
    new_node=getNode();
    new_node->item=data;
    new_node->next=NULL;
    if(first==NULL)
    {
        return new_node;
    }
        new_node->next=first;
        first=new_node;
        return first;

}
Node insert_end(Node first,int data)
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
Node delete_front(Node first)
{
    Node temp;
    if(first==NULL)
    {
        printf("List Is Empty Cannot be deleted\n");
        return first;
    }
    temp=first;
    temp=temp->next;
    free(first);
    return temp;
}
Node delete_end(Node first)
{
    Node prev,cur;
    if(first==NULL)
    {
        printf("List Is Empty And Cannot be deleted\n");
        return first;
    }
    cur=first;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=NULL;
    free(cur);
    return first;
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
        printf("%d\n",temp->item);
    }
}
void stack()
{
    int choice,data;
    Node head=NULL;
    printf("STACK IS IMPLEMENTED INSERT REAR AND DELETE REAR\n");
    do{
    printf("1:INSERT REAR\n");
    printf("2:DELETE REAR\n");
    printf("3:DISPLAY\n");
    printf("4:EXIT\n");
    printf("Enter Your Choice\n");
    scanf("%d",&choice);
    switch(choice)
    {

    case 1:
        printf("Enter The Data To Be Inserted\n");
        scanf("%d",&data);
        head=insert_end(head,data);
        break;
    case 2:
        head=delete_end(head);
        break;
    case 3:
        display(head);
        break;
    }

    }while(choice!=4);

}
void q()
{
    int choice,data;
    Node head=NULL;
    printf("QUEUE IS IMPLEMENTED INSERT FRONT AND DELETE REAR\n");
    do{
    printf("1:INSERT FRONT\n");
    printf("2:DELETE REAR\n");
    printf("3:DISPLAY\n");
    printf("4:EXIT\n");
    printf("Enter Your Choice\n");
    scanf("%d",&choice);
    switch(choice)
    {

    case 1:
        printf("Enter The Data To Be Inserted\n");
        scanf("%d",&data);
        head=insert_front(head,data);
        break;
    case 2:
        head=delete_end(head);
        break;
    case 3:
        display(head);
        break;
    }

    }while(choice!=4);

}
int main()
{

    int option;
    printf("1:STACK\n");
    printf("2:QUEUE\n");
    printf("3:EXIT\n");
    printf("Enter Your Choice\n");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        stack();
        break;
    case 2:
        q();
        break;
    case 3:
        exit(0);
        break;
    }
}
