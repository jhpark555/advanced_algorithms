#include <stdio.h>
#include <stdlib.h>

int getInvCount( int arr[], int n)
{
  int i,j;
  int count=0;

  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    {
      if(arr[i]>arr[j]) count++;
    }

    return count;
}

int main()
{
  // int arr[] = { 1, 20, 6, 4, 5 };
  int arr[]= {1, 9, 6, 4, 5};
   int n = sizeof(arr) / sizeof(arr[0]);
   printf(" Number of inversions are %d \n",
          getInvCount(arr, n));
   return 0;
}
