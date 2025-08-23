#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Enqueue operation
struct Node* enqueue(struct Node *rear, int value) {
    struct Node *new_Node = (struct Node*)malloc(sizeof(struct Node));
    new_Node->data = value;
    new_Node->next = NULL;
    if (rear != NULL)
        rear->next = new_Node;
    return new_Node;
}

// Display queue
void display(struct Node *front) {
    printf("Queue: ");
    struct Node *temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Delete from any position in front half
struct Node* delete_front_half(struct Node *front, int pos) {
    int len = 0;
    struct Node *temp = front;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    
    int half = (len + 1) / 2; // front half includes middle if odd

    if (pos < 1 || pos > half) {
        printf("Invalid position! Can only delete from front half (1 to %d).\n", half);
        return front;
    }

    temp = front; // reuse temp
    if (pos == 1) {
        front = front->next;
        free(temp);
        return front;
    }

    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return front;

    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
    return front;
}

int main() {
    struct Node *front = NULL, *rear = NULL;
    int N, value, pos;

    printf("Enter no. of elements to enqueue: ");
    scanf("%d",&N);
    for(int i =0; i<N; i++) {
        printf("Enter value to enqueue: ");
        scanf("%d", &value);
        if (front == NULL) 
            front = rear = enqueue(NULL, value);
        else 
            rear = enqueue(rear, value);
    }

    printf("Enter position to delete (from front half): ");
    scanf("%d", &pos);
    front = delete_front_half(front, pos);
    if (front == NULL)
        rear = NULL;

    display(front);

    // Free memory
    while(front != NULL) {
        struct Node *temp = front;
        front = front->next;
        free(temp);
    }

    return 0;
}
