#include<stdio.h>

void fibo() {
    int a =0, b =1, c = 0;
    printf("%d %d ",a,b);
    for(int i =2 ; i<15; i++) {
        c = a+b;
        a = b;
        b = c;
        printf("%d ",c);
    }
}

int main() {

    printf("The first 15 nubers of the Fibonacci series are: ");
    fibo();

    return 0;
}