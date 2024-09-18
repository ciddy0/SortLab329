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
    int array[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original:\n");
    print_arr(array, n);

    merge_sort(array, n);

    printf("Sorted:\n");
    print_arr(array, n);

    return 0;
}
