#include<stdio.h>

int GCD(int m, int n) {

    while (n != 0) {
        int temp = n;
        n = m%n;
        m = temp;
    }
    return m;
}

int main() {
    int a,b;

    printf("Enter two number: ");
    scanf("%d %d", &a, &b);

    printf("GCD of %d and %d is = %d.\n",a,b,GCD(a,b));
    
    return 0;
}