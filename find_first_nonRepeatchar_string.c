//https://www.techiedelight.com/find-first-non-repeating-character-string-one-traversal/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char findNonRepeatingChar(char s[],int n)
{
  char map[256];
  int i,j;

  for(i=0;i<256 ;i++) map[i]=0;

  for(i=0;i <256; i++)
  {
    map[s[i]]++;
  //  printf("%c   %d \n",s[i],map[s[i]]);
    if(map[s[i]]>1) break;
  }
//printf("%c ",s[i-1]);
 return s[i-1];
}
int main()
{
  char str[]="ABCDBAGHC";
  int n=strlen(str);

char c=  findNonRepeatingChar(str,n);
printf("The first non-repeating character in the string is %c ",c);
}
