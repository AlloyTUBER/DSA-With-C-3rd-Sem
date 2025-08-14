#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void display(struct Node *head) {
    struct Node *temp = head;
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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

int main() {
    int n, val, pos, choice;
    struct Node head, node1, node2, node3;

    head.next = &node1;

    node1.data = 10;
    node1.next = &node2;

    node2.data = 20;
    node2.next = &node3;

    node3.data = 30;
    node3.next = NULL;

    printf("Enter value and position of new node: ");
    scanf("%d %d", &val, &pos);
    head.next = insert_pos(head.next, val, pos);

    display(head.next);

    return 0;
}
