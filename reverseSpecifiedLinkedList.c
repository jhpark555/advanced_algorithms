//https://www.techiedelight.com/reverse-specified-portion-linked-list/

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

void push(struct node **head,int data)
{
   struct node *new=(struct node*)malloc(sizeof(struct node));
   new->data=data;
   new->next=*head;
   *head=new;
}

void reverseList(struct node **headref)
{
  struct node *curr=*headref;
  struct node *Next=NULL;
  struct node *prev=NULL;

  while(curr!=NULL)
  {
    Next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=Next;
  }
  *headref=prev;
}

#if 0
void reverse(struct node **headref,int m,int n)
{
  struct node *curr=*headref;
  struct node *prev=NULL;

  while(curr->data !=m )
  {
    prev=curr;
    curr=curr->next;
  }

  struct node *start=curr;
  struct node *stop=NULL;
  struct node *Next=NULL;

  while(curr->data !=n+1)     //1->stop->......>start->curr
  {
    Next=curr->next;
    curr->next=stop;
    stop=curr;
    curr=Next;
  }

  start->next=curr;
  if(prev !=NULL){
    prev->next=stop;
  }
  else{
    *headref=stop;
  }
}

#else
void reverse(struct node **headref,int m,int n)
{
    struct node *curr=*headref;
    struct node *prev=NULL;
    struct node *start=NULL;

    while(curr!=NULL)
    {
      prev=curr;
      curr=curr->next;
      if(curr->data= m)
      {
         start=curr;
         prev->next=NULL;
         break;
      }
    }

  struct node *Next=NULL;
   while(curr!=NULL)
   {
     curr=curr->next;
     if(curr->data ==n){
       Next=curr->next;
       curr->next=NULL;
       break;
     }
   }

   reverseList(&start);

   curr=start;     // curr should be reset to point start again

   while(curr!=NULL)
   {
     curr=curr->next;
     if(curr->data == m){    //traverse until to m due to reversed m/n
       break;
     }
   }
   //printf("\n>>>>>>>>>>>>>>\n");
   //printList(start);
   //printf("\n>>>>>>>>>>>>>>\n");

   prev->next=start;
   //printf("**data=%d \n",curr->data);
   curr->next=Next;

}
#endif
int main()
{
  int m = 2, n = 5;
  int i;

  struct node* head = NULL;
  for (i = 7; i >= 1; i--) {
      push(&head, i);
  }

  printList( head);
  reverse(&head, m, n);
  printf("\nreversed :\n");
  printList(head);

  return 0;

}
