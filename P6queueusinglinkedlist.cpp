#include <stdio.h>
#include <stdlib.h>

// Define Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to enqueue (add element to the queue)
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued to queue\n", data);
}

// Function to dequeue (remove element from the queue)
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue underflow\n");
        return -1; // Indicating empty queue
    }
    Node* temp = q->front;
    int dequeuedData = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL; // If queue is empty after dequeue
    }
    free(temp);
    return dequeuedData;
}

// Function to peek the front element of the queue
int peek(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1; // Indicating empty queue
    }
    return q->front->data;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Main function
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("%d dequeued from queue\n", dequeue(&q));
    printf("Front element is %d\n", peek(&q));

    if (isEmpty(&q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    return 0;
}

