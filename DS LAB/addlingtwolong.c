#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
    int item;
    struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{

    NODE x=(NODE)malloc(sizeof(struct node));
    return x;
}
NODE insert_front(NODE first,int data)
{
    NODE new_node;
    new_node=getnode();
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
NODE process(NODE head,char s[])
{
    int n;
    for(int i=0;i<strlen(s);i++)
    {
        n=s[i]-'0';
        head=insert_front(head,n);
    }
    return head;

}
NODE addlong(NODE head1,NODE head2,NODE head3)
{
    NODE cur1,cur2;
    int sum,temp;
    int carry=0;
    cur1=head1;
    cur2=head2;
    while(cur1!=NULL&&cur2!=NULL)
    {
        temp=cur1->item+cur2->item;
        if(temp>9)
        {
            sum=temp%10;
            carry=temp/10;
        }
        else
        {
            sum=temp;
            carry=0;
        }
        head3=insert_front(head3,sum);
        cur1=cur1->next;
        cur2=cur2->next;
    }
    while(cur1!=NULL)
    {
        temp=cur1->item+carry;
        if(temp>9)
        {
            sum=temp%10;
            carry=temp/10;
        }
        else
        {
            sum=temp;
            carry=0;
        }
        head3=insert_front(head3,sum);
        cur1=cur1->next;
    }
    while(cur2!=NULL)
    {
        temp=cur2->item+carry;
        if(temp>9)
        {
            sum=temp%10;
            carry=temp/10;
        }
        else
        {
            sum=temp;
            carry=0;
        }
        head3=insert_front(head3,sum);
        cur2=cur2->next;
    }
    return head3;
}
void display(NODE head3)
{

    NODE temp;
    if(head3==NULL)
    {
        printf("List Is Empty\n");
    }
    for(temp=head3;temp!=NULL;temp=temp->next)
    {
        printf("%d\t",temp->item);
    }
}
int main()
{
    NODE head1=NULL;
    NODE head2=NULL;
    NODE head3=NULL;
    char str1[50];
    char str2[50];
    printf("Enter the First Long Integer\n");
    scanf("%s",str1);
    head1=process(head1,str1);
    printf("Enter the second Long Integer\n");
    scanf("%s",str2);
    head2=process(head2,str2);
   // display(head1);
    //display(head2);
    head3=addlong(head1,head2,head3);
    printf("final sum is  \n");
    display(head3);
}
