//https://www.geeksforgeeks.org/bubble-sort-for-linked-list-by-swapping-nodes/
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

void bubbleSort(struct node **headref,int n)
{
  struct node **h;
  int i,j;

  for(i=0;i<n;i++)
  {
    h=headref;
    for(j=0;j<n-i-1;j++)
    {
      struct node *p1=*h;
      struct node *p2=p1->next;
      if(p1->data > p2->data) {
        *h=swap(p1,p2);
      }
      h=&(*h)->next;
    }
  }

}
int main()
{
  // input coordinates
   int arr[]={78,20,10,32,1,5};
   int n = sizeof(arr) / sizeof(arr[0]);
   int i;


   struct node* head = NULL;
   for (i = n - 1; i >= 0; i--) {
       push(&head, arr[i]);
   }

   printList(head); printf("\n");
   bubbleSort(&head,n); printf("\n");
//   KreverseList(&head,k);printf("\n");
    printList(head);
  return 0;

}
