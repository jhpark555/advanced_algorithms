#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findFrequency(int arr[],int n)
{
  int i;
  int map[n];

  for(i=0;i <n; i++) map[i]=0;

  for(i =0; i< n; i++)
  {
    map[arr[i]]++;
  }

  for(i=0;i< n; i++){
     if(map[arr[i]]> 1)    //duplicated
     printf("%d %d \n",arr[i], map[arr[i]]);
  }



}
int main()
{
    // int A[] = { 2, 2, 2, 4, 4, 4, 5, 5, 6, 8, 8, 9};
    int A[]={2, 3, 4, 5, 4, 6, 4, 7, 4, 5, 6, 6} ;
     int n = sizeof(A) / sizeof(A[0]);

     findFrequency(A, n);



     return 0;
}
