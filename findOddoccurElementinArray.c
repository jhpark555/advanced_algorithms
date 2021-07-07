#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if 0
void findOddOccuring(int arr[],int n)
{
  int i;
  int map[n];

  for(i=0;i <n; i++) map[i]=0;

  for(i =0; i< n; i++)
  {
    map[arr[i]]++;
  }

  for(i=0;i< n; i++){
     if(map[arr[i]] & 1)    //odd
     printf("%d %d \n",arr[i], map[arr[i]]);
  }
}
#else
//Xor odd number of times produce itself.
//x ^ 0 = x
//x ^ x ^ x ^ x = (x ^ x) ^ (x ^ x) = 0 ^ 0 = 0
void findOddOccuring(int arr[],int n)
{
  int xor=0;
  int i;

  for(i=0;i <n; i++)
  {
    xor =xor^arr[i];
  }
   printf("xor=%d \n",xor);
  return xor;
}
#endif



int main()
{
  int arr[] = { 4, 3, 6, 2, 6, 4, 2, 3, 4, 3, 3 };
  int n = sizeof(arr) / sizeof(arr[0]);

  findOddOccuring(arr, n);

  return 0;
}
