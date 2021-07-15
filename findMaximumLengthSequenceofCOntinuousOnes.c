#include <stdio.h>
#include <stdlib.h>

int findIndexofZero(int arr[], int n)
{
    int max_count = 0;          // stores maximum number of 1's (including zero)
    int max_index = -1;         // stores index of 0 to be replaced

    int prev_zero_index = -1;   // stores index of previous zero
    int count = 0;              // stores current count of zeros
    int i;

    // consider each index `i` in the array
    for (i = 0; i < n; i++)
    {
        // if the current element is 1
        if (arr[i] == 1) {
            count++;
          //  printf("#%d(%d)",count,i);
        }
        // if the current element is 0
        else {
            // reset count to 1 + number of ones to the left of current 0
            count = i - prev_zero_index;
          //  printf("*%d(%d)%d  ",count,i,prev_zero_index);

            // update `prev_zero_index` to the current index
            prev_zero_index = i;
        }

        // update maximum count and index of 0 to be replaced if required
        if (count > max_count)
        {
            max_count = count;
            max_index = prev_zero_index;
        }
    }

    // return index of 0 to be replaced or -1 if the array contains all 1's
    return max_index;
}
int main()
{
int arr[] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
int n = sizeof(arr) / sizeof(arr[0]);

int index = findIndexofZero(arr, n);

if (index != -1) {
    printf("Index to be replaced is %d", index);
}
else {
    printf("Invalid input");
}

return 0;
}
