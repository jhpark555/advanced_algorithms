//https://www.techiedelight.com/find-symmetric-pairs-array-pairs/

#include <stdio.h>
#include <stdlib.h>

typedef struct Pair Pair;
struct Pair
{
  int x,y;
};

int findPair(Pair pair[],int n)
{
  int i,j;
  int count=0;

  for(i =0;i <n; i++)
  {
    count=0;
   for( j=i+1 ;j<n ;j++)
   {
     if(pair[i].x==pair[j].y && pair[i].y==pair[j].x){
       printf("%d %d | %d %d \n",pair[i].x,pair[i].y,pair[j].x,pair[j].y);
        count++;
      }
   }
  }
  return count;
}

int main()
{
  Pair arr[]={{3,4},{1,2},{5,2},{7,10},{4,3},{2,5}};
  int n = sizeof(arr)/sizeof(arr[0]);

  int r= findPair(arr,n);
printf("Count=%d \n",r);
}
