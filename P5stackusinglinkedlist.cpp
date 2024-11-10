#include <stdio.h>
#include <stdlib.h>

// Define Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to push an element to the stack
void push(Node** top, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", data);
}

// Function to pop an element from the stack
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1; // Indicating empty stack
    }
    Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

// Function to peek the top element of the stack
int peek(Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1; // Indicating empty stack
    }
    return top->data;
}

// Function to check if the stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}

// Main function
int main() {
    Node* top = NULL; // Initialize the stack

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printf("%d popped from stack\n", pop(&top));
    printf("Top element is %d\n", peek(top));

    if (isEmpty(top)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    return 0;
}

