#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void display(int queue[], int size) {
    printf("Queue: ");
    for(int i = 0; i < size; i++) {
        if(queue[i] == -1)
            printf("_ ");
        else
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int queue[SIZE];
    for(int i = 0; i < SIZE; i++)
        queue[i] = -1; // -1 means vacant

    int choice, value, pos;

    while(1) {
        printf("\n1. Insert at rear vacant location\n2. Display\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                // Find first vacant location from rear
                for(pos = SIZE-1; pos >= 0; pos--) {
                    if(queue[pos] == -1) {
                        queue[pos] = value;
                        printf("Inserted at position %d (from front: %d)\n", pos, pos+1);
                        break;
                    }
                }
                if(pos < 0)
                    printf("Queue is full! No vacant location at rear.\n");
                break;
            case 2:
                display(queue, SIZE);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}