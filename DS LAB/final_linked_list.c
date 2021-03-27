#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>
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
Node insert_pos(Node first,int data,int pos)
{
    Node last;
    Node new_node;
    new_node=getNode();
    new_node->item=data;
    if(first==NULL&&pos==1)
    {
        new_node->next=NULL;
        return new_node;
    }
    else if(pos<1)
    {
        printf("Invalid Position\n");
        return first;
    }
    else if(pos==1)
    {
        new_node->next=first;
        first=new_node;
        return first;
    }
    else
    {
        last=first;
        for(int i=1;i<pos-1;i++)
        {
            last=last->next;
        }
        new_node->next=last->next;
        last->next=new_node;
        return first;
    }

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
Node delete_pos(Node first,int pos)
{
    Node prev,cur;
    if(first==NULL)
    {
        printf("List is empty and cannot be deleted\n");
        return first;
    }
    if(pos==1)
    {
        cur=first;
        first=first->next;
        free(cur);
        return first;
    }
    cur=first;
    for(int i=1;i<pos;i++)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=cur->next;
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
Node delete_specific(Node first,int key)
{
    Node cur,prev;
    if(first->item==key)
    {
        Node temp=first;
        temp=temp->next;
        free(first);
        return temp;
    }
    cur=first;
    while(cur->item!=key)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=cur->next;
    free(cur);
    return first;
}
void sort(Node first)
{
    int t;
    Node temp;
    if(first==NULL)
    {
        printf("List Is Empty\n");
        return;
    }
    for(Node i=first;i!=NULL;i=i->next)
    {
        for(Node j=i->next;j!=NULL;j=j->next)
        {
            if((i->item)>(j->item))
            {
                t=i->item;
                i->item=j->item;
                j->item=t;
            }
            /*if((i->item)==(j->item))
            {
                first=delete_specific(first,j->item);
                break;
            }
            */

        }
    }
}
Node concat(Node first,Node second)
{
    Node cur;
    if(first==NULL)
    {
        first=second;
        return first;
    }
    if(second==NULL)
    {
        return first;
    }

        cur=first;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=second;
        printf("Final Concatinated List is \n");
        return first;
}
Node merged_sort(Node a,Node b)
{
    Node result;
    if(a==NULL)
    {
        return b;
    }
    else if(b==NULL)
    {
        return b;
    }
    if(a->item<=b->item)
    {
        result=a;
        result->next=merged_sort(a->next,b);
    }
    else
    {
        result=b;
        result->next=merged_sort(a,b->next);
    }
    return result;
}
Node order_list(Node first,int data)
{
    Node new_node;
    Node prev,cur;
    new_node=getNode();
    new_node->item=data;
    if(data<first->item)
    {
        new_node->next=first;
        first=new_node;
        return first;
    }
    cur=first;
    prev=NULL;
    while(cur!=NULL&&cur->item<data)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=new_node;
    new_node->next=cur;
    return first;
}

int main()
{
    Node first=NULL;
    Node a= NULL;
    Node b=NULL;
    Node ans=NULL;
    int choice,val,pos,n;
    do
    {
        printf("1:Insert at Front\n");
        printf("2:Insert at End\n");
        printf("3:Insert at Specified Position\n");
        printf("4:Delete Front\n");
        printf("5:Delete End\n");
        printf("6:Delete At Specified Position\n");
        printf("7:Display\n");
        printf("8:Reverse the list\n");
        printf("9:Sort the List\n");
        printf("10:Concat\n");
        printf("11: Ordered List\n");
        printf("12: Merged Sort\n");
        printf("13: Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the Value To Be Inserted\n");
            scanf("%d",&val);
            first=insert_front(first,val);
            break;
        case 2:
            printf("Enter the Value\n");
            scanf("%d",&val);
            first=insert_end(first,val);
            break;
        case 3:
            printf("Enter the Value\n");
            scanf("%d",&val);
            printf("Enter the position to be inserted\n");
            scanf("%d",&pos);
            first=insert_pos(first,val,pos);
            break;
        case 4:
            first=delete_front(first);
            break;
        case 5:
            first=delete_end(first);
            break;
        case 6:
            printf("Enter the position from which element has to be deleted\n");
            scanf("%d",&pos);
            first=delete_pos(first,pos);
            break;
        case 7:
            display(first);
            break;
        case 8:
            first=reverse(first);
            break;
        case 9:
            sort(first);
            break;
        case 10:
            printf("Enter the Number of nodes In List 1\n");
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                printf("Enter the Item To Be Inserted\n");
                scanf("%d",&val);
                a=insert_end(a,val);
            }
            printf("Enter the Number of nodes In List 2\n");
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                printf("Enter the Item To Be Inserted\n");
                scanf("%d",&val);
                b=insert_end(b,val);
            }
            a=concat(a,b);
            display(a);
            break;
        case 11:
            printf("Enter the Value\n");
            scanf("%d",&val);
            first=order_list(first,val);
            break;

        case 12:
            printf("Enter the Number of Nodes in  The List \n");
            scanf("%d",&n);
            printf("Enter the Items In Ascending order for list 1\n");
            for(int i=0;i<n;i++)
            {
                printf("Enter the item %d to be inserted at List 1 \n",(i+1));
                scanf("%d",&val);
                a=insert_end(a,val);
            }
            printf("Enter the item in ascending order for list 2\n");
            for(int i=0;i<n;i++)
            {
                printf("Enter the item %d to be inserted at List 1 \n",(i+1));
                scanf("%d",&val);
                b=insert_end(b,val);
            }
            ans=merged_sort(a,b);
            display(ans);
            break;

        }
    }while(choice!=13);
}

