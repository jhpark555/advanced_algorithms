#include <stdio.h>
#include <stdlib.h>

void findminIndex(int arr[],int n)
{
  int map[n];
  int i,j;
  int min=100;
  int element;

  for(i=0;i< n;i++) map[i]= 0;

  for( i=0; i< n;i++)
  map[arr[i]]++;

  for( i=0;i <n; i++)
  {
    printf("*%d  \n",map[arr[i]]);
    if(map[arr[i]] < min ) {
      min= map[arr[i]];
      element= arr[i];
    }
    //else continue;     //if not less than min, continue
  }

  printf("Min=%d  %d",min,element);
}

int main()
{
  int arr[]={5,6,3,4,3,6,4};
  int n=sizeof(arr)/sizeof(arr[0]);

  findminIndex(arr,n);
}
