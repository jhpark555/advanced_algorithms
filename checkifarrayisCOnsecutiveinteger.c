//https://www.techiedelight.com/check-array-formed-consecutive-integers/


#include <stdio.h>
#include <stdlib.h>

int isConsecutive(int arr[],int n)
{
  int i,j;
  int map[n];

  for( i=0;i <n;i ++) map[i]=0;

  for(i =0; i< n; i++)
  {
    map[arr[i]]++;
    if(map[arr[i]] >1 ) {
      printf("***not consecutibve is %d \n",arr[i]);
    //  break;
    return 0;
    }
  }
 return 1;
//  for(i=0;i<n;i++) printf("%d(%d) ",arr[i],map[arr[i]]);
}
int main()
{
  int arr[]={-1,5,4,2,0,3,1};
//int arr[]= { 4, 2, 4, 3, 1 };
  int n= sizeof(arr)/sizeof(arr[0]);

  isConsecutive(arr,n) ? printf("Consecutive integers\n") :
     printf("Not consecutive integers\n");
}
