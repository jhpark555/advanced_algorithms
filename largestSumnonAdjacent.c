#include<stdio.h>
#include<stdlib.h>

#if 0
int largeSum(int arr[],int n)
{
  int i,j,k;
  int sum=0;
  int max=-1;

  for(i=0;i <n; i++)
  {
    for( j=i+1;j< n; j++)
    {
     printf("(");
      sum=0;
      for(k=i;k <=j;k ++)
      {
        sum +=arr[k];
        if( sum > max) {
            max= sum;
          }
       printf("%d ",arr[k]);
      }
      //  for(k=i;k <=j;k +=2) printf("%d ",arr[k]);
    //  printf("**max=%d \n",max);
      printf(")");
    }
  }

  return max;
}
#else
int largeSum(int arr[],int n)
{
  int incl = arr[0];
  int excl =0;
  int excl_new;
  int i;

  for( i=1;i <n ;i++)
  {
    excl_new= (incl >excl)? incl:excl;

    incl = excl +arr[i];
    excl= excl_new;
  }

  return ((incl > excl)? incl:excl);
}
#endif

int main()
{
 int arr[]={2,4,6,2,5};
//int arr[]={5,1,1,5};
  int n=sizeof(arr)/sizeof(arr[0]);

  int max= largeSum(arr,n);
  printf("Max is %d \n",max);
}
