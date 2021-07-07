//https://www.techiedelight.com/find-intersection-point-of-two-linked-lists/
//find the intersection point of two linked lists

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

//Usimg Floyd method
struct node *findIntersection(struct node *first,struct node *second)
{
   struct node *curr=first;

   while(curr->next!=NULL)
   {
     curr=curr->next;
   }
   curr->next=first;      // make first list as cycle

   curr=first;
   struct node *temp=second;

   while(curr!=NULL)
   {
     curr=curr->next;
     temp=temp->next->next;
    //  printf("**%d,%d  \n",curr->data,temp->data);
     if(temp==curr) {       //meet in the loop
      // printf("**%d \n",temp->data);
       break;
     }
   }

   struct node *start=second;
   while(start!=NULL)
   {
     start=start->next;
     curr=curr->next;
     if(start==curr)
     {
       //printf("**%d \n",start->data);
       return start;
     }
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
   int i;
  // construct the first linked list (1 —> 2 —> 3 —> 4 —> 5 —> null)
   struct node* first = NULL;
   for (i = 5; i > 0; i--) {
       push(&first, i);
   }

   // construct the second linked list (1 —> 2 —> 3 —> null)
   struct node* second = NULL;
   for (i = 3; i > 0; i--) {
       push(&second, i);
   }

   // link tail of the second list to the fourth node of the first list
   second->next->next->next = first->next->next->next;

   struct node* addr = findIntersection(first, second);
   if (addr) {
       printf("The intersection point is %d \n",addr->data);
   }
   else {
       printf("The lists do not intersect.\n");
   }
   // print linked list
   //printList(head);
   return 0;

}
