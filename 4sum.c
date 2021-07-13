#include <stdio.h>
#include <stdlib.h>

void hasQuadruplet(int arr[],int n,int tot)
{
  int i,j,k;
  int sum=0;

  for(i= 0; i< n; i++)
  {
    for( j=i+1 ; j<n ;j++)
    {
      sum=0;
      for(k=i;k<=j;k++)
      {
        if(j-i !=3) break;    // check if it's quadruple, we need it.
        sum +=arr[k];
        //printf("%d %d\n",sum,k);
      }
      if(sum==tot){
        printf("(");
          for(k=i;k<=j;k++)
             printf("%d ",arr[k]);
        printf(")");
      }
    }
  }
}
int main()
{

 int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
 int sum = 18;

 int n = sizeof(arr) / sizeof(arr[0]);

 hasQuadruplet(arr, n, sum);

 return 0;
}
