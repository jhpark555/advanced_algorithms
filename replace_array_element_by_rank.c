
//https://www.techiedelight.com/replace-each-element-corresponding-rank-array/
//rank arry

#include <stdio.h>
#include <stdlib.h>

#define swap(a,b) ( a^=b^=a^=b)

int *sortarr(int arr[],int n)   // sorting to check rank.
{
  int i,j;
  static int brr[sizeof n];

  for(i=0;i<n;i++) for(j=0;j<n-i-1;j++)
  {
    if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
  }

  for(i=0;i<n;i++) brr[i]=arr[i];

  return brr;
}
void transform(int arr[],int n)
{
  int map[50]={0};
  int i,j;
  int ret[n];


  for(i =0; i< n;i++){    //back up original array
    ret[i]=arr[i];
  }

  int *brr = sortarr(arr,n);     // brr is a sorted array
  for(i =0;i <n;i++)
  {
   map[brr[i]] = i+1;
   //printf("%d %d \n",brr[i],map[brr[i]]);
 }

  for(i=0;i<n;i++)
  {
    printf("%d %d \n",ret[i],map[ret[i]]);    // it's a original array
  }

}
int main()
{
 int arr[]={10,8,15,12,6,20,1};
 int n=sizeof(arr)/sizeof(arr[0]);

 transform(arr, n);

}
