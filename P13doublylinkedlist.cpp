#include <stdio.h>
#include <stdlib.h>

// Define Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head) (*head)->prev = newNode;
    newNode->next = *head;
    *head = newNode;
}

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (!*head) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete from the beginning
void deleteFromBeginning(struct Node** head) {
    if (!*head) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head) (*head)->prev = NULL;
    free(temp);
}

// Delete from the end
void deleteFromEnd(struct Node** head) {
    if (!*head) return;
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    if (temp->prev) temp->prev->next = NULL;
    else *head = NULL;
    free(temp);
}

// Display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate list operations
int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    displayList(head);
    deleteFromBeginning(&head);
    displayList(head);
    deleteFromEnd(&head);
    displayList(head);
    return 0;
}

