#include <stdio.h>

int findMaxConsecutiveOnes(int *nums, int numsSize);

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

    int maxOnes = 0;
    maxOnes = findMaxConsecutiveOnes(&userArray, userLen);
    printf("The array entered was: [");
    for (int i = 0; i < userLen; i++) {
        if (i == userLen - 1) printf("%d].\n", userArray[i]);
        else printf("%d ", userArray[i]);
    }
    printf("The maximum number of consecutive ones in this array is %d.\n", maxOnes);
    return 0;
}

int findMaxConsecutiveOnes(int *nums, int numsSize){
    int tempmax = 0;
    int max = 0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==1) {
            tempmax++;
            if(max<tempmax) max = tempmax;
        }
        else {
            tempmax=0;
        }
    }
    return max;
}