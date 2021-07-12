/* Function to get no of bits in binary
   representation of positive integer */
#include <stdio.h>

unsigned int countBits(unsigned int n)
{
   unsigned int count = 0;
   while (n)
   {
        if(n&0x1) count++;
        n >>= 1;


    }
    return count;
}

/* Driver program*/
int main()
{
    int i = 0x4;
    printf("%d", countBits(i));
    return 0;
}
