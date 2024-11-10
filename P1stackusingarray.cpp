#include <stdio.h>
#define MAX 10  // maximum size of the stack

int stack[MAX];
int top = -1;

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d onto the stack.\n", value);
    } else {
        stack[++top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop from the stack.\n");
        return -1;
    } else {
        int value = stack[top--];
        printf("Popped %d from the stack.\n", value);
        return value;
    }
}

// Function to peek at the top element of the stack
int peek() {
    if (isEmpty()) {
        printf("Stack is empty. No top element.\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Function to display the elements of the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    // Sample operations
    push(10);
    push(20);
    push(30);
    display();

    printf("Top element is %d\n", peek());
    
    pop();
    pop();
    display();

    return 0;
}

