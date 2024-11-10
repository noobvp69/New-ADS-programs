#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Add node at the end of the list
void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) *head = newNode;
    else {
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// Insert node at the beginning
void insertBegin(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Insert node at the end
void insertEnd(struct Node** head, int data) {
    addNode(head, data);
}

// Insert node at a given position
void insertMiddle(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    int i = 0;
    newNode->data = data;

    if (position == 0) {
        insertBegin(head, data);
        return;
    }
    
    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) printf("Position out of range\n");
    else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Delete node from the beginning
void deleteBegin(struct Node** head) {
    if (*head == NULL) printf("List is empty\n");
    else {
        struct Node* temp = *head;
        *head = temp->next;
        free(temp);
    }
}

// Delete node from the end
void deleteEnd(struct Node** head) {
    if (*head == NULL) printf("List is empty\n");
    else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        while (temp->next && temp->next->next) temp = temp->next;
        free(temp->next);
        temp->next = NULL;
    }
}

// Delete node at a given position
void deleteMiddle(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    if (position == 0) {
        deleteBegin(head);
        return;
    }

    int i = 0;
    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) printf("Position out of range\n");
    else {
        struct Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}

// Search for an element
void searchNode(struct Node* head, int data) {
    struct Node* temp = head;
    int index = 0;
    while (temp) {
        if (temp->data == data) {
            printf("Found element %d at index %d\n", data, index);
            return;
        }
        temp = temp->next;
        index++;
    }
    printf("Element not found\n");
}

// Display the list
void displayList(struct Node* head) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    displayList(head);

    insertBegin(&head, 5);  // Insert at beginning
    displayList(head);

    insertEnd(&head, 40);   // Insert at end
    displayList(head);

    insertMiddle(&head, 25, 2);  // Insert at position 2
    displayList(head);

    deleteBegin(&head);    // Delete from beginning
    displayList(head);

    deleteEnd(&head);      // Delete from end
    displayList(head);

    deleteMiddle(&head, 1); // Delete at position 1
    displayList(head);

    searchNode(head, 25);  // Search for element
    searchNode(head, 100); // Search for element not in the list

    return 0;
}

