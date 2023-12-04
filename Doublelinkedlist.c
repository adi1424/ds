#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function prototypes
struct Node* createNode(int value);
struct Node* insertAtEnd(struct Node *head, int value);
struct Node* deleteFromBegin(struct Node *head);
void displayList(struct Node *head);
void updateNode(struct Node *head);

int main() {
    struct Node *head = NULL;
    int choice, value;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Insert at End\n");
        printf("2. Delete from Beginning\n");
        printf("3. Display List\n");
        printf("4. Update Node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                printf("Node inserted at the end.\n");
                break;
            case 2:
                head = deleteFromBegin(head);
                if (head != NULL) {
                    printf("Node deleted from the beginning.\n");
                } else {
                    printf("List is empty. No node to delete.\n");
                }
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                updateNode(head);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    // Free allocated memory before exiting
    struct Node *current = head;
    struct Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}

// Function to create a new node with the given value
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
struct Node* insertAtEnd(struct Node *head, int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        return newNode; // If list is empty, new node becomes the head
    }

    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;

    return head;
}

// Function to delete a node from the beginning of the doubly linked list
struct Node* deleteFromBegin(struct Node *head) {
    if (head == NULL) {
        return NULL; // Empty list, nothing to delete
    }

    struct Node *newHead = head->next;

    if (newHead != NULL) {
        newHead->prev = NULL;
    }

    free(head);

    return newHead;
}

// Function to display the doubly linked list
void displayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to update a node's value in the doubly linked list
void updateNode(struct Node *head) {
    int oldValue, newValue;

    if (head == NULL) {
        printf("List is empty. No node to update.\n");
        return;
    }

    printf("Enter the value of the node to update: ");
    scanf("%d", &oldValue);

    struct Node *current = head;
    while (current != NULL) {
        if (current->data == oldValue) {
            printf("Enter the new value for the node: ");
            scanf("%d", &newValue);
            current->data = newValue;
            printf("Node updated successfully.\n");
            return;
        }
        current = current->next;
    }

    printf("Value %d not found in the list. No node updated.\n", oldValue);
}
