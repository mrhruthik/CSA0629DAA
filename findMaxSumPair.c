#include <stdio.h>

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int findMaxSumPair(int nums[], int size) {
    int maxSum = -1;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (sumOfDigits(nums[i]) == sumOfDigits(nums[j])) {
                maxSum = (maxSum == -1) ? nums[i] + nums[j] : (nums[i] + nums[j] > maxSum) ? nums[i] + nums[j] : maxSum;
            }
        }
    }
    return maxSum;
}

int main() {
    int nums[] = {12, 24, 36, 48, 50, 51, 54}; // Added some more numbers for testing
    int size = sizeof(nums) / sizeof(nums[0]);
    int maxSum = findMaxSumPair(nums, size);

    if (maxSum == -1) {
        printf("No such pair found.\n");
    } else {
        printf("Maximum sum of pair: %d\n", maxSum);
    }

    return 0;
}