#include <stdio.h>
#include <stdlib.h>

int *findFrequency(int arr[],int n)
{
  int i,j;
  int map[n];
  static int temp;
  static int ret[sizeof n];

  for(i=0;i<n;i++) map[i]=0;

  for(i=0;i <n;i ++)
  {
    map[arr[i]]++;
  }

  for(i=0;i<n;i++)
  {
    if(arr[i]!=temp)    // avoid duplicate element
    {
      temp=arr[i];
        printf("%d(%d) ",arr[i],map[arr[i]]);
    }
    ret[i]=map[arr[i]];
  }
  return ret;
}

int main()
{
    int arr[] = { 1, 1, 1, 2, 3, 3, 5, 5,
                  8, 8, 8, 9, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

  int *ret=  findFrequency(arr, n);

  for(i=0;i<n;i++) printf("%d ",ret[i]);
}
