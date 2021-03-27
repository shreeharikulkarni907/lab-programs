#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int expx;
    int expy;
    struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{

    NODE x=(NODE)malloc(sizeof(struct node));
    return x;
}
NODE insert_end(NODE first,int co,int exx,int exy)
{
    NODE last;
    NODE new_node;
    new_node=getnode();
    new_node->coeff=co;
    new_node->expx=exx;
    new_node->expy=exy;
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
NODE addpolynomial(NODE head1,NODE head2,NODE head3)
{
    NODE cur1,cur2;
    cur1=head1;
    cur2=head2;
    while(cur1!=NULL&&cur2!=NULL)
    {
        if((cur1->expx==cur2->expx)&&(cur1->expy==cur2->expy))
        {
            head3=insert_end(head3,cur1->coeff+cur2->coeff,cur1->expx,cur1->expy);
            cur1=cur1->next;
            cur2=cur2->next;
        }
        else
        {
            if(cur1->coeff>cur2->coeff)
            {
                head3=insert_end(head3,cur1->coeff,cur1->expx,cur1->expy);
                cur1=cur1->next;
                //cur2=cur2->next;
            }
            else
            {
                head3=insert_end(head3,cur2->coeff,cur2->expx,cur2->expy);
                cur2=cur2->next;
                //cur1=cur1->next;
            }
        }
    }
    while(cur1!=NULL)
    {
        head3=insert_end(head3,cur1->coeff,cur1->expx,cur1->expy);
        cur1=cur1->next;
    }
    while(cur2!=NULL)
    {
        head3=insert_end(head3,cur2->coeff,cur2->expx,cur2->expy);
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
        printf("%d x^%dy^%d + \t",temp->coeff,temp->expx,temp->expy);
    }
}
int main()
{
    int n,cf,e1,e2;
    NODE head1=NULL;
    NODE head2=NULL;
    NODE head3=NULL;
    printf("Enter the Number Of Terms In Polynomial 1\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the coeffcient of term %d \n",(i+1));
        scanf(" %d",&cf);
        printf("Enter the Power of X  \n");
        scanf(" %d",&e1);
        printf("Enter the Power of y  \n");
        scanf(" %d",&e2);
        head1=insert_end(head1,cf,e1,e2);
    }
    printf("Enter the Number Of Terms In Polynomial 2\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the coeffcient of term %d \n ",(i+1));
        scanf(" %d",&cf);
        printf("Enter the Power of X \n");
        scanf(" %d",&e1);
        printf("Enter the Power of Y \n");
        scanf(" %d",&e2);
        head2=insert_end(head2,cf,e1,e2);
    }
    printf("Final Result Polynomial is \n");
    head3=addpolynomial(head1,head2,head3);
    display(head3);
}
