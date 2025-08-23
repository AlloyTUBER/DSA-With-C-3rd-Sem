#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* push(struct Node *top, int value) {
    struct Node *new_Node = (struct Node*)malloc(sizeof(struct Node));
    new_Node->data = value;
    new_Node->next = top;
    return new_Node;
}

struct Node* pop(struct Node *top, int *popped_value) {
    if(top == NULL) {
        printf("Stack Underflow!\n");
        *popped_value = -1;
        return NULL;
    }
    struct Node *temp = top;
    *popped_value = temp->data;
    top = top->next;
    free(temp);
    return top;
}

void display(struct Node *top) {
    printf("Stack: ");
    struct Node *temp = top;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *top = NULL;
    int choice, value, popped;

    while(1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                top = push(top, value);
                break;
            case 2:
                top = pop(top, &popped);
                if(popped != -1)
                    printf("Popped value: %d\n", popped);
                break;
            case 3:
                display(top);
                break;
            case 4:
                // Free memory
                while(top != NULL) {
                    struct Node *temp = top;
                    top = top->next;
                    free(temp);
                }
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}