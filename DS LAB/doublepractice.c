#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node
{
    char name[50];
    char usn[50];
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{

    NODE x=(NODE)malloc(sizeof(struct node));
    return x;
}
NODE insert_front(NODE head,char usn[],char name[])
{
    NODE new_node,cur;
    new_node=getnode();
    strcpy(new_node->usn,usn);
    strcpy(new_node->name,name);
    cur=head->next;
    head->next=new_node;
    new_node->prev=head;
    new_node->next=cur;
    cur->prev=new_node;
    return head;
}
NODE insert_rear(NODE head,char usn[],char name[])
{
    NODE new_node,cur;
    new_node=getnode();
    strcpy(new_node->usn,usn);
    strcpy(new_node->name,name);
    cur=head->prev;
    cur->next=new_node;
    new_node->prev=cur;
    new_node->next=head;
    head->prev=new_node;
    return head;
}
NODE delete_pos(NODE head,char usn[])
{
    NODE cur=head->next;
    if(strcmp(cur->usn,usn)==0)
    {
        head->next=cur->next;
        (cur->next)->prev=head;
        free(cur);
        return head;
    }
    while(strcmp(cur->usn,usn)!=0)
    {
        cur=cur->next;
    }
    (cur->prev)->next=cur->next;
    (cur->next)->prev=cur->prev;
    free(cur);
    return head;
}
void display(NODE head)
{
    if(head->next==head)
    {
        printf("List Is Empty\n");
        return;
    }
    NODE cur=head->next;
    while(cur!=head)
    {
        printf("%s \t %s \n",cur->usn,cur->name);
        cur=cur->next;
    }
}
int main()
{
    NODE head=getnode();
    head->next=head;
    head->prev=head;
    int option,item,key;
    char usn[50];
    char name[50];
    do{
    printf("1:Insert At Front\n");
    printf("2:Insert At End\n");
    printf("3:delete usn\n");
    printf("4:Display\n");
    printf("5:Exit\n");
    printf("Enter Your Choice\n");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        printf("Enter the usn\n");
        scanf("%s",usn);
        printf("Enter the name\n");
        scanf("%s",name);
        head=insert_front(head,usn,name);
        break;
    case 2:
        printf("Enter the usn\n");
        scanf("%s",usn);
        printf("Enter the name\n");
        scanf("%s",name);
        head=insert_rear(head,usn,name);
        break;
    case 3:
        printf("enter the usn to be deleted\n");
        scanf("%s",usn);
        head=delete_pos(head,usn);
        break;
    case 4:
        display(head);
        break;
    }
    }while(option!=5);
}





