#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair minmax, mml, mmr;
    int mid;

    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    mid = (low + high) / 2;

    mml = findMinMax(arr, low, mid);
    mmr = findMinMax(arr, mid + 1, high);

    if (mml.min < mmr.min) {
        minmax.min = mml.min;
    } else {
        minmax.min = mmr.min;
    }

    if (mml.max > mmr.max) {
        minmax.max = mml.max;
    } else {
        minmax.max = mmr.max;
    }

    return minmax;
}

int main() {
    int arr[] = {23, 45, 6, 8, -9, 44, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Pair minmax = findMinMax(arr, 0, n - 1);
    printf("Min value = %d, Max Value = %d\n", minmax.min, minmax.max);
    return 0;
}