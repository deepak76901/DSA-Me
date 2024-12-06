#include <stdio.h>
#include <stdlib.h>

// Define a new type 'Node' using typedef
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a new node after a node with given data
void insertAfter(Node** head_ref, int key, int new_data) {
    // Allocate memory for the new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;

    // If the linked list is empty 
    if (*head_ref == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }

    //If the key is found in head node itself
    if((*head_ref)->data == key){
        new_node->next = (*head_ref)->next;
        (*head_ref)->next = new_node;
        return;
    }
    
    Node* temp = *head_ref;
    // Traverse the list using while loop to find the node with the given key
    while (temp->next != NULL && temp->next->data != key){
        temp = temp->next;
    }

    // If the key is not present in the linked list
    if(temp->next == NULL){
        printf("The given previous node cannot be NULL");
        return;
    }
   
   // Insert the new node after the node with the given data
   new_node->next = temp->next->next;
   temp->next->next = new_node;

}

// Function to insert a node at the end
void insertAtEnd(Node** head_ref, int new_data) {
    // Allocate memory for the new node
    Node* new_node = (Node*)malloc(sizeof(Node));

    // Assign data to the new node
    new_node->data = new_data;

    // Set the next pointer of the new node to NULL, as it will be the last node
    new_node->next = NULL;

    // Check if the linked list is empty
    if (*head_ref == NULL) {
        // If the list is empty, make the new node the head
        *head_ref = new_node;
        return;
    }

    // Traverse to the last node of the linked list
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // Set the next pointer of the last node to the new node
    last->next = new_node;
}

// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function to test the insertion operation
int main() {
    // Initialize an empty linked list
    Node* head = NULL;

    // Insert nodes at the end of the list
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 1);

    // Print the resulting linked list
    printf("Created linked list is: ");
    printList(head);

    //Insert a new node after the given node
    insertAfter(&head, 7, 8);
     printf("\nCreated linked list is: ");
    printList(head);

    return 0;
}
