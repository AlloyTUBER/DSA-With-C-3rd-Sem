#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node *next;
};

void display(struct Node *head) {
    struct Node *temp = head;
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%.2f ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sum_and_mean(struct Node *head) {
    struct Node *temp = head;
    float sum = 0.0;
    int count = 0;
    while(temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    printf("Sum = %.2f\n", sum);
    if(count > 0)
        printf("Mean = %.2f\n", sum / count);
    else
        printf("Mean = 0.00\n");
}

int main() {
    struct Node head, node1, node2, node3;

    head.next = &node1;
    
    node1.data = 10.3;
    node1.next = &node2;

    node2.data = 27.9;
    node2.next = &node3;

    node3.data = 33.4;
    node3.next = NULL;

    display(head.next);
    sum_and_mean(head.next);

    // Free memory
    struct Node *temp;
    while(head.next != NULL) {
        temp = head.next;
        head.next = head.next->next;
        free(temp);
    }
    return 0;
}
