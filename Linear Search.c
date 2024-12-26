#include <stdio.h>
#include <time.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {56, 89, 7, 13, 75, 23, 8, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 75;

    clock_t start = clock();
    int position = linearSearch(arr, size, key);
    clock_t end = clock();

    if (position != -1) {
        printf("Element found at position: %d\n", position);
    } else {
        printf("Element not found.\n");
    }

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for linear search: %f seconds\n", time_taken);

    return 0;
}