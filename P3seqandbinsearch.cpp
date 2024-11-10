#include <stdio.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int linearSearch(int arr[], int size, int item) {
    int first = -1, count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == item) {
            if (first == -1) first = i;
            count++;
        }
    }
    if (first != -1) printf("Found at index %d, occurrences: %d\n", first, count);
    else printf("Element not found\n");
    return first;
}

int binarySearch(int arr[], int size, int item) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == item) return printf("Element found at index %d\n", mid), mid;
        else if (arr[mid] < item) left = mid + 1;
        else right = mid - 1;
    }
    printf("Element not found\n");
    return -1;
}

int main() {
    int size, item, searchType;

    printf("Array size: ");
    scanf("%d", &size);
    int arr[size];

    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Element to search: ");
    scanf("%d", &item);
    printf("Search type (1=Linear, 2=Binary): ");
    scanf("%d", &searchType);

    if (searchType == 1) linearSearch(arr, size, item);
    else if (searchType == 2) {
        bubbleSort(arr, size);
        printf("Array sorted for Binary Search\n");
        binarySearch(arr, size, item);
    } else printf("Invalid choice\n");

    return 0;
}

