#include <stdio.h>
#include <stdlib.h>

// Define a new type 'Node' using typedef
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node** head_ref, int new_data) {
    // Allocate memory for the new node
    Node* new_node = (Node*) malloc(sizeof(Node));

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


void insertAfterNode (Node** head_ref, int data, int newNodeData){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data=newNodeData;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    Node* temp = *head_ref;
    while (temp->next->data != data)
    {
        temp= temp->next;
    }
    
    new_node->next = temp->next->next;
    temp->next->next=new_node;
    
    
    
}
// Function to print the linked list
void printList(Node* node) {

    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function to test the insertion operation
int main() {
    // Initialize an empty linked list
    // printf("Hello new bie \n");
    Node* head = NULL;

    // Code written by me #################################################### 
    // Node* new_node = (Node*) malloc(sizeof(Node));
    // new_node->data=5;
    // head = new_node;
    // printf("%d",head->data);

    // Insert nodes at the end of the list
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 23);

    // Print the resulting linked list
    printf("Created linked list is: ");
    printList(head);

    insertAfterNode(&head,1,199);
    printList(head);

    return 0;
}

