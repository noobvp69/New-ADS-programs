// Regular Queue Implementation
#include <stdio.h>
#define MAX 5

// Regular Queue
int queue[MAX];
int front = -1;
int rear = -1;

// Regular Queue Functions
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Enqueued %d successfully\n", value);
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    int value = queue[front];
    front++;
    if (front > rear) {
        front = rear = -1;  // Reset queue when last element is dequeued
    }
    printf("Dequeued %d successfully\n", value);
    return value;
}

void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Circular Queue Implementation
#define CMAX 5
int cqueue[CMAX];
int cfront = -1;
int crear = -1;

void cenqueue(int value) {
    if ((crear + 1) % CMAX == cfront) {
        printf("Circular Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (cfront == -1) {
        cfront = 0;
    }
    crear = (crear + 1) % CMAX;
    cqueue[crear] = value;
    printf("Enqueued %d successfully in circular queue\n", value);
}

int cdequeue() {
    if (cfront == -1) {
        printf("Circular Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    int value = cqueue[cfront];
    if (cfront == crear) {
        cfront = crear = -1;  // Reset when last element is dequeued
    } else {
        cfront = (cfront + 1) % CMAX;
    }
    printf("Dequeued %d successfully from circular queue\n", value);
    return value;
}

void displayCQueue() {
    if (cfront == -1) {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Circular Queue elements: ");
    if (crear >= cfront) {
        for (int i = cfront; i <= crear; i++) {
            printf("%d ", cqueue[i]);
        }
    } else {
        for (int i = cfront; i < CMAX; i++) {
            printf("%d ", cqueue[i]);
        }
        for (int i = 0; i <= crear; i++) {
            printf("%d ", cqueue[i]);
        }
    }
    printf("\n");
}

int main() {
    // Regular Queue Operations
    printf("\nRegular Queue Operations:\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    displayQueue();
    dequeue();
    displayQueue();
    
    // Circular Queue Operations
    printf("\nCircular Queue Operations:\n");
    cenqueue(1);
    cenqueue(2);
    cenqueue(3);
    displayCQueue();
    cdequeue();
    cenqueue(4);
    displayCQueue();
    
    return 0;
}
