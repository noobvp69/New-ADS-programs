#include <stdio.h>
#include <stdlib.h>

// Define Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode; // Points to itself (circular link)
    return newNode;
}

// Function to insert a node at the end
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If the list is empty, new node is the head
    } else {
        Node* temp = *head;
        // Traverse till last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode; // Set the next of last node to the new node
        newNode->next = *head; // Set new node's next to head to maintain circularity
    }
    printf("%d inserted at the end of the list\n", data);
}

// Function to insert a node at the beginning
void insertBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If the list is empty, new node is the head
    } else {
        Node* temp = *head;
        // Traverse to last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head; // New node's next points to the current head
        *head = newNode; // Head is updated to the new node
        temp->next = *head; // Last node's next updated to new head
    }
    printf("%d inserted at the beginning of the list\n", data);
}

// Function to delete a node from the beginning
void deleteBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    if ((*head)->next == *head) { // Only one node in the list
        *head = NULL;
    } else {
        Node* last = *head;
        // Traverse to the last node
        while (last->next != *head) {
            last = last->next;
        }
        *head = (*head)->next; // Move the head to the next node
        last->next = *head; // Update the last node's next to the new head
    }
    free(temp);
    printf("Node deleted from the beginning\n");
}

// Function to delete a node from the end
void deleteEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    if ((*head)->next == *head) { // Only one node in the list
        free(*head);
        *head = NULL;
    } else {
        Node* prev = NULL;
        // Traverse to the second last node
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head; // Update second last node's next to head
        free(temp);
    }
    printf("Node deleted from the end\n");
}

// Function to display the circular linked list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function
int main() {
    Node* head = NULL; // Initialize an empty list

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertBeginning(&head, 5);
    display(head);

    deleteBeginning(&head);
    display(head);

    deleteEnd(&head);
    display(head);

    return 0;
}

