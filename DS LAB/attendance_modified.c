#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct node
{
    char name[50];
    char usn[50];
    struct node *link;
};
typedef struct node *Node;
Node getNode()
{
    Node x;
    x=(Node)malloc(sizeof(struct node));
    return x;
}
Node insert_front(Node first,char n[],char u[])
{
    Node new_node;
    Node new_node_usn;
    new_node=getNode();
    strcpy(new_node->name,n);
    strcpy(new_node->usn,u);
    new_node->link=NULL;
    if(first==NULL)
    {
        return new_node;
    }
    new_node->link=first;
    first=new_node;
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
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=NULL;
    free(cur);
    return first;
}
void search(Node first,char n[])
{
    int pos=0;
    Node temp;
    int i;
    if(first==NULL)
    {
        printf("List Is Empty\n");
        return;
    }
    for(temp=first,i=0;temp!=NULL;temp=temp->link,i++)
    {
        if(strcmp(temp->usn,n)==0)
        {
            pos=i+1;
            printf("Search Successfull\n");
            printf("Element Is Found At Position %d\n",pos);
            break;
        }
        else
        {
            pos=0;
        }
    }
    if(pos==0)
    {
       printf("Search Unsuccesfull\n");
    }
}
void sort(Node first)
{
    char t_usn[50];
    char t_name[50];
    Node temp;
    if(first==NULL)
    {
        printf("List Is Empty\n");
        return;
    }
    for(Node i=first;i!=NULL;i=i->link)
    {
        for(Node j=i->link;j!=NULL;j=j->link)
        {
            if(strcmp((i->usn),(j->usn))>0)
            {
                strcpy(t_usn,i->usn);
                strcpy(t_name,i->name);
                strcpy(i->usn,j->usn);
                strcpy(i->name,j->name);
                strcpy(j->usn,t_usn);
                strcpy(j->name,t_name);
            }
        }
    }
    printf("List In Ascending order is\n");
}
void sort1(Node first)
{
    char t_usn[50];
    char t_name[50];
    Node temp;
    if(first==NULL)
    {
        printf("List Is Empty\n");
        return;
    }
    for(Node i=first;i!=NULL;i=i->link)
    {
        for(Node j=i->link;j!=NULL;j=j->link)
        {
            if(strcmp((i->name),(j->name))>0)
            {
                strcpy(t_usn,i->usn);
                strcpy(t_name,i->name);
                strcpy(i->usn,j->usn);
                strcpy(i->name,j->name);
                strcpy(j->usn,t_usn);
                strcpy(j->name,t_name);
            }
        }
    }
    printf("List In Ascending order is\n");
}
void display(Node first)
{
    Node temp;
    if(first==NULL)
    {
        printf("List Is Empty\n");
    }
    for(temp=first;temp!=NULL;temp=temp->link)
    {
        printf("Name\t");
        puts(temp->name);
        printf("\n");
        printf("USN\t");
        puts(temp->usn);
        printf("\n");
    }
}
int main()
{
    Node first=NULL;
    Node a= NULL;
    Node b=NULL;
    Node ans=NULL;
    int choice;
    char name[50];
    char usn[50];
    char n[50];
    do
    {
        printf("1:Insert at Front\n");
        printf("2:Delete End\n");
        printf("3:Search For Element\n");
        printf("4:Sort By USN\n");
        printf("5:Sort By Name\n");
        printf("6:Display\n");
        printf("7: Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the Name To Be Inserted\n");
            scanf("%s",name);
            printf("Enter the USN to Be Inserted\n");
            scanf("%s",usn);
            first=insert_front(first,name,usn);
            break;
        case 2:
            first=delete_end(first);
            break;

        case 3:
            printf("Enter the USN Number To Searched\n");
            scanf("%s",n);
            search(first,n);
            break;
        case 4:
            sort(first);
            break;
        case 5:
            sort1(first);
            break;
        case 6:
            display(first);
            break;
        }
    }while(choice!=7);
}
