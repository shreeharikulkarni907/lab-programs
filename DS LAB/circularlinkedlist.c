#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
}
NODE insert_front(NODE last,int data)
{
    NODE new_node;
    new_node=getnode();
    new_node->info=data;
    if(last==NULL)
    {
        new_node->next=new_node;
        return new_node;
    }
    else
    {
        new_node->next=last->next;
        last->next=new_node;
        return last;
    }
}
NODE insert_rear(NODE last,int data)
{
    NODE new_node;
    new_node=getnode();
    new_node->info=data;
    if(last==NULL)
    {
        new_node->next=new_node;
        return new_node;
    }
    else
    {
        new_node->next=last->next;
        last->next=new_node;
        last=new_node;
        return  last;
    }
}

NODE insert_pos(NODE last,int pos,int data)
{
    NODE new_node,cur;
    new_node=getnode();
    new_node->info=data;
    if(last==NULL&&pos==1)
    {
        new_node->next=new_node;
        return new_node;
    }
    else if(pos==1)
    {
        new_node->next=last->next;
        last->next=new_node;
        return last;
    }
    else if(pos<1)
    {
        printf("Invalid Positionj\n");
        return last;
    }
    else
    {
        cur=last->next;
        for(int i=1;i<pos-1;i++)
        {
            cur=cur->next;
        }
        new_node->next=cur->next;
        cur->next=new_node;
        return last;
    }

}
NODE delete_front(NODE last)
{
    NODE temp;
    if(last==NULL)
    {
        printf("List Is Empty\n");
        return last;
    }
    else
    {
        temp=last->next;
        last->next=temp->next;
        free(temp);
        return last;
    }
}
NODE delete_end(NODE last)
{
    NODE prev,cur;
    if(last==NULL)
    {
        printf("List Is Empty\n");
        return last;
    }
    else
    {
        cur=last->next;
        while(cur!=last)
        {
            prev=cur;
            cur=cur->next;
        }
    }
    prev->next=cur->next;
    last=prev;
    free(cur);
    return last;
}
NODE delete_pos(NODE last,int pos)
{
    NODE prev,cur;
    if(last==NULL)
    {
        printf("List Is Empty\n");
        return last;
    }
    else if(pos==1)
    {
        last->next=(last->next)->next;
        free(last->next);
    }
    else
    {
        cur=last->next;
        for(int i=1;i<pos;i++)
        {
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        free(cur);
        return last;
    }

}
void display(NODE last)
{
    NODE i;
    if(last==NULL)
    {
        printf("List iS empty and Cannot Be Displayed\n");
        return;
    }
    for(i=last->next;i!=last;i=i->next)
    {
        printf("%d\n",i->info);
    }
    printf("%d\n",i->info);

}

int main()
{
    NODE last=NULL;
    int option,val,pos;
    do
    {
        printf("1:Insert at front\n");
        printf("2:Insert at end\n");
        printf("3:Insert at position\n");
        printf("4:Delete Front\n");
        printf("5:Delete End\n");
        printf("6:Delete at Position\n");
        printf("7:Display\n");
        printf("8:Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("Enter the value to be inserted\n");
            scanf("%d",&val);
            last=insert_front(last,val);
            break;
         case 2:
            printf("Enter the value to be inserted\n");
            scanf("%d",&val);
            last=insert_rear(last,val);
            break;
         case 3:
            printf("Enter the value to be inserted\n");
            scanf("%d",&val);
            printf("Enter the position At Which The Value Is To Be Inserted\n");
            scanf("%d",&pos);
            last=insert_pos(last,pos,val);
            break;

         case 4:
            last=delete_front(last);
            break;
         case 5:
            last=delete_end(last);
            break;
         case 6:
            printf("Enter the position At Which Number has to be deleted\n");
            scanf("%d",&pos);
            last=delete_pos(last,pos);
            break;

         case 7:
            display(last);
            break;

        }
    }while(option!=8);
}
