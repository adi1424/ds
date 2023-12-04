#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in the singly circular linked list
struct Node {
    int data;
    struct Node *next;
};

// Function prototypes
struct Node* createNode(int value);
struct Node* insertNode(struct Node *head, int value);
struct Node* deleteNode(struct Node *head, int value);
void updateNode(struct Node *head, int oldValue, int newValue);
void displayList(struct Node *head);

int main() {
    struct Node *head = NULL;
    int choice, value, oldValue, newValue;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Update Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertNode(head, value);
                printf("Node inserted.\n");
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                if (head != NULL) {
                    printf("Node deleted.\n");
                } else {
                    printf("List is empty. No node to delete.\n");
                }
                break;
            case 3:
                printf("Enter the value of the node to update: ");
                scanf("%d", &oldValue);
                printf("Enter the new value for the node: ");
                scanf("%d", &newValue);
                updateNode(head, oldValue, newValue);
                break;
            case 4:
                displayList(head);
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
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the singly circular linked list
struct Node* insertNode(struct Node *head, int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode; // If list is empty, circular reference to itself
        return newNode;
    }

    struct Node *current = head;
    while (current->next != head) {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = head;

    return head;
}

// Function to delete a node from the singly circular linked list
struct Node* deleteNode(struct Node *head, int value) {
    if (head == NULL) {
        return NULL; // Empty list, nothing to delete
    }

    struct Node *current = head;
    struct Node *previous = NULL;

    do {
        if (current->data == value) {
            if (previous == NULL) {
                // Deleting the head node
                struct Node *lastNode = head;
                while (lastNode->next != head) {
                    lastNode = lastNode->next;
                }

                if (lastNode == head) {
                    // Only one node in the list
                    free(head);
                    return NULL;
                }

                lastNode->next = head->next;
                head = head->next;
            } else {
                previous->next = current->next;
                free(current);
            }
            return head;
        }

        previous = current;
        current = current->next;
    } while (current != head);

    // Value not found
    return head;
}

// Function to update a node's value in the singly circular linked list
void updateNode(struct Node *head, int oldValue, int newValue) {
    if (head == NULL) {
        printf("List is empty. No node to update.\n");
        return;
    }

    struct Node *current = head;

    do {
        if (current->data == oldValue) {
            current->data = newValue;
            printf("Node updated successfully.\n");
            return;
        }

        current = current->next;
    } while (current != head);

    printf("Value %d not found in the list. No node updated.\n", oldValue);
}

// Function to display the singly circular linked list
void displayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = head;

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("(head)\n");
}
