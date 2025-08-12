#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node *next;
};

struct Node* create(int n) {
    struct Node *head = NULL, *temp = NULL, *new_Node = NULL;
    float value;
    for(int i = 0; i < n; i++) {
        printf("Enter float value for node %d: ", i+1);
        scanf("%f", &value);
        new_Node = (struct Node*)malloc(sizeof(struct Node));
        new_Node->data = value;
        new_Node->next = NULL;
        if(head == NULL) {
            head = new_Node;
            temp = new_Node;
        } else {
            temp->next = new_Node;
            temp = new_Node;
        }
    }
    return head;
}

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
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = create(n);
    display(head);
    sum_and_mean(head);

    // Free memory
    struct Node *temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
