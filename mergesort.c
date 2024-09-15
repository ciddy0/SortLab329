
#include <stdio.h>
#include <stdlib.h>


void merge(int *a, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;


    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));


    for (i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];


    i = 0; 
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

   
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }


    free(L);
    free(R);
}

void merge_sort_recursive(int *a, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;


        merge_sort_recursive(a, left, mid);
        merge_sort_recursive(a, mid + 1, right);


        merge(a, left, mid, right);
    }
}


void merge_sort(int *a, int n) {
    merge_sort_recursive(a, 0, n - 1);
}

void print_array(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    print_array(arr, n);

    merge_sort(arr, n);

    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}
