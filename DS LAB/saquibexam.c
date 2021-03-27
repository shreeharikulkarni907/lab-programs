#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;
NODE getnode()
{

    NODE x=(NODE)malloc(sizeof(struct node));
    return x;
}
NODE ascend(NODE head,int data)
{
    NODE new_node;
    new_node=getnode();
    new_node->info=data;
    if(head->next==head)
    {
        NODE cur=head->next;
        head->next=new_node;
        new_node->prev=head;
        new_node->next=cur;
        cur->prev=new_node;
        return head;
    }
    else
    {
        NODE cur=head->next;
        while(cur!=head)
        {
            if(data<cur->info)
            {
                new_node->prev=cur->prev;
                (cur->prev)->next=new_node;
                new_node->next=cur;
                cur->prev=new_node;
                break;
            }
            else
            {
                if(cur->next==head)
                {
                    new_node->next=cur->next;
                    cur->next=new_node;
                    new_node->prev=cur;
                    return head;
                }
                cur=cur->next;
            }
        }
        return head;
    }
}
NODE insert_front(NODE head,int item)
{
    NODE new_node,cur;
    new_node=getnode();
    new_node->info=item;
    cur=head->next;
    head->next=new_node;
    new_node->prev=head;
    new_node->next=cur;
    cur->prev=new_node;
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
        printf("%d\n",cur->info);
        cur=cur->next;
    }
}
NODE del_item(NODE head,int data)
{
    if(head->next==head)
        printf("List is empty\n");
    NODE cur=head->next;
    while(cur!=head)
    {
        if(cur->info==data)
        {
            (cur->prev)->next=cur->next;
            (cur->next)->prev=cur->prev;
            free(cur);
            return head;
        }
        else
        {
            if(cur->next==head)
            {
                printf("element to delete not found\n");
            }
            cur=cur->next;
        }
    }
}
int main()
{
    NODE head=getnode();
    head->next=head;
    head->prev=head;
    int option,item,key;
    do
    {
      printf("1:Insert At Front\n");
      printf("2:Insert in ascending order\n");
      printf("3:Display\n");
      printf("4:Delete particular\n");
      printf("Enter your option \n");
      scanf("%d",&option);
      switch(option)
      {
      case 1:
        printf("Enter the data\n");
        scanf("%d",&item);
        head=insert_front(head,item);
        break;
      case 2:
        printf("Enter the data\n");
        scanf("%d",&item);
        head=ascend(head,item);
        break;
      case 3:
        display(head);
        break;
      case 4:
        printf("Enter data to be deleted\n");
        scanf("%d",&item);
        head=del_item(head,item);
        break;
      }
    }while(option!=5);
}
