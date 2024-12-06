#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void insertAtStart (Node** head_ref,int data){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data=data;


    if (*head_ref == NULL)
    {
        *head_ref=new_node;
        return;
    }
    

    new_node->next=*head_ref;
    *head_ref = new_node;
}

void printList(Node* temp){
   
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
}

int main(){
    Node* head =NULL;
       
    
    insertAtStart(&head,5);    
    insertAtStart(&head,23);    
    insertAtStart(&head,4);    
    insertAtStart(&head,12);    

    printList(head);

    return 0;
}