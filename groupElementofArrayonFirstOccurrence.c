//https://www.geeksforgeeks.org/group-multiple-occurrence-of-array-elements-ordered-by-first-occurrence/
//visited[n]을 사용해서 방문한 이력이 있으면 1로 세팅.
#include <stdio.h>
#include <stdlib.h>

int *rearrange(int arr[],int n)
{
  int visited[n];
  int i,j,k=0;
  static int ret[sizeof(n)];    // storage size error

  for( i=0;i <n ;i++) visited[i]= 0;

  for(i =0; i< n; i++)
  {
    if(!visited[i])
    {
      //printf("%d(%d) ",arr[i],i);
      ret[k++]=arr[i];
      for(j=i+1; j< n;j++)
      {
        if(arr[i] == arr[j]) {
          //printf("*%d(%d) ",arr[i],i);
          ret[k++]=arr[i];
          visited[j]=1;
        }
      }
    }
  }
  return ret;
}

int main()
{
  int arr[]={ 5, 4, 5, 5, 3, 1, 2, 2, 4 };
//  int arr[] = {4, 6, 9, 2, 3, 4, 9, 6, 10, 4};
  int n= sizeof(arr)/sizeof(arr[0]);
  int i;

 int *ret=rearrange(arr,n);

  for(i=0;i< n;i++) printf("%d ",ret[i]);
}
