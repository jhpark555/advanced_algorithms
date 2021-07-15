#include <stdio.h>
#include <stdlib.h>


#define swap(a,b)  ( a^=b^=a^=b )

int  findKthLargest(int arr[],int k,int n)
{
  int i,j;
  int ret;

  //bubble sort
  for(i=0;i<n;i++)
  for(j=0;j<n-i-1;j++)
  {
    if(arr[j]<arr[j+1]) swap(arr[j],arr[j+1]);
  }
  ret= arr[k-1];

 return ret;

}

int main()
{
   int arr[]={7,4,6,3,9,1};
   int n=sizeof(arr)/sizeof(int);
   int k=2;
   int i;

   int ret=findKthLargest(arr,k,n);
   printf("*Kth =%d ",ret);
   return 0;

}
