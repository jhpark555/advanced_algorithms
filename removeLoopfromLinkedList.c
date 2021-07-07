//https://www.techiedelight.com/remove-loop-linked-list/
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

void printList(struct node *head)
{
  struct node *curr=head;

  while(curr!=NULL)
  {
    printf("%d->",curr->data);
    curr=curr->next;
  }
}

#if 0
// Hash map use
void removeCycle(struct node *head)
{
  struct node *curr=head;
  struct node *prev=head;

  int map[100];
  int i;


  for(i=0;i<100;i++) map[i]=0;

  while(curr->next!=NULL)
  {
    prev=curr;
    curr=curr->next;     // to in advance one step ahead

    map[curr->data]++;
    if( map[curr->data] >1 )
    {
      printf("crossed node is %d \n",curr->data);
      prev->next=NULL;
      break;
    }
  }
}
#else
//Floyd's cycle method
void removeCycle(struct node *head)
{
   struct node *slow=head;
   struct node *fast=head;

   while(slow)
   {
     slow=slow->next;
     fast=fast->next->next;

     if(slow==fast)
     {
       printf("Meet at %d \n",slow->data);
       break;
     }
   }

   struct node *new=slow;
   struct node *curr=head;
   while(new!=NULL)
   {
     if(curr->next->data== new->next->data){
       new->next=NULL;
       break;
     }
     new=new->next;
     curr=curr->next;
   }

}

#endif
void push(struct node **head,int data)
{
   struct node *new=(struct node*)malloc(sizeof(struct node));
   new->data=data;
   new->next=*head;
   *head=new;
}

int main()
{
  int n=5;
  int i;
  struct node *head=NULL;
  // construct a linked list
  for (i = n; i > 0; i--) {
      push(&head, i);
  }

  // insert cycle
  head->next->next->next->next->next = head->next;

  removeCycle(head);
  // print linked list
  printList(head);
}
