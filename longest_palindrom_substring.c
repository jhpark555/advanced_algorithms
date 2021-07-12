#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//#define swap(a,b) (a^=b^=a^=b)

char * reverse(char s[],int m)
{
  int i,j;
  static char t[sizeof(m)];

  //printf("**%d \n",m);
  //for(i=0,j=m-1;i<j;i++,j--)
  for(i=m-1;i>=0;i--)
  {
     t[i]=s[i];
     printf("%c",t[i]);
   }

 return  t;

}
int compare(char a[],char b[],int m)
{
  int i;
  int count=0;
//printf("%s %s  ",a,b);
 for(i=0; i<m;i++)
 {
  // printf("%c%c, ",a[i],b[i]);
   if(a[i]!=b[i]) {
    // printf("%c%c, ",a[i],b[i]);
     return 0;
   }
   count++;
 }
 //printf("*%d ",count);
 return 1;
}

int longestPalSubstr(char str[],int n)
{
   int i,j,k,m;
   int ret=0;
   char normal[n];
   char rev[n];

   for(i=0; i<n ;i++)
    for(j =i ; j <n; j++)
    {
      printf("(");
      memset(normal,0,sizeof(n));
      memset(rev,0,sizeof(n));

      for(k=i;k<=j;k++)
      {
        normal[k-i]=str[k];
          printf("%c",normal[k-i]);
      }
      printf(":");
      for(k=j;k>=i;k--)
      {
       rev[k-j]=str[k];
        printf("%c",rev[k-j]);
      }
      m=j-i+1;
    //  rev=reverse(normal,m);
      if( compare(normal,rev,m) ) printf(":Palindrom ");
      printf(")\n");

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
