//https://www.techiedelight.com/intersection-two-given-sorted-linked-lists/

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

struct node *sortedIntersect(struct node *a,struct node *b)
{
   struct node *pa=a;
   struct node *pb=b;
   struct node *temp=NULL;

   int i,j;
   int data[5];
   int count=0;

   while(pa!=NULL && pb!=NULL)
   {
     if(pa->data<pb->data) pa=pa->next;
     else if(pa->data > pb->data ) pb=pb->next;
     else if( pa->data ==pb->data) movenode(&temp,&pa);
   }
   reverse(&temp);
   return temp;

}
int main()
{
  // input keys
  int keys[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int n = sizeof(keys)/sizeof(keys[0]);
  int i;

  struct node* a = NULL;
  for (i = n - 1; i >=0; i = i - 3) {
      push(&a, keys[i]);
  }

  struct node* b = NULL;
  for (i = n - 1; i >=0; i = i - 2) {
      push(&b, keys[i]);
  }

  // print both lists
  printf("First List: ");
  printList(a);

  printf("\nSecond List: ");
  printList(b);

  struct node* head = sortedIntersect(a, b);

  printf("\nAfter Intersection: ");
  printList(head);


}
