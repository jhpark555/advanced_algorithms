//https://www.geeksforgeeks.org/remove-all-duplicate-adjacent-characters-from-a-string-using-stack/#:~:text=1%20Create%20a%20stack%2C%20st%20to%20remove%20the,print%20all%20the%20remaining%20elements%20of%20the%20stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *removeDuplicates(char s[])
{
  int n= strlen(s);
  char dp[226]={0};
  int k=0;
  int i;

  static char ret[sizeof n];

  for(i=0; i<n;i++)
  {
    dp[s[i]]++;
  }
  for(i=0;i<n; i++){
    //printf("%d ",dp[s[i]]);
   if(dp[s[i]]==1){
      ret[k++]=s[i];
    //  printf("%c",s[i]);
    }
  }

return ret;
}

int main()
{
//  char S[] = "AAABBCDDDEFFF";
  //char S[]="azzxzy";
//  char S[]="azxxzy";
  char S[]="aaabccddd";

  char *ret=removeDuplicates(S);

  printf("%s", ret);


  return 0;
}
