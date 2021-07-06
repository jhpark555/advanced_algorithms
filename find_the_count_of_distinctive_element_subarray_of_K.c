#include <stdio.h>
#include <stdlib.h>

#if 0
void findDistinctCount( int arr[],int n,int k)
{
    int i,j,x;
    //consider every subarray of size k
    for(x= 0; x<= n-k; x++)
    {
      // maintains a counter for distinct elements in the current subarray
      int distinct =0;
      // current subarray is formed by subarray `arr[x, x+k)`
      for( i=x; i< x+k ;i++)
      {
        // increase distinct count for `arr[i]` in current subarray
        distinct++;

        // check if `arr[i]` is present in subarray `arr[x, i-1]` or not
        for(j=x; j<i ;j++)
        {
          // if duplicate element found in the current subarray
          if(arr[i]==arr[j]){
            // unmark element `arr[i]` as distinct – decrease count
             distinct --;
             break;
           }
        }
      }
      printf("The count of distinct elements in subarray [%d, %d] "
                     "is %d\n", x, x + k - 1, distinct);

    }

}
#else
void findDistinctCount( int arr[],int n,int k)
{
   int i,j,x,w;
   int visited[10]={0};
   int max=-1;

  // for( i=0;i <n ;i++) visited[i]= 0;

   for(i =0;i <n; i++)
   {
     for( j=i; j< n;j ++)
     {
       //printf("(");
       max=0;
       for( w=0;w <n ;w++) visited[w]= 0;   // important initialize

       for( x=i; x<=j; x++)
       {
         if(j-i!= k-1) break;
         visited[arr[x]]++;
         //if(visited[arr[x]]==1)
         if((arr[x] > max) && (visited[arr[x]]==1)) max= arr[x];
         printf("%d ",arr[x]);
       }
       if(max)
         printf("max=%d \n",max);
       //printf(")");
     }
   }
}
#endif

int main()
{
  int arr[] = { 2, 1, 2, 3, 2, 1, 4, 5 };
  int k = 5;
  int n = sizeof(arr) / sizeof(arr[0]);

  findDistinctCount(arr, n, k);
}
