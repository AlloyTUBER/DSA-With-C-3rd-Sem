#include<stdio.h>

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("A = %d, B = %d",a, b);
}

int main() {
    int a,b;

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    swap(a,b);

    return 0;
}