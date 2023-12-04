#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in the queue
struct Node {
    int data;
    struct Node *next;
};

// Define structure for the queue
struct Queue {
    struct Node *front, *rear;
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

    // Free allocated memory before exiting
    struct Node *current = queue.front;
    struct Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}

// Function to initialize the queue
void initializeQueue(struct Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue *queue, int element) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        // If queue is empty, both front and rear point to the new node
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Otherwise, update the rear to the new node
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *queue) {
    if (queue->front == NULL) {
        return -1; // Queue is empty
    } else {
        int element = queue->front->data;
        struct Node *temp = queue->front;

        if (queue->front == queue->rear) {
            // If only one node is present, reset front and rear
            queue->front = NULL;
            queue->rear = NULL;
        } else {
            // Otherwise, move front to the next node
            queue->front = queue->front->next;
        }

        free(temp);
        return element;
    }
}

// Function to display the queue
void displayQueue(struct Queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        struct Node *current = queue->front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
