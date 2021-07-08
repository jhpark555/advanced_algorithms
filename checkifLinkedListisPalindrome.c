//https://www.techiedelight.com/recursively-check-linked-list-characters-palindrome-or-not/
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
    printf("%c->",curr->data);
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

int compare(struct node *a,struct node *b)
{
  while(a!=NULL && b!=NULL)
  {
    if(a->data !=b->data)
    return 0;

    a=a->next;
    b=b->next;
  }
  return 1;
}
int isPalindrome(struct node **headref)
{
  int ret;
   struct node *curr=*headref;
   struct node *rev=*headref;

   reverseList(&rev);

   ret= compare(curr,rev);

   return ret;
}

int main()
{
  int m = 2, n = 5;
  int i;
  int arr[]={'A','B','C','B','A'};

  struct node* head = NULL;
  for (i = 4; i >= 0; i--) {
      push(&head, arr[i]);
  }

  printList( head);
  printf("\n");
  int ret= isPalindrome(&head);
  if(ret) printf("Yes Palindrom \n");
  else printf("No not palindrom \n");
  return 0;

}
