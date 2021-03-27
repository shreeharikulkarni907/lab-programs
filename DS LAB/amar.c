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
//This IS for reversing the Linked List
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
void reverse_print(Node head) {
   if(head == NULL) {
      return;
   }
   reverse_print(head->next);
   printf(" %d\n",head->item);
}
Node reverseCopy(Node head) {
    Node newHead = NULL;
    Node temp;
    /* Input Validation */
    if (head == NULL) {
       printf("Error : Invalid node pointer !!!\n");
       return head;
    }

    while(head != NULL) {
        temp = getNode();
        temp->item = head->item;
        temp->next = newHead;
        newHead = temp;
        head = head->next;
    }
    return newHead;
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
int compareLinkedList(Node LLOne, Node LLTwo){
    while (LLOne != NULL && LLTwo != NULL)
    {
        if (LLOne->item != LLTwo->item)
            return 0;
        LLOne = LLOne->next;
        LLTwo = LLTwo->next;
    }
    return (LLOne == NULL && LLTwo == NULL);
}
int main()
{
    Node start=NULL;
    Node new_start=NULL;
    int n,num;
    printf("Enter the Number of nodes in the linked list\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the Number to be inserted\n");
        scanf("%d",&num);
        start=insert_end(start,num);
    }
    display(start);
    new_start=reverseCopy(start);
    printf("In Reverse Order is\n");
    display(new_start);
    if(compareLinkedList(start,new_start)){
        printf("\nPalindrome Linked List\n");
    } else {
        printf("\nNot a Palindrome Linked List\n");
    }
    printf("Reverse printing the linked list\n");
    reverse_print(start);
}
