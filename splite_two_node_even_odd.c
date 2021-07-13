//https://www.techiedelight.com/split-linked-list-into-two-lists-list-containing-alternating-elements/

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
  printf("NULL");
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

void movenode(struct node **dst,struct node **src)
{
  struct node *temp;

  if(*src ==NULL) return ;
  temp=*src;
  (*src)=(*src)->next;
  temp->next=*dst;
  *dst=temp;
}

void alternatingSplit(struct node *head,struct node **aref,struct node **bref)
{
  struct node *curr=head;
  struct node *a=NULL;
  struct node *b=NULL;

  while(curr!=NULL  )
  {
    if(curr->data &1) {
      movenode(&a,&curr);
    }
    else
    {
      movenode(&b,&curr);
    }

  }
  *aref=a;
  *bref=b;

}

int main()
{
  // input keys
   int keys[] = { 1, 2, 3, 4, 5, 6, 7 ,8};
   int n = sizeof(keys)/sizeof(keys[0]);

   // construct the first linked list
   struct node* head = NULL;
   for (int i = n-1; i >= 0; i--) {
       push(&head, keys[i]);
   }

   struct node *a = NULL, *b = NULL;
   alternatingSplit(head, &a, &b);

   // print both lists
   printf("First List: ");
   printList(a);

   printf("Second List: ");
   printList(b);

  return 0;

}
