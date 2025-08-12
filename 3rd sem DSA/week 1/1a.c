#include<stdio.h>

void check_prime(int n) {
    int c = 0;

    for(int i = 1; i<=n/2; i++) {
        if(n%i == 0)
            c++;
        
    }

    if(c == 1)
        printf("%d is a prime number.\n", n);
    
    else
        printf("%d is not a prime number.\n", n);
} 

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d",&num);

    check_prime(num);

    return 0;
}