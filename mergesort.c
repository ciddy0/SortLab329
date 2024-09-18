#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, int n);
static void merge_sort_helper(int *array, int *temp, int left, int right);
static void merge(int *array, int *temp, int left, int mid, int right);

void merge_sort(int *array, int n) {
    if (n <= 0) return;
    int *temp = (int *)malloc(n * sizeof(int));
    if (temp == NULL) {
        perror("Could not allocate memory");
        exit(EXIT_FAILURE);
    }

    merge_sort_helper(array, temp, 0, n - 1);

    free(temp);
}

static void merge_sort_helper(int *array, int *temp, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort_helper(array, temp, left, mid);
        merge_sort_helper(array, temp, mid + 1, right);
        merge(array, temp, left, mid, right);
    }
}

static void merge(int *array, int *temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    for (int l = left; l <= right; l++) {
        temp[l] = array[l];
    }

    while (i <= mid && j <= right) {
        if (temp[i] <= temp[j]) {
            array[k++] = temp[i++];
        } else {
            array[k++] = temp[j++];
        }
    }

    while (i <= mid) {
        array[k++] = temp[i++];
    }

    while (j <= right) {
        array[k++] = temp[j++];
    }
}

void print_arr(int *array, int n) {
    for (int i = 0; i < n; i++) {
        
        printf("%d ", array[i]);
    }

    printf("\n");
}

int main() {
    // Case 1: Random Unsorted Array
    int testCase1[] = {34, 7, 23, 32, 5, 62};
    int size1 = sizeof(testCase1) / sizeof(testCase1[0]);
    printf("Test Case 1: Random Unsorted Array\n");
    print_arr(testCase1, size1);
    merge_sort(testCase1, size1);
    print_arr(testCase1, size1);
    
    printf("\n");

    // Case 2: Already Sorted Array
    int testCase2[] = {1, 2, 3, 4, 5, 6};
    int size2 = sizeof(testCase2) / sizeof(testCase2[0]);
    printf("Test Case 2: Already Sorted Array\n");
    print_arr(testCase2, size2);
    merge_sort(testCase2, size2);
    print_arr(testCase2, size2);
    
    printf("\n");

    // Case 3: Reverse Order Array
    int testCase3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size3 = sizeof(testCase3) / sizeof(testCase3[0]);
    printf("Test Case 3: Reverse Order Array\n");
    print_arr(testCase3, size3);
    merge_sort(testCase3, size3);
    print_arr(testCase3, size3);
    
    printf("\n");

    // Case 4: Single Element Array
    int testCase4[] = {42};
    int size4 = sizeof(testCase4) / sizeof(testCase4[0]);
    printf("Test Case 4: Single Element Array\n");
    print_arr(testCase4, size4);
    merge_sort(testCase4, size4);
    print_arr(testCase4, size4);
    
    printf("\n");

    // Case 5: Empty Array
    int testCase5[] = {};
    int size5 = sizeof(testCase5) / sizeof(testCase5[0]);
    printf("Test Case 5: Empty Array\n");
    print_arr(testCase5, size5);
    merge_sort(testCase5, size5);
    print_arr(testCase5, size5);
    
    printf("\n");

    // Case 6: Array with Duplicates
    int testCase6[] = {8, 3, 3, 7, 9, 8, 5};
    int size6 = sizeof(testCase6) / sizeof(testCase6[0]);
    printf("Test Case 6: Array with Duplicates\n");
    print_arr(testCase6, size6);
    merge_sort(testCase6, size6);
    print_arr(testCase6, size6);
    
    printf("\n");

    // Case 7: Large Array
    int testCase7[] = {23, 45, 12, 67, 89, 34, 90, 56, 78, 11, 22, 33};
    int size7 = sizeof(testCase7) / sizeof(testCase7[0]);
    printf("Test Case 7: Large Array\n");
    print_arr(testCase7, size7);
    merge_sort(testCase7, size7);
    print_arr(testCase7, size7);
    
    printf("\n");

    // Case 8: All Elements Identical
    int testCase8[] = {7, 7, 7, 7, 7, 7};
    int size8 = sizeof(testCase8) / sizeof(testCase8[0]);
    printf("Test Case 8: All Elements Identical\n");
    print_arr(testCase8, size8);
    merge_sort(testCase8, size8);
    print_arr(testCase8, size8);

    return 0;
}
