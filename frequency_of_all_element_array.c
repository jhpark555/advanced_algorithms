#include <stdio.h>
#include <stdlib.h>

void findFrequency(int arr[], int n)
{
  int map[50]={0};
  int i;

  for(i=0;i<n;i++)
  {
    map[arr[i]]++;
  }

  for(i=0;i<n;i++)
  {
    if(map[i])
     printf("arr[%d]=%d \n",i,map[i]);
  }


}
int main()
{
//  int arr[]={2,3,3,2,1};
 int arr[]={1, 1, 1, 2, 3, 3, 5, 5, 8, 8, 8, 9, 9, 10};
  int n=sizeof(arr)/sizeof(arr[0]);

  findFrequency(arr, n);
}
