#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert element into the heap
void insert(int value) {
    if (size >= MAX) {
        printf("Heap Overflow\n");
        return;
    }
    heap[size++] = value; // Insert at end
    int i = size - 1;
    
    // Reheapify the heap upward
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

// Delete root element from the heap
int deleteRoot() {
    if (size <= 0) {
        printf("Heap Underflow\n");
        return -1;
    }
    int root = heap[0];
    heap[0] = heap[--size]; // Replace root with last element
    
    int i = 0;
    // Reheapify the heap downward
    while (2 * i + 1 < size) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;
        if (largest == i)
            break;
        
        swap(&heap[i], &heap[largest]);
        i = largest;
    }
    return root;
}

// Display the heap array
void displayHeap() {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insert(20);
    insert(15);
    insert(30);
    insert(40);
    insert(50);
    printf("Heap after insertions: ");
    displayHeap();

    printf("Deleted root: %d\n", deleteRoot());
    printf("Heap after deletion: ");
    displayHeap();

    return 0;
}

