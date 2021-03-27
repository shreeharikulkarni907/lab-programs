#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    char item[100];
    struct node *next;
};
typedef struct node *Node;
Node getNode()
{
    Node x;
    x=(Node)malloc(sizeof(struct node));
    return x;
}
/*Node insert_front(Node first,char data[])
{
    Node new_node;
    new_node=getNode();
    strcpy(new_node->item,data);
    new_node->next=NULL;
    if(first==NULL)
    {
        return new_node;
    }
        new_node->next=first;
        first=new_node;
        return first;

}*/
Node insert_end(Node first,char data[])
{
    Node last;
    Node new_node;
    new_node=getNode();
    strcpy(new_node->item,data);
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
        printf("URL: %s\n",temp->item);
    }
}
int main()
{
    int option;
    Node head=NULL;
    char name[100];
    do
    {
        printf("1:VISIT NEW SITE\n");
        printf("2:GO BACK\n");
        printf("3:DISPLAY SITES YOU HAVE VISITED\n");
        printf("4:EXIT\n");
        printf("Enter Your Option\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("ENTER THE URL ADDRESS\n");
            scanf("%s",name);
            head=insert_end(head,name);
            break;
        case 2:
            head=delete_end(head);
            break;
        case 3:
            display(head);
            break;
        }
    }while(option!=4);
}
