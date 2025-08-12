#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 100, m = 100;
    char *input = (char*)malloc(n * sizeof(char));
    char *store = (char*)malloc(m * sizeof(char));

    printf("Enter string: ");
    fgets(input, n, stdin);

    int k = 0;
    for(int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        if(!(ch == 'A'||ch == 'E'||ch == 'I'||ch == 'O'||ch == 'U'||
             ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u')) {
            store[k++] = ch;
        }
    }
    store[k] = '\0';

    printf("String without vowels: %s\n", store);

    free(input);
    free(store);
    return 0;
}