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


struct Node* insert_pos(struct Node *head, int value, int pos) {
    struct Node *new_Node = (struct Node*)malloc(sizeof(struct Node));
    new_Node->data = value;
    new_Node->next = NULL;
    if(pos == 1) {
        new_Node->next = head;
        return new_Node;
    }
    struct Node *temp = head;
    for(int i = 1; temp != NULL && i < pos-1; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Position out of bounds.\n");
        free(new_Node);
        return head;
    }
    new_Node->next = temp->next;
    temp->next = new_Node;
    return head;
}

void display(struct Node *head) {
    struct Node *temp = head;
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, val, pos, choice;
    struct Node *head = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    head = create(n);

    printf("Enter value and position of new node: ");
    scanf("%d %d", &val, &pos);
    head = insert_pos(head, val, pos);

    display(head);

    return 0;
}