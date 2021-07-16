#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int singleNumber(int a[],int n)
{
//  int m[100]={0};
  map<int,int> m;
  int sum1=0,sum2=0;

  int i;
  for(i=0;i<n;i++)
  {
    if(m[a[i]]==0)
    {
      sum1 +=a[i];
      m[a[i]]++;
    }
    sum2 +=a[i];
  }
//for(i=0;i<10;i++) printf("%d(%d) ",m[i],a[i]);
  return 2*sum1-sum2;
}
int main()
{
 int a[] = {2, 3, 5, 4, 5, 3, 4};
 int n = 7;
 int ret= singleNumber(a,n);
 printf("**%d \n",ret);

 int b[] = {15, 18, 16, 18, 16, 15, 89};

 ret = singleNumber(b,n);
 printf("**%d \n",ret);
 return 0;
}
