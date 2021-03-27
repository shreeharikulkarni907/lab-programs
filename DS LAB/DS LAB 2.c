#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
    int info;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{

    NODE x=(NODE)malloc(sizeof(struct node));
    return x;
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
NODE insert_rear(NODE head,int item)
{
    NODE new_node,cur;
    new_node=getnode();
    new_node->info=item;
    cur=head->prev;
    cur->next=new_node;
    new_node->prev=cur;
    new_node->next=head;
    head->prev=new_node;
    return head;
}
NODE delete_front(NODE head)
{
    if(head->next==head)
    {
        printf("List Is Empty\n");
        return head;
    }
    NODE temp;
    temp=head->next;
    head->next=temp->next;
    (temp->next)->prev=head;
    free(temp);
    return head;
}
NODE delete_rear(NODE head)
{
    if(head->next==head)
    {
        printf("List Is Empty\n");
        return head;
    }
    NODE cur;
    cur=head->prev;
    (cur->prev)->next=head;
    head->prev=cur->prev;
    free(cur);
    return head;
}
NODE delete_all(NODE head)
{
    NODE temp;
    for(NODE i=head->next;i!=head;i=i->next)
    {
        for(NODE j=i->next;j!=head;j=j->next)
        {
            if(i->info==j->info)
            {
                temp=j;
                (j->prev)->next=j->next;
                if(j->next!=head)
                {
                    j->next->prev=j->prev;
                }
                temp=NULL;
               // temp=NULL;
            }
        }
    }
}
NODE delete_all_key(int item,NODE head)
{
NODE prev,cur,next;
int count;
   if(head->next==head)
    {
     printf("EMPTY TREE");
     return head;
     }
count=0;
cur=head->next;
while(cur!=head)
{
  if(item!=cur->info)
  cur=cur->next;
  else
 {
  count++; //---- udate the number of occurances
  prev=cur->prev;
  next=cur->next;
  prev->next=next;
  next->prev=prev;
  free(cur);
  cur=next; //----search continues again
 }
}
if(count==0)
  printf("key not found\n");
  else
 printf("key found at %d positions and are deleted\n", count);

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
int main()
{

    NODE head=getnode();
    head->next=head;
    head->prev=head;
    int option,item;
    do{
    printf("1:Insert FRONT\n");
    printf("2:Insert REAR\n");
    printf("3:DELETE FRONT\n");
    printf("4:Delete Rear\n");
    printf("5:Delete Duplicates\n");
    printf("6:Delete All Duplicates\n");
    printf("7:Display\n");
    printf("8:Exit\n");
    printf("Enter Your Option\n");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        printf("Enter the item\n");
        scanf("%d",&item);
        head=insert_front(head,item);
        break;
    case 2:
        printf("Enter the item\n");
        scanf("%d",&item);
        head=insert_rear(head,item);
        break;
    case 3:
        head=delete_front(head);
        break;
    case 4:
        head=delete_rear(head);
        break;
    case 5:
        head=delete_all(head);
        break;
    case 6:
        printf("Enter the item whose duplicates you want to remove\n");
        scanf("%d",&item);
        head=delete_all_key(item,head);
        break;
    case 7:
        display(head);
        break;
    }
}while(option!=8);

}
