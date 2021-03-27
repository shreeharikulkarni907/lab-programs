
#include<stdio.h>
#include<stdlib.h>
#define N 3
int queue[3][N];
int front[3]={0,0,0};
int rear[3]={-1,-1,-1};
int item,pr;
int pqinsert();
int pqdelete();
int display();
int main()
{
int ch;

while(1)
{
printf("PRIORITY QUEUE\n");
printf("*****************\n");
printf("\n\t 1:PQinsert\n");
printf("\n\t 2:PQdelete\n");
printf("\n\t 3:PQdisplay\n");
printf("\n\t 4:Exit\n");
printf("\n enter the choice\n");
scanf("%d",&ch);
switch(ch)
{
 case 1:printf("\n enter the priority number\n");
		scanf("%d",&pr);
		if(pr>0 && pr<4)
		pqinsert(pr-1);
		else
		printf("only 3 priority exists 1 2 3\n");
		break;
case 2:pqdelete();
	   break;
case 3:display();
	   break;
case 4:exit(0);
}
}

}
int pqinsert(int pr)
{
 if(rear[pr]==N-1)
 printf("\n Queue overflow\n");
 else
 {
 printf("\nenter the item\n");
 scanf("%d",&item);
 rear[pr]++;
 queue[pr][rear[pr]]=item;
 }
 return 0;
}
int pqdelete()
{
int i;
for(i=0;i<3;i++)
{
  if(rear[i]==front[i]-1)
  printf("queue empty\n");
  else
  {
  printf("deleted item is %d of queue %d\n",queue[i][front[i]],i+1);
  front[i]++;
  return 0;
  }
 }
}
int display()
{
int i,j;
for(i=0;i<3;i++)
{
if(rear[i]==front[i]-1)
  printf("queue empty %d\n",i+1);
else
  {
  printf("\nQUEUE %d:",i+1);
  for(j=front[i];j<=rear[i];j++)
    printf("%d\t",queue[i][j]);
  }
}
  return 0;
}
