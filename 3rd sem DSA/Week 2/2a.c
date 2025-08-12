#include<stdio.h>
#include<stdlib.h>

void largest(int *arr, int len) {
    int first, second, third;

    if(len < 3) {
        printf("Array must have at least 3 elements.\n");
        return;
    }

    first = second = third = arr[0];

    for(int i = 0; i < len; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        }
        else if(arr[i] > second && arr[i] != first) {
            third = second;
            second = arr[i];
        }
        else if(arr[i] > third && arr[i] != second && arr[i] != first) {
            third = arr[i];
        }
    }

    printf("First largest element = %d.\n", first);
    printf("Second largest element = %d.\n", second);
    printf("Third largest element = %d.\n", third);
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));

    if(array == NULL) {
        printf("MEMORY ALLOCATION FAILED\n");
        return 1;
    }

    printf("Enter elements in the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    largest(array, n);

    free(array);
    return 0;
}