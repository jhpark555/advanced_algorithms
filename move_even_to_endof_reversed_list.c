//https://www.techiedelight.com/pairwise-swap-adjacent-nodes-linked-list/
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

void reverse(struct node **headref)
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

struct node *swap(struct node *N1,struct node *N2)
{
  struct node *Next=NULL;

  Next=N2->next;
  N2->next=N1;
  N1->next=Next;

  return N2;
}

void rearrange(struct node **headref)
{
  struct node *curr=*headref;
  struct node dummy;
  struct node *temp=&dummy;

  while(curr!=NULL)
  {
    if(curr->data &1)  //odd
     movenode(&temp,&curr);
     curr=curr->next;
  }
   *headref=temp;
}

void movenode(struct node **dst,struct node **src)
{
  struct node *temp;

  temp=*src;
  (*src)=(*src)->next;
  temp->next=*dst;
  *dst=temp;
}

int main()
{
  // input keys
  int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
  int n = sizeof(keys)/sizeof(keys[0]);

  // construct the first linked list
  struct Node* head = NULL;
  for (int i = n-1; i >= 0; i--) {
      push(&head, keys[i]);
  }

  printf("Before: ");
  printList(head);

  // rearrange the pointers of a given list
  rearrange(&head);

  printf("After: ");
  printList(head);

  return 0;

}
