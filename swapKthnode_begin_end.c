//https://www.techiedelight.com/swap-kth-node-beginning-with-kth-node-end/

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

void swapNodes(struct node **headref,int k)
{
   struct node *prev=NULL;
   struct node *prev2=NULL;
   struct node *curr=*headref;
   struct node *n1=NULL;
   struct node *n2=NULL;
   struct node *Next=NULL;
   int count=0;

   while(count++<k)
   {
     prev=curr;
     curr=curr->next;
   }
    n1=curr;     //first k node
    Next=curr->next;
   //printf("**n1=%d \n",n1->data);
   reverse(headref);
   struct node *rev=*headref;
   count=0;
   while(count++<k)     // end kth data was calculated by revere the list.
   {
     rev=rev->next;
   }
    int temp=rev->data;
    reverse(headref);
   while(curr->data !=temp)
   {
     prev2=curr;
     curr=curr->next;
   }
   n2=curr;

   struct node *NNext=n2->next;
   n2->next=Next;
   n1->next=NNext;
   prev->next=n2;
   prev2->next=n1;

}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    unsigned n = sizeof(arr)/sizeof(arr[0]);
    int i;
    int k=2;

    struct node* head = NULL;
    for (i = n - 1; i >= 0; i--) {
        push(&head, arr[i]);
    }

    printList(head);
    swapNodes(&head,k);
    printf("\n");
    printList(head);
  return 0;

}
