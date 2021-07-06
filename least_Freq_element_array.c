//https://www.geeksforgeeks.org/least-frequent-element-array/
#include <stdio.h>
#include <stdlib.h>

int findleast(int arr[],int n)
{
  int i,j;
  int count[n];
  int min=100;
  int element;

  for(i=0;i<n;i++) count[i]=0;

  for( i= 0; i< n;i++)
  {
    count[arr[i]]++;
  }
  for(i=0;i<n;i++)
  {
    if(count[arr[i]] < min) {
       min= count[arr[i]];
       element=arr[i];
     }
    else continue;
  //  printf("[%d](%d) ",arr[i],count[arr[i]]);
  //  printf("Min=%d \n",min);
  }
//  for(i=0;i<n;i++) printf("[%d](%d) ",arr[i],count[arr[i]]);
   //printf("Min=%d arr=%d \n",min,element);
   return element;
}
int main()
{
  int arr[]={1,3,2,1,2,2,3,1};
  int n= sizeof(arr)/sizeof(arr[0]);

  int i,j;

  int ret= findleast(arr,n);
  printf("*minimum element= %d \n",ret);
}
