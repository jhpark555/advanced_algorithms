//https://www.techiedelight.com/merge-alternate-nodes-two-linked-lists/

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

struct node  *shuffleMerge(struct node *aref,struct node *bref)
{
    struct node *temp=NULL;
    struct node **lastptr=&temp;
    struct node *pa=aref;
    struct node *pb=bref;

    while(pa !=NULL || pb!=NULL )
    {
      movenode(lastptr,&pa);
      lastptr=&((*lastptr)->next);
      movenode(lastptr,&pb);
      lastptr=&((*lastptr)->next);
    }

  return temp;
}

int main()
{
  // input keys
   int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
   int n = sizeof(keys)/sizeof(keys[0]);

   struct node *a = NULL, *b = NULL;
   for (int i = n - 1; i >= 0; i = i - 2) {
       push(&a, keys[i]);
   }

   for (int i = n - 2; i >= 0; i = i - 2) {
       push(&b, keys[i]);
   }

   // print both lists
   printf("First List: ");
   printList(a);

   printf("\nSecond List: ");
   printList(b);

   struct node* head = shuffleMerge(a, b);
   printf("\nAfter Merge: ");
   printList(head);

   return 0;

}
