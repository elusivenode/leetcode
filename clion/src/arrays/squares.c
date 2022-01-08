#include <stdio.h>
#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize);

int main() {
    printf("Enter the length of an array (integer between 1 and 10,000): ");
    int userLen = 0;
    scanf("%d", &userLen);

    int userArray[userLen];
    printf("At each pause, enter a positive integer.\n");
    for (int i = 0; i < userLen; i++) {
        printf("Enter index %d: ", i);
        scanf("%d", &userArray[i]);
    }

    int *sorted = sortedSquares(&userArray, userLen, &userLen);

    printf("The array entered was: [");
    for (int i = 0; i < userLen; i++) {
        if (i == userLen - 1) printf("%d].\n", userArray[i]);
        else printf("%d ", userArray[i]);
    }

    printf("The sorted array of squares is: [");
    for (int i = 0; i < userLen; i++) {
        if (i == userLen - 1) printf("%d].\n", sorted[i]);
        else printf("%d ", sorted[i]);
    }
    free(sorted);
    return 0;
}

int* sortedSquares(int* A, int ASize, int* returnSize) {
    int* ans = calloc(ASize, sizeof(int));
    *returnSize = ASize;
    int i = 0, j = ASize - 1, index = ASize - 1;
    while(i <= j)
    {
        if(-A[i] > A[j])
        {
            ans[index--] = A[i] * A[i];
            i++;
        }
        else
        {
            ans[index--] = A[j] * A[j];
            j--;
        }
    }
    return ans;
}