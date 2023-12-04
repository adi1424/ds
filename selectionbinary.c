#include <stdio.h>

// Function prototypes
void selectionSort(int arr[], int n);
int binarySearch(int arr[], int low, int high, int key);
void displayArray(int arr[], int n);

int main() {
    int choice, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Selection Sort\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                selectionSort(arr, n);
                printf("Array after Selection Sort:\n");
                displayArray(arr, n);
                break;
            case 2:
                {
                    int key;
                    printf("Enter the element to search: ");
                    scanf("%d", &key);
                    int result = binarySearch(arr, 0, n - 1, key);
                    if (result != -1) {
                        printf("Element %d found at index %d.\n", key, result);
                    } else {
                        printf("Element %d not found in the array.\n", key);
                    }
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to perform Binary Search
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Key not found
}

// Function to display the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
