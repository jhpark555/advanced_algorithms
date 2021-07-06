#include <stdio.h>
#include <stdlib.h>

#define swap(a,b) (a^=b^=a^=b)

void reverse(char arr[],int n)
{
    int i,j;

    for(i=0,j=n-1;i<j;i++,j--)
    swap(arr[i],arr[j]);
}

char *longestPalindrome(char *s,int n)
{
  int i,j;
  char ch;

  int count[256]={0};
  for(i=0; i<n; i++){
   count[s[i]]++;
   printf("%d %d ",s[i],count[s[i]]);
 }

  char beg[10],mid[10],end[10];
  char *pbeg=beg,*pmid=mid,*pend=end;

  for(ch='a' ;ch <='z'; ch++)
  {
    if(count[ch] &1 )
    {
      *pmid=ch;
      count[ch--]--;
    }
    else
    {
      for( i=0; i< count[ch]/2 ; i++)
        beg[ch];

    }
  }

//  pend= reverse(pbeg,n);

  return strcat(strcat(beg,mid),end);

}

int main()
{
  char str[]="ABBDAB";
  int n= strlen(str);
  int i;

  char *ret=longestPalindrome(str,n);
//  reverse(str,n);

  //for(i=0; i<n; i++) printf("%c ",str[i]);
}
