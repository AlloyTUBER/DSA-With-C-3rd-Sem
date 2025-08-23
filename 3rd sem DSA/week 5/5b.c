#include <stdio.h>
#include <stdlib.h>

// Stack node
struct Node {
    int data;
    struct Node *next;
};

// Push to stack
struct Node* push(struct Node *top, int value) {
    struct Node *new_Node = (struct Node*)malloc(sizeof(struct Node));
    new_Node->data = value;
    new_Node->next = top;
    return new_Node;
}

// Pop from stack
struct Node* pop(struct Node *top, int *value) {
    if (top == NULL) {
        *value = -1;
        return NULL;
    }
    struct Node *temp = top;
    *value = temp->data;
    top = top->next;
    free(temp);
    return top;
}

// Enqueue using two stacks
void enqueue(struct Node **stack1, int value) {
    *stack1 = push(*stack1, value);
}

// Dequeue using two stacks
int dequeue(struct Node **stack1, struct Node **stack2) {
    int value;
    if (*stack2 == NULL) {
        // Transfer all elements from stack1 to stack2
        while (*stack1 != NULL) {
            *stack1 = pop(*stack1, &value);
            *stack2 = push(*stack2, value);
        }
    }
    if (*stack2 == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    *stack2 = pop(*stack2, &value);
    return value;
}

// Display queue (from stack2, then stack1 reversed)
void display(struct Node *stack1, struct Node *stack2) {
    // Print stack2 (front of queue)
    struct Node *temp = stack2;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    // To print stack1 in correct order, reverse it temporarily
    // (copy to temp stack)
    struct Node *rev = NULL;
    temp = stack1;
    int val;
    while (temp != NULL) {
        rev = push(rev, temp->data);
        temp = temp->next;
    }
    temp = rev;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    // Free temp stack
    while (rev != NULL) {
        rev = pop(rev, &val);
    }
    printf("\n");
}

int main() {
    struct Node *stack1 = NULL, *stack2 = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&stack1, value);
                break;
            case 2:
                value = dequeue(&stack1, &stack2);
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;
            case 3:
                display(stack1, stack2);
                break;
            case 4:
                // Free memory
                while (stack1 != NULL) stack1 = pop(stack1, &value);
                while (stack2 != NULL) stack2 = pop(stack2, &value);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}