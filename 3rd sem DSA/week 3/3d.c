#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* create(int n) {
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
    return head;
}

int count_occurrences(struct Node *head, int key) {
    int count = 0;
    struct Node *temp = head;
    while(temp != NULL) {
        if(temp->data == key)
            count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int n, key;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = create(n);

    printf("Enter value to count: ");
    scanf("%d", &key);

    int result = count_occurrences(head, key);
    printf("Occurrences of %d: %d\n", key, result);

    // Free memory
    struct Node *temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
