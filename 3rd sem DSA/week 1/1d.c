#include <stdio.h>

int power(int n, int m) {

    if(m>0) {
        return n*power(n,m-1);
    }
    else
        return 1;
}

int main() {
    int n,m;

    printf("Enter n and m: ");
    scanf("%d %d", &n, &m);

    printf("%d^%d = %d",n,m,power(n,m));
    return 0;
}