#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2;
    printf("Enter size of 1st and 2nd array respectively: ");
    scanf("%d %d", &n1, &n2);

    int *arr1 = (int*)malloc(n1 * sizeof(int));
    int *arr2 = (int*)malloc(n2 * sizeof(int));
    int *merged = (int*)malloc((n1+n2) * sizeof(int));

    if(arr1 == NULL || arr2 == NULL || merged == NULL) {
        printf("MEMORY ALLOCATION FAILED\n");
        return 1;
    }

    printf("Enter elements in the sorted array 1: ");
    for(int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter elements in the sorted array 2: ");
    for(int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2) {
        if(arr1[i] <= arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }

    while(i < n1)
        merged[k++] = arr1[i++];

    while(j < n2)
        merged[k++] = arr2[j++];


    printf("Merged sorted array: ");
    for(int x = 0; x < n1 + n2; x++) {
        printf("%d ", merged[x]);
    }
    printf("\n");

    free(arr1);
    free(arr2);
    free(merged);
    return 0;
}