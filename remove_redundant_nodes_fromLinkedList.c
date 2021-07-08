//https://www.techiedelight.com/remove-redundant-nodes-path-formed-linked-list/
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int x,y;
  struct node *next;
};

void printList(struct node *head)
{
  struct node *curr=head;

  while(curr!=NULL)
  {
    printf("(%d,%d)->",curr->x,curr->y);
    curr=curr->next;
  }
}

void push(struct node **head,int x,int y)
{
   struct node *new=(struct node*)malloc(sizeof(struct node));
   new->x=x;
   new->y=y;
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

void removeNodes( struct node **headref)
{
   struct node *curr=*headref;
   struct node *Next=NULL;

   while(curr->next!=NULL && curr->next->next)
   {
     Next=curr->next->next;
     if(curr->x == curr->next->x && curr->x==Next->x ){
       free(curr->next);
       curr->next=Next;
      // printf("*%d ",curr->x);
     }
     else if(curr->y ==curr->next->y && curr->y ==Next->y){
       free(curr->next);
       curr->next=Next;
      //  printf("#%d ",curr->y);
     }
     else{
       curr=curr->next;
      //  printf("$%d ",curr->x);
     }
   }
}

int main()
{
  // input coordinates
   int keys[][2] = { {0, 1}, {0, 5}, {0, 8}, {2, 8},
                   {5, 8}, {7, 8}, {7, 10}, {7, 12} };

   int n = sizeof(keys) / sizeof(keys[0]);
   int i;

   struct node* head = NULL;
   for (i = n - 1; i >= 0; i--) {
       push(&head, keys[i][0], keys[i][1]);
   }

   removeNodes(&head);
   printList(head);
  return 0;

}
