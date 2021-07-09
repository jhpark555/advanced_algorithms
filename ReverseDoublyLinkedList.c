//Doubly Linked List Reverse

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *prev,*next;
};

void push(struct node **headref,int data)
{
  struct node *NewNode=(struct node*)malloc(sizeof(struct node));

  NewNode->data=data;
  NewNode->prev=NULL;
  NewNode->next=*headref;
  if(*headref!=NULL)
  {
    (*headref)->prev=NewNode;
  }
  *headref=NewNode;
}

void printDll(struct node *headref)
{
  struct node *curr=headref;
  while( curr!=NULL)
  {
    printf("%d<->",curr->data);
    curr=curr->next;
  }
}

void swap(struct node *node)
{
  struct node *prev=node->prev;
  struct node *Next=node->next;

  node->next=prev;
  node->prev=Next;
}

void ReverseDLL(struct node **headref)
{
  struct node *prev=NULL;
  struct node *curr=*headref;

  while(curr!=NULL)
  {
    swap(curr);    // swap next and prev pointer
  //  printf("**%d \n",curr->data);
    prev=curr;
    curr=curr->prev;
  }

  if(prev!=NULL)
  *headref=prev;
}

int main()
{
  int keys[]={1,2,3,4,5};
  int n=sizeof(keys)/sizeof(keys[0]);
  int i;

  struct node *head=NULL;

  for(i=0;i< n;i++) push(&head,keys[i]);

  printDll(head);
  ReverseDLL(&head);
//  reverseDDL(&head);
  printf("\n");
  printDll(head);
}
