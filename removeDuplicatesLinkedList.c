//https://www.techiedelight.com/remove-duplicates-linked-list/

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
//hash map method used
void removeDuplicates(struct node *head)
{
  struct node *curr=head;
  struct node *prev=head;
  int map[100]={0};
  int max=-1;
  int i;

  while(curr!=NULL) {
    if( curr->data >max) max=curr->data;
     curr=curr->next;
   }

  for(i=0;i<=max;i++) map[i]=0;

  curr=head;

  while(curr!=NULL)
  {
      map[curr->data]++;
    if(map[curr->data] >1)   // if data is duplicates
    {
      prev->next=curr->next;
    }
    else{
      prev=curr;
    }
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

int main()
{
//  int keys[]={5,3,4,2,5,4,1,3};
  int keys[]={11,11,11,13,13,20};
  int n= sizeof(keys)/sizeof(keys[0]);
  int i;

  struct node *head= NULL;

  // construct a linked list
  for (i = n-1; i >= 0; i--) {
      push(&head, keys[i]);
  }

  printList(head);
  removeDuplicates(head);
  // print linked list
  printf("\n");
  printList(head);
}
