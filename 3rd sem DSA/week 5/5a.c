#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Deque {
    struct Node *front;
    struct Node *rear;
};

void insertFront(struct Deque *dq, int value) {
    struct Node *new_Node = (struct Node*)malloc(sizeof(struct Node));
    new_Node->data = value;
    new_Node->prev = NULL;
    new_Node->next = dq->front;
    if (dq->front == NULL)
        dq->rear = new_Node;
    else
        dq->front->prev = new_Node;
    dq->front = new_Node;
}

void insertRear(struct Deque *dq, int value) {
    struct Node *new_Node = (struct Node*)malloc(sizeof(struct Node));
    new_Node->data = value;
    new_Node->next = NULL;
    new_Node->prev = dq->rear;
    if (dq->rear == NULL)
        dq->front = new_Node;
    else
        dq->rear->next = new_Node;
    dq->rear = new_Node;
}

void deleteFront(struct Deque *dq) {
    if (dq->front == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node *temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front == NULL)
        dq->rear = NULL;
    else
        dq->front->prev = NULL;
    printf("Deleted from front: %d\n", temp->data);
    free(temp);
}

void deleteRear(struct Deque *dq) {
    if (dq->rear == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node *temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL)
        dq->front = NULL;
    else
        dq->rear->next = NULL;
    printf("Deleted from rear: %d\n", temp->data);
    free(temp);
}

void display(struct Deque *dq) {
    struct Node *temp = dq->front;
    printf("Deque: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Deque *dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->front = dq->rear = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(dq, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(dq, value);
                break;
            case 3:
                deleteFront(dq);
                break;
            case 4:
                deleteRear(dq);
                break;
            case 5:
                display(dq);
                break;
            case 6:
                // Free memory
                while (dq->front != NULL) {
                    struct Node *temp = dq->front;
                    dq->front = dq->front->next;
                    free(temp);
                }
                free(dq);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}