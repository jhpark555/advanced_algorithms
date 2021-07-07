#include <stdio.h>
#include <stdlib.h>

void findSubarrays(int arr[],int n,int sum)
{
  int i,j,k;
  int temp=0;

  for(i=0;i <n; i++)
  {
    for(j=i ;j< n; j++)
    {
      temp=0;

      for(k=i; k<=j; k++)
      {
        temp +=arr[k];
      }
      if(temp==sum) {
        printf("(");
        for(k=i; k<=j;k++)
            printf("%d ",arr[k]);
        printf(")");
      }

    }

  }
}
int main()
{
    int arr[] = { 3, 4, -7, 1, 3, 3, 1, -4 };
    int sum = 7;

    int n = sizeof(arr)/sizeof(arr[0]);
    findSubarrays(arr, n, sum);

    return 0;
}
