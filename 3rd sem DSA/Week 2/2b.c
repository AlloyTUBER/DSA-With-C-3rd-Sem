#include<stdio.h>
#include<stdlib.h>

int** allocate(int rows, int cols) {
    int** mat = (int**) malloc(rows * sizeof(int*));
    for(int i = 0; i<rows; i++) {
        mat[i] = (int*) malloc(cols * sizeof(int));
    }
    return mat;
}

void input(int** mat, int rows, int cols, const char* title) {
    printf("Enter elements for matrix %s: \n",title);

    for(int i = 0; i<rows; i++) {
        for(int j = 0; j< cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int** mat, int rows, int cols, const char* title) {
    printf("\n[%s]:\n",title);
    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<cols; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void sum_product(int** A,int** B, int** sums, int** products, int rows, int cols) {
    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<cols; j++) {
            sums[i][j] = A[i][j] + B[i][j];
            products[i][j] = A[i][j] * B[i][j];
        }
    }
}

void freeMatrix(int** mat, int rows) {
    for(int i = 0; i<rows; i++) {
        free(mat[i]);
    }
    free(mat);
}

int main() {
    int rows, cols;
    printf("Enter no. of rows and columns: ");
    scanf("%d %d",&rows, &cols);

    int **mat1 = allocate(rows, cols);
    int **mat2 = allocate(rows, cols);
    int **sums = allocate(rows, cols);
    int **products = allocate(rows, cols);

    input(mat1, rows, cols, "Matrix 1");
    input(mat2, rows, cols, "Matrix 2");
    displayMatrix(mat1, rows, cols, "Matrix 1");
    displayMatrix(mat2, rows, cols, "Matrix 2");

    sum_product(mat1, mat2, sums, products, rows, cols);
    displayMatrix(sums, rows, cols, "Sum of matrices");
    displayMatrix(products, rows, cols, "Product of matrices");

    freeMatrix(mat1, rows);
    freeMatrix(mat2, rows);
    freeMatrix(sums, rows);
    freeMatrix(products, rows);

    return 0;
}