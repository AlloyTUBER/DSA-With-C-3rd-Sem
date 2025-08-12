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
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* insert_begin(struct Node *head, int value) {
    struct Node *new_Node = (struct Node*)malloc(sizeof(struct Node));
    new_Node->data = value;
    new_Node->next = head;
    return new_Node;
}

struct Node* insert_end(struct Node *head, int value) {
    struct Node *new_Node = (struct Node*)malloc(sizeof(struct Node));
    new_Node->data = value;
    new_Node->next = NULL;
    if (head == NULL) {
        return new_Node;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_Node;
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

struct Node* delete_begin(struct Node *head) {
    if(head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* delete_end(struct Node *head) {
    if(head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if(head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* delete_pos(struct Node *head, int pos) {
    if(head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if(pos == 1) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node *temp = head;
    for(int i = 1; temp != NULL && i < pos-1; i++) {
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
}

int main() {
    int n, val, pos, choice;
    struct Node *head = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    head = create(n);

    while(1) {
        printf("\nMenu:\n");
        printf("1. Display\n2. Insert at beginning\n3. Insert at end\n4. Insert at position\n");
        printf("5. Delete at beginning\n6. Delete at end\n7. Delete at position\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display(head);
                break;
            case 2:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &val);
                head = insert_begin(head, val);
                display(head);
                break;
            case 3:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                head = insert_end(head, val);
                display(head);
                break;
            case 4:
                printf("Enter value and position to insert: ");
                scanf("%d %d", &val, &pos);
                head = insert_pos(head, val, pos);
                display(head);
                break;
            case 5:
                head = delete_begin(head);
                display(head);
                break;
            case 6:
                head = delete_end(head);
                display(head);
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                head = delete_pos(head, pos);
                display(head);
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}