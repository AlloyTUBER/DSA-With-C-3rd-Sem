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
        printf("Enter data for node %d: ", i+1);
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

void display(struct Node *head) {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void merge_alternate(struct Node *head1, struct Node *head2) {
    struct Node *next1, *next2;

    while(head1 != NULL && head2 != NULL) {
        next1 = head1->next;
        next2 = head2->next;

        head1->next = head2;
        if(next1 == NULL) break;
        head2->next = next1;

        head1 = next1;
        head2 = next2;
    }
}

int main() {
    int n;
    printf("Enter size of both lists (same size): ");
    scanf("%d", &n);

    printf("Enter elements for first list:\n");
    struct Node *head1 = create(n);

    printf("Enter elements for second list:\n");
    struct Node *head2 = create(n);

    printf("First list before merge: ");
    display(head1);
    printf("Second list before merge: ");
    display(head2);

    merge_alternate(head1, head2);

    printf("Merged list (alternate elements): ");
    display(head1);

    // Free all nodes
    struct Node *temp;
    while(head1 != NULL) {
        temp = head1;
        head1 = head1->next;
        free(temp);
    }

    return 0;
}
