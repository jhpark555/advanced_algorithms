#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findPair(int arr[],int n,int diff)
{
  int i,j,k;
  int temp=0;

  for(i=0;i <n; i++)
  {
    temp=0;
    for(j=i+1 ;j< n; j++)
    {
      temp=fabs(arr[i]-arr[j]);
      if(temp==diff){
         printf("%d %d \n",arr[i],arr[j]);
       }
    }
  }
}
int main()
{
   int arr[] = { 1, 5, 2, 2, 2, 5, 5, 4};
   int diff = 4;

   int n = sizeof(arr) / sizeof(arr[0]);

   findPair(arr, n, diff);

  return 0;
}
