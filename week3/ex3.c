#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* nextNode;
} typedef Node;

void print_list(struct Node * head) {
    Node* currentNode = head->nextNode;

    printf("Here is your linked list:\n");
    while (currentNode) {
        printf("->%d", currentNode->data);
        currentNode = currentNode->nextNode;
    }
    printf("\n");
}

void insert_node(struct Node * head, struct Node *newNode, struct Node *prevNode) {
    Node *currentNode = head;
    while (currentNode != prevNode && currentNode->nextNode != NULL) { // search for the preceding node to insert
        currentNode = currentNode->nextNode;
    }

    if (currentNode->nextNode != NULL) {
        newNode->nextNode = currentNode->nextNode;
    }

    currentNode->nextNode = newNode;
}

void delete_node(struct Node *head, struct Node *node) {
    Node *currentNode = head;
    while (currentNode) {
        if (currentNode->nextNode == node) {
            if (node->nextNode != NULL) {
                currentNode->nextNode = node->nextNode;
            } else {
                currentNode->nextNode = NULL;
            }
            free(node);
            break;
        }
        currentNode = currentNode->nextNode;
    }
}

Node * create_list() {
    Node *head = malloc(sizeof (struct Node*));
    return head;
}

Node * create_node(int data) {
    Node *node = malloc(sizeof (struct Node*));
    node->data = data;
    return node;
}

int main() {
    Node *head = create_list();

    Node *node1 = create_node(10);
    Node *node2 = create_node(20);
    Node *node3 = create_node(15);
    Node *node4 = create_node(25);

    insert_node(head, node1, head); // add a first node to the list
    print_list(head);

    insert_node(head, node2, node1); // add a second node to the list
    print_list(head);

    insert_node(head, node3, node1); // add a third node between 2 existing nodes
    print_list(head);

    delete_node(head, node1); // delete the first node from the list
    print_list(head);

    insert_node(head, node4, head); // insert another node as a first
    print_list(head);

    delete_node(head, node3); // delete the node between other 2 nodes
    print_list(head);

    delete_node(head, node2); // delete the last node
    print_list(head);
}
