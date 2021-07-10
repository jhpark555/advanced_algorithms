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

void rearrange(struct node **headref,int k)
{
  struct node *curr=*headref;
  struct node *prev=NULL;
  struct node *Next=NULL;

  while(curr->data !=k)
  {
     curr=curr->next;
  }
   Next=curr->next;
   curr->next=NULL;
   reverse(headref);
   curr=*headref;

   while(curr->next!=NULL)
   {
      curr=curr->next;
   }
   curr->next=Next;

}


int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    unsigned n = sizeof(arr)/sizeof(arr[0]);
    int i;
    int k=4;

    struct node* head = NULL;
    for (i = n - 1; i >= 0; i--) {
        push(&head, arr[i]);
    }

    printList(head);
    rearrange(&head,k);
    printf("\n");
    printList(head);
  return 0;

}
