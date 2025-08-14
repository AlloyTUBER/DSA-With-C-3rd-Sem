#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

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
    struct  Node head, node1, node2, node3;

    head.next = &node1;
    
    node1.data = 10;
    node1.next = &node2;
    
    node2.data = 20;
    node2.next = &node3;

    node3.data = 0;
    node3.next = head.next;

    int nonzero = count_nonzero(head.next);
    printf("Number of non-zero values in the circular linked list: %d\n", nonzero);

    // Free memory
    if(head.next != NULL) {
        struct Node *temp = head.next->next, *del;
        while(temp != head.next) {
            del = temp;
            temp = temp->next;
            free(del);
        }
        free(head.next);
    }
    return 0;
}
