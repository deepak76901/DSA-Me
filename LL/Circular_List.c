#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct Node {
    int data;
    struct Node* next; // Pointer to the next node
} Node;

// Structure definition for the circular linked list
typedef struct CircularLinkedList {
    Node* head; // Pointer to the first node
} CircularLinkedList;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a circular linked list
CircularLinkedList* createCircularLinkedList() {
    CircularLinkedList* list = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    list->head = NULL;
    return list;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(CircularLinkedList* list, int data) {
    Node* newNode = createNode(data);

    // If the list is empty
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = newNode; // Point to itself, making it circular
        return;
    }

    // Traverse to the last node
    Node* temp = list->head;
    while (temp->next != list->head) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;
    newNode->next = list->head; // Make it circular
}

// Function to display the circular linked list
void printList(CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = list->head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head); // Loop until we come back to the head

    printf("(back to head)\n");
}

// Main function
int main() {
    // Create a circular linked list
    CircularLinkedList* list = createCircularLinkedList();

    // Insert nodes
    insertAtEnd(list, 10);
    insertAtEnd(list, 20);
    insertAtEnd(list, 30);
    insertAtEnd(list, 40);

    printf("Circular Linked List:\n");
    printList(list);

    return 0;
}
