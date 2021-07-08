//https://www.techiedelight.com/add-single-digit-number-linked-list-representing-number/
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

void addDigit(struct node **headref,int digit)
{
    reverseList(headref);

    struct node *curr=*headref;
    int carry=digit;

    while(carry)
    {
      int sum =curr->data +carry;
      curr->data = sum %10;
      carry =sum /10;

      if( curr->next ==NULL) break;

      curr=curr->next;
    }

    reverseList(headref);
    if(carry) push(headref,carry);
}


int main()
{
  // input coordinates
   int arr[]={9,9,9,9,3};
   int n = sizeof(arr) / sizeof(arr[0]);
   int i;
   int digit=7;

   struct node* head = NULL;
   for (i = n - 1; i >= 0; i--) {
       push(&head, arr[i]);
   }

   printList(head);
   addDigit(&head, digit);
   printf("\n");
   printList(head);
  return 0;

}
