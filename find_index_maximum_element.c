#include <stdio.h>
#include <stdlib.h>

int *findIndex(int arr[],int n)
{
  int map[n];
  int i,j;
  int max=-1;
  int element;
  int count=0;
  static int ret[sizeof n]={-1};

  for(i=0;i< n;i++) map[i]= 0;

  for( i=0; i< n;i++)
  map[arr[i]]++;

  for( i=0;i <n; i++)
  {
    //printf("*%d  \n",map[arr[i]]);
    if(map[arr[i]] >= max ) {
      max= map[arr[i]];
      element= arr[i];
      ret[count++]=arr[i];
      printf("*%d %d \n",map[arr[i]],i);
    }
    //else continue;     //if not less than min, continue
  }

//  printf("Max=%d  %d",max,element);
 return ret;
}

int main()
{
  int arr[]={4, 3, 6, 8, 4, 6, 2, 4, 5, 9, 7, 4};
  int n=sizeof(arr)/sizeof(arr[0]);
  int i;

  int *ret=findIndex(arr,n);

  for(i=0;i<n;i++) printf("%d ",ret[i]);
}
