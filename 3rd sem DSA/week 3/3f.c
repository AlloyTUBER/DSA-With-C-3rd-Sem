#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* create_circular(int n) {
    struct Node *head = NULL, *temp = NULL, *new_Node = NULL;
    int value;
    for(int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i+1);
        scanf("%d", &value);
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
    if(temp != NULL)
        temp->next = head; // Make it circular
    return head;
}

int count_nonzero(struct Node *head) {
    if(head == NULL) return 0;
    int count = 0;
    struct Node *temp = head;
    do {
        if(temp->data != 0)
            count++;
        temp = temp->next;
    } while(temp != head);
    return count;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = create_circular(n);

    int nonzero = count_nonzero(head);
    printf("Number of non-zero values in the circular linked list: %d\n", nonzero);

    // Free memory
    if(head != NULL) {
        struct Node *temp = head->next, *del;
        while(temp != head) {
            del = temp;
            temp = temp->next;
            free(del);
        }
        free(head);
    }
    return 0;
}
