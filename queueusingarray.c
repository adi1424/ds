#include <stdio.h>

#define MAX_SIZE 100

// Define structure for the queue
struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

// Function prototypes
void initializeQueue(struct Queue *queue);
void enqueue(struct Queue *queue, int element);
int dequeue(struct Queue *queue);
void displayQueue(struct Queue *queue);

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    int choice, element;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(&queue, element);
                printf("Element %d enqueued.\n", element);
                break;
            case 2:
                element = dequeue(&queue);
                if (element != -1) {
                    printf("Element %d dequeued.\n", element);
                } else {
                    printf("Queue is empty. Cannot dequeue.\n");
                }
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to initialize the queue
void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue *queue, int element) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue overflow. Cannot enqueue.\n");
    } else {
        if (queue->front == -1) {
            // If queue is empty, update front
            queue->front = 0;
        }
        queue->arr[++(queue->rear)] = element;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *queue) {
    if (queue->front == -1) {
        return -1; // Queue is empty
    } else {
        int element = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            // If last element is dequeued, reset front and rear
            queue->front = -1;
            queue->rear = -1;
        } else {
            // Move front to the next position
            queue->front++;
        }
        return element;
    }
}

// Function to display the queue
void displayQueue(struct Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
        printf("\n");
    }
}
