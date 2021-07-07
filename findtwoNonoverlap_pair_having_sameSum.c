//https://www.techiedelight.com/find-two-non-overlapping-pairs-sum-array/
#include <stdio.h>
#include <stdlib.h>

void findPairs(int arr[],int n)
{
   int i,j;
   int map[n*10*n];
   int visited[n*10*n];

   for(i=0; i< n*10*n; i++) {
      map[i]=0;
      visited[i]=0;
    }

   for( i=0 ; i<n-1 ; i++)
   for( j= i+1 ;j <n ; j++)
   {
     map[i*10+j]=arr[i]+arr[j];
     //printf("%d(%02d) ",map[i*10+j],i*10+j);
   }
   for(i=0;i<n*10*n;i++)
   {
     if(map[i]!=0)
       visited[map[i]]++;

     if(visited[map[i]] > 2)  printf("%d(%d) ",map[i],i);
     //else printf("There is no overlapping \n");
   }
}
int main()
{
   //int arr[] = { 3, 4, 7, 3, 4 };
    int arr[] = { 8, 4, 7, 8, 4 };
//  int arr[]={3,4,7,4};
   int n = sizeof(arr) / sizeof(arr[0]);

   findPairs(arr, n);

   return 0;
}
