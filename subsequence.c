#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findPowerSet( char s[],int n)
{
  int i,j;
  int m=pow(2,n);

  for(i=0;i<m;i++)
  {
    printf("(");
    for(j=0;j<m;j++)
    {
      if( i & (1<<j) )    // why?
      printf("%c",s[j]);
    }
    printf(")");
  }

}

int main()
{
  char str[]="apple";
//  char str[]={1,2,3,4,5};
  int n=strlen(str);
  findPowerSet(str,n);

  return 0;
}
