#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>

struct node
{
    int data;
    struct node *next;
};

void insert_front(struct node**head_ref,int dat)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));

    new_node->data=dat;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

void insert_end(struct node**head_ref,int dat)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    struct node *last=*head_ref;

    new_node->data=dat;
    new_node->next=NULL;
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
    }
    else
    {
        while(last->next!=NULL)
        {
            last=last->next;
        }
    }
    last->next=new_node;
}

void insert_pos(struct node**head_ref,int pos,int item)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    struct node *last=*head_ref;
    new_node->data=item;
    if(pos==1)
    {
        new_node->next=(*head_ref);
        (*head_ref)=new_node;
    }
    else{
    for(int i=1;i<pos-1;i++)
    {
        last=last->next;
    }
    new_node->next=last->next;
    last->next=new_node;
    }
}

void print(struct node *Node)
{
    while(Node!=NULL)
    {
        printf("%d\n",Node->data);
        Node=Node->next;
    }
}

void delete_front(struct node**head_ref)
{
    struct node *temp;
    struct node *last=(*head_ref);
    if(last==NULL)
    {
        printf("List Is Empty\n");
    }
    temp=last;
    last=last->next;
    free(temp);

}
void delete_end(struct node *head)
{
    struct node *prev;
    struct node *cur;
    if(head==NULL)
    {
        printf("List Is Empty And Cannot Be Deleted\n");
    }
    cur=head;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=NULL;
    free(cur);
}

void delete_pos(struct node *head,int pos)
{
    struct node *prev;
    struct node *cur;
    if(head==NULL)
    {
      printf("List Is empty \n");
    }
    cur=head;
    for(int i=1;i<pos;i++)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=cur->next;
    free(cur);

}

/*void reverse(struct node *head)
{
    struct node *cur;
    struct node *temp;
    if(head==NULL)
    {
        printf("List Is Empty\n");
    }
    cur=NULL;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        temp->next=cur;
        cur=temp;
    }
    printf("Elements in Reversed order are\n");
    while(cur!=NULL)
    {
        printf("%d\n",cur->data);
        cur=cur->next;
    }
}*/

int main()
{
    struct node *head=NULL;
    int choice,val,pos;
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
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the Value To Be Inserted\n");
            scanf("%d",&val);
            insert_front(&head,val);
            break;
        case 2:
            printf("Enter the Value To Be Inserted\n");
            scanf("%d",&val);
            insert_end(&head,val);
            break;
        case 3:
            printf("Enter the Value To Be Inserted\n");
            scanf("%d",&val);
            printf("Enter the position to be inserted\n");
            scanf("%d",&pos);
            insert_pos(&head,pos,val);
            break;

        case 4:
            delete_front(&head);
            break;
        case 5:
            delete_end(head);
            break;

        case 6:
            printf("Enter the position from which element has to be deleted\n");
            scanf("%d",&pos);
            delete_pos(head,pos);
            break;
        case 7:
            print(head);
            break;
        //case 8:
            //reverse(head);
            //break;

        }
    }while(choice!=9);
}


