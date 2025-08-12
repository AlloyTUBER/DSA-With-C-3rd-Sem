#include<stdio.h>
#include<stdlib.h>

int main() {
    int row, cols;
    printf("Enter no. of rows and columns: ");
    scanf("%d %d", &row, &cols);

    if(row != cols) {
        printf("Matrix cannot be transposed!!");
        return 1;
    }

    // Allocate matrix
    int **mat = (int **)malloc(row * sizeof(int *));
    for(int i = 0; i < row; i++) {
        mat[i] = (int *)malloc(cols * sizeof(int));
    }

    // Input matrix
    printf("Enter elements for matrix:\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Display original matrix
    printf("Normal matrix: -\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    // Display transposed matrix
    printf("Transposed matrix: -\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }

    // Free memory
    for(int i = 0; i < row; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}