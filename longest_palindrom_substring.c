#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int longestPalSubstr(char str[],int n)
{
   int i,j,k,m,x;
   int ret=0;
   char normal[n];
   char rev[n];
   int max =-1;

   for(i=0; i<n ;i++)
    for(j =i ; j <n; j++)
    {
      max=-1;
      //printf("(");
      memset(normal,0,sizeof(n));
      memset(rev,0,sizeof(n));

      for(k=i;k<=j;k++)
      {
        normal[k-i]=str[k];
         //printf("%c",normal[k-i]);
      }
      //printf(":");
      for(k=j;k>=i;k--)
      {
       rev[j-k]=str[k];
        //printf("%c",rev[j-k]);
      }
      m=j-i+1;
      //printf(">>%c %c ",normal[0],rev[0]);

      for(x=0;x<m;x++){
        if(normal[x]!=rev[x]){    //it's not palindrom
            break;
        }
      }
      if(x==m){       // Yes it's palindrom
        if(x>max) max=x;   //need to check max substrig
      printf("\t\tPalindrom %d : ",max);
      for(x=0;x<m;x++) printf("%c",normal[x]);
        printf("\n");
      }
      //printf(")\n");

    }
  return ret;
}

int main()
{
  char str[] = "forgeeksskeegfor";
  int n=strlen(str);
  printf("\nLength is:%d ",longestPalSubstr(str,n));
  return 0;
}
