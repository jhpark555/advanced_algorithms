#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
void removeDuplicates(char s[])
{
  int n= strlen(s);
  char prev='\0';
  int k=0;
  int i;

  for(i=0; i<n;i++)
  {
    if(prev !=s[i])
    {
      s[k++]=s[i];
    }

    prev=s[i];
  }

  s[k]='\0';

}
#else
void removeDuplicates(char s[])
{
  int n= strlen(s);
  char prev=-1;
  int k=0;
  int i;

  for(i=0; i<n;i++)
  {
    if(s[i]!=prev)
    {
      prev=s[i];
      s[k++]=s[i];
    }

  }
  s[k]='\0';

}
#endif

int main()
{
  //char S[] = "AAABBCDDDEFFF";
//  char S[]="azzxzy";
char S[]="aaabccddd";

  removeDuplicates(S);

  printf("%s", S);


  return 0;
}
