#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
struct node
{
	 int info;
	 struct node *llink;
	 struct node *rlink;
	 };
typedef struct node *NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("mem full\n");
		exit(0);
		}
	return x;
	}
void freenode(NODE x)
{
	free(x);
}
NODE dinsert_front(int item,NODE head)
{
NODE temp,cur;
temp=getnode();
temp->info=item;
cur=head->rlink;
head->rlink=temp;
temp->llink=head;
temp->rlink=cur;
cur->llink=temp;
return head;
}
NODE dinsert_rear(int item,NODE head)
{
NODE temp,cur;
temp=getnode();
temp->info=item;
cur=head->llink;
head->llink=temp;
temp->rlink=head;
temp->llink=cur;
cur->rlink=temp;
return head;
}
NODE ddelete_front(NODE head)
{
NODE cur,next;
if(head->rlink==head)
{
printf("dq empty\n");
return head;
}
cur=head->rlink;
next=cur->rlink;
head->rlink=next;
next->llink=head;
printf("the node deleted is %d",cur->info);
freenode(cur);
return head;
}
NODE ddelete_rear(NODE head)
{
NODE cur,prev;
if(head->rlink==head)
{
printf("dq empty\n");
return head;
}
cur=head->llink;
prev=cur->llink;
head->llink=prev;
prev->rlink=head;
printf("the node deleted is %d",cur->info);
freenode(cur);4
return head;
}
void display(NODE head)
{
NODE temp;
if(head->rlink==head)
{
printf("dq empty\n");
return;
}
printf("contents of dq\n");
temp=head->rlink;
while(temp!=head)
{
printf("%d\n",temp->info);
temp=temp->rlink;
}
printf("\n");
}
NODE insert_leftpos(int item,NODE head)
{
NODE temp,cur,prev;
if(head->rlink==head)
{
printf("list empty\n");
return head;
}
cur=head->rlink;
while(cur!=head)
{
if(item==cur->info)break;
cur=cur->rlink;
}
if(cur==head)
{
 printf("key not found\n");
 return head;
 }
 prev=cur->llink;
 printf("enter towards left of %d=",item);
 temp=getnode();
 scanf("%d",&temp->info);
 prev->rlink=temp;
 temp->llink=prev;
 cur->llink=temp;
 temp->rlink=cur;
 return head;
}
NODE insert_rightpos(int item,NODE head)
{

    NODE temp,cur,prev;
    if(head->rlink==head)
    {
        printf("Empty List\n");
        return head;
    }
    cur=head->rlink;
    while(cur!=head)
    {
       if(item==cur->info)break;
       cur=cur->rlink;
    }
    if(cur==head)
    {
      printf("key not found\n");
      return head;
    }
    prev=cur->llink;
    printf("enter towards right of %d=",item);
    temp=getnode();
    scanf("%d",&temp->info);
    temp->rlink=cur->rlink;
    temp->llink=cur;
    cur->rlink=temp;
    return head;

}

void search(NODE head)

{

NODE ptr;

int item,i=0,flag;

ptr = head;

if(ptr == NULL)

{

printf("\nEmpty List\n");

}

else

{

printf("\nEnter item which you want to search?\n");

scanf("%d",&item);

while (ptr!=NULL)

{

if(ptr->info == item)

{

printf("\nitem found at location %d ",i);

flag=0;

break;

}
else
{

flag=1;

}

i++;

ptr = ptr -> rlink;

}

if(flag==1)

{
printf("\nItem not found\n");
return;
}

}

}
NODE delete_all_key(int item,NODE head)
{
NODE prev,cur,next;
int count;
   if(head->rlink==head)
    {
     printf("LE");
     return head;
     }
count=0;
cur=head->rlink;//-----find the address of first node
while(cur!=head)
{
  if(item!=cur->info)
  cur=cur->rlink;
  else
 {
  count++; //---- udate the number of occurances
  prev=cur->llink;
  next=cur->rlink;
  prev->rlink=next;
  next->llink=prev;
  freenode(cur);
  cur=next; //----search continues again
 }
}
if(count==0)
  printf("key not found\n");
  else
 printf("key found at %d positions and are deleted\n", count);

return head;
}
void main()
{
NODE head,last;
int item, choice;
head=getnode();
head->rlink=head;
head->llink=head;
for(;;)
{
	printf("\n1:insert front\n2:insert rear\n3:delete front\n4:delete rear\n5:display\n6:Insert Left\n7: remove duplicates\n8: Search\n9:Insert Right\n 10:Exit\n");
	printf("enter the choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("enter the item at front end\n");
			scanf("%d",&item);
			last=dinsert_front(item,head);
			break;
		case 2: printf("enter the item at rear end\n");
			scanf("%d",&item);
			last=dinsert_rear(item,head);
			break;
		case 3:last=ddelete_front(head);
			break;
		case 4: last=ddelete_rear(head);
			break;
		case 5: display(head);
			break;
        case 6:
         printf("enter the key item\n");
		 scanf("%d",&item);
		 head=insert_leftpos(item,head);
		 break;
        case 7:
            printf("Enter the item whose duplicates you want to remove\n");
            scanf("%d",&item);
            head=delete_all_key(item,head);
            break;
        case 8:
            search(head);
            break;
        case 9:
         printf("enter the key item\n");
		 scanf("%d",&item);
		 head=insert_rightpos(item,head);
		 break;

		default:exit(0);

		}
	}
}
