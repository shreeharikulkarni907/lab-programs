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
NODE insert_leftpos(NODE head,int key,int item)
{
    int flag=1;
    NODE new_node,cur;
    new_node=getnode();
    new_node->info=item;
    cur=head->next;
    if(cur->info==key)
    {
        new_node->next=cur;
        head->next=new_node;
        new_node->prev=head;
        cur->prev=new_node;
        return head;
        flag=0;
    }
    else
    {
       while(cur->info!=key&&cur!=head)
       {

          cur=cur->next;
           if(cur->info==key)
           {
               flag=0;
           }
       }
       if(flag==0)
       {
        (cur->prev)->next=new_node;
        new_node->prev=cur->prev;
        new_node->next=cur;
        cur->prev=new_node;
        return head;
       }
       else
       {
           printf("Invalid Key\n");
           return head;
       }

    }
}
NODE insert_rightpos(NODE head,int key,int item)
{
    int flag=1;
    NODE new_node;
    new_node=getnode();
    new_node->info=item;
    NODE cur;
    cur=head->next;
    if(cur->info==key)
    {
        new_node->next=cur->next;
        (cur->next)->prev=new_node;
        new_node->prev=cur;
        cur->next=new_node;
        flag=0;
        return head;

    }
   /* if((cur->info==key)&&(cur->next==head))
    {
        cur->next=new_node;
        new_node->prev=cur;
        new_node->next=head;
        head->prev=new_node;
        flag=0;
        return head;
    }*/
    while(cur->info!=key)
    {
        cur=cur->next;
        if(cur->info==key)
        {
            flag=0;
        }
    }
    if(flag==0)
    {
        new_node->next=cur->next;
        cur->next=new_node;
        (cur->next)->prev=new_node;
        new_node->prev=cur;
        return head;
    }
    else
    {
        printf("KEY NOT FOUNF\n");
        return head;
    }

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
NODE delete_all_key(NODE head,int key)
{
    int count=0;
    NODE cur=head->next;
    NODE temp;
    while(cur!=head)
    {

        if(cur->info==key)
        {
            temp=cur->prev;;
             count++;
            (cur->prev)->next=cur->next;
            (cur->next)->prev=cur->prev;
            free(cur);
            cur=temp;
        }
        cur=cur->next;
    }
    if(count>0)
    {
        printf("Duplicate Elements are found at %d Position \n",count);
        return head;
    }
    else
    {
        printf("NO DUPLICATES\n");
        return head;
    }
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
void search(NODE head,int key)
{
    NODE cur;
    int i=1;
    int flag=0;
    if((head->next)->info==key)
    {
        flag=1;
        printf("Element Found At Position %d\n " + i);
        return;
    }
    cur=head->next;
    while(cur->info!=key&&cur->next!=head)
    {
        cur=cur->next;
        i++;
        if(cur->info==key)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("Element Found At %d\n",i);
    }
    else
    {
        printf("Element Not Found\n");
    }

}
int main()
{
    NODE head=getnode();
    head->next=head;
    head->prev=head;
    int option,item,key;
    do{
    printf("1:Insert At Front\n");
    printf("2:Insert At End\n");
    printf("3:Delete Front\n");
    printf("4:Delete Rear\n");
    printf("5:Display\n");
    printf("6:Insert left\n");
    printf("7:Insert Right\n");
    printf("8:Delete Duplicates\n");
    printf("9:Search For Element\n");
    printf("10:Delete Key\n");
    printf("Enter Your Choice\n");
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
        display(head);
        break;
    case 6:
        printf("Enter the key Element\n");
        scanf("%d",&key);
        printf("Enter the Item\n");
        scanf("%d",&item);
        head=insert_leftpos(head,key,item);
        break;
    case 7:
        printf("Enter the key Element\n");
        scanf("%d",&key);
        printf("Enter the item\n");
        scanf("%d",&item);
        head=insert_rightpos(head,key,item);
        break;
    case 8:
        head=delete_all(head);
        break;
    case 9:
        printf("Enter the Element To Be Searched\n");
        scanf("%d",&key);
        search(head,key);
        break;
    case 10:
        printf("Enter the Key Element\n");
        scanf("%d",&key);
        head=delete_all_key(head,key);
        break;

    }
    }while(option!=11);
}


