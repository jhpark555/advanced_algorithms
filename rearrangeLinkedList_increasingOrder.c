
//https://www.techiedelight.com/given-linked-list-change-sorted-order/

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

void sortedInsert(struct node **headref,struct node *newNode)
{
   struct node dummy;
   struct node *curr=&dummy;
   dummy.next=*headref;

   while(curr->next!=NULL && curr->next->data < newNode->data)
   {
     curr=curr->next;
   }
   newNode->next=curr->next;
   curr->next=newNode;
   *headref=dummy.next;
}
void insertSort(struct node **headref)
{
  struct node *curr=*headref;
  struct node *result=NULL;
  struct node *Next;

  while(curr!=NULL)
  {
    Next=curr->next;
    sortedInsert(&result,curr);
    curr=Next;
  }
    *headref=result;
}
int main()
{
  // input keys
   int keys[] = {6, 3, 4, 8, 2, 9};
   int n = sizeof(keys)/sizeof(keys[0]);
   int i;

   // points to the head node of the linked list
   struct node* head = NULL;

   // construct a linked list
   for (i = n-1; i >= 0; i--) {
       push(&head, keys[i]);
   }

   printList(head);

   insertSort(&head);
   printf("\n");
   // print linked list
   printList(head);
 return 0;

}
