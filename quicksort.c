#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int part(int array[], int less, int greater) {
    int piv = array[greater];
    int i = less-1;
    for (int j = less; j < greater; j++) {
        if (array[j] <= piv) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[greater]);\
    return i+1;
}

void quick_recur(int array[], int less, int greater){
    if(less < greater){
        int divide = part(array, less, greater);
        quick_recur(array, less, divide - 1);
        quick_recur(array, divide + 1, greater);
    }
}

int quicks(int *a, int n){
    if (a == NULL || n < 0) {
        printf("Sort 3: Invalid input. Please Try Again.");
        return 0;
    }
    if (n == 0) {
        printf("Sort 2: \n");
        return 0;
    }
    quick_recur(a, 0, n-1);
    return 1;
}

int main(){
    int arr1[] = {18, 3, 8, 23, 2, 6};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    if (quicks(arr1, n1)) {
        printf("Sort 1: ");
        for (int i = 0; i < n1; i++) printf("%d ", arr1[i]);
        printf("\n");
    }

    int arr2[] = {};
    int n2 = 0;
    quicks(arr2, n2);

    int *arr3 = NULL;
    int n3 = -1;
    quicks(arr3, n3);

    return 0;
}