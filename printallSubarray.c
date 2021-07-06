#include <stdio.h>
#include <stdlib.h>

void findSubArray(int arr[],int n)
{
  int i,j,k;
  int max=-1;
  int visited[10]={0};

  for(i=0 ;i<n; i++)
  {
    for(j=i+1;j<n; j++)
    {
      for(k=0;k<10;k++) visited[k]=0;

      printf("(");

      for(k=i;k<=j;k++)
      {
      //  if(j-1 <3) break;
        visited[arr[k]]++;
        if(visited[arr[k]]<2)
        printf("%d ",arr[k]);
      }
      printf(")");
    }
  }
}
int main()
{
  int arr[]={5,2,3,5,4,3};
  int n=sizeof(arr)/sizeof(arr[0]);

  findSubArray(arr,n);
}
