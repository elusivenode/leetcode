#include <stdio.h>

int findNumbers(int *nums, int numsSize);
int numDigits(int num);

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

    int ctEvens;
    ctEvens = findNumbers(&userArray, userLen);

    printf("The array entered was: [");
    for (int i = 0; i < userLen; i++) {
        if (i == userLen - 1) printf("%d].\n", userArray[i]);
        else printf("%d ", userArray[i]);
    }
    printf("There are %d numbers in this array with an even number of digits.\n", ctEvens);
    return 0;
}

int findNumbers(int *nums, int numsSize){
    int numDigs;
    int ctEvens = 0;
    for (int i = 0; i < numsSize; i++) {
        numDigs = numDigits(nums[i]);
        if (numDigs % 2 == 0) ctEvens++;
    }
    return ctEvens;
}

int numDigits(int num) {
    int n = num;
    int count = 0;
    while (n != 0) {
        n/=10;
        count++;
    }
    return count;
}