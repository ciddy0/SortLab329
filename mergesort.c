#include <stdio.h>
#include <stdlib.h>

void performMergeSort(int *arr, int length);
void divideAndSort(int *arr, int *helper, int low, int high);
void combineSortedHalves(int *arr, int *helper, int low, int middle, int high);

void performMergeSort(int *arr, int length) {
    if (length <= 1) return;

    int *helper = (int *)malloc(length * sizeof(int));
    if (!helper) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    divideAndSort(arr, helper, 0, length - 1);
    free(helper);
}

void divideAndSort(int *arr, int *helper, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        divideAndSort(arr, helper, low, mid);
        divideAndSort(arr, helper, mid + 1, high);
        combineSortedHalves(arr, helper, low, mid, high);
    }
}

void combineSortedHalves(int *arr, int *helper, int low, int middle, int high) {
    for (int i = low; i <= high; i++) {
        helper[i] = arr[i];
    }

    int left = low;
    int right = middle + 1;
    int current = low;

    while (left <= middle && right <= high) {
        if (helper[left] <= helper[right]) {
            arr[current++] = helper[left++];
        } else {
            arr[current++] = helper[right++];
        }
    }

    while (left <= middle) {
        arr[current++] = helper[left++];
    }
}

void displayArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test cases
    int array1[] = {34, 7, 23, 32, 5, 62};
    int length1 = sizeof(array1) / sizeof(array1[0]);
    displayArray(array1, length1);
    performMergeSort(array1, length1);
    displayArray(array1, length1);

    int array2[] = {};
    int length2 = sizeof(array2) / sizeof(array2[0]);
    displayArray(array2, length2);
    performMergeSort(array2, length2);
    displayArray(array2, length2);

    int array3[] = {42};
    int length3 = sizeof(array3) / sizeof(array3[0]);
    displayArray(array3, length3);
    performMergeSort(array3, length3);
    displayArray(array3, length3);

    int array4[] = {9, 9, 9, 9, 9};
    int length4 = sizeof(array4) / sizeof(array4[0]);
    displayArray(array4, length4);
    performMergeSort(array4, length4);
    displayArray(array4, length4);

    int array5[] = {1, 2, 3, 4, 5};
    int length5 = sizeof(array5) / sizeof(array5[0]);
    displayArray(array5, length5);
    performMergeSort(array5, length5);
    displayArray(array5, length5);

    int array6[] = {-10, 0, 2, -5, 4};
    int length6 = sizeof(array6) / sizeof(array6[0]);
    displayArray(array6, length6);
    performMergeSort(array6, length6);
    displayArray(array6, length6);

    return 0;
}
