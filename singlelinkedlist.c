#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function prototypes
struct Node* createNode(int value);
struct Node* insertAtBeginning(struct Node *head, int value);
struct Node* deleteEndNode(struct Node *head);
void displayList(struct Node *head);
struct Node* searchValue(struct Node *head, int value);

int main() {
    struct Node *head = NULL;
    int choice, value;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Delete End Node\n");
        printf("3. Display List\n");
        printf("4. Search Value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                printf("Node inserted at the beginning.\n");
                break;
            case 2:
                head = deleteEndNode(head);
                if (head != NULL) {
                    printf("End node deleted.\n");
                } else {
                    printf("List is empty. No node to delete.\n");
                }
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                struct Node *result = searchValue(head, value);
                if (result != NULL) {
                    printf("Value %d found in the list.\n", value);
                } else {
                    printf("Value %d not found in the list.\n", value);
                }
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

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node *head, int value) {
    struct Node *newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Function to delete the end node of the linked list
struct Node* deleteEndNode(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        // Empty list or only one node
        free(head);
        return NULL;
    }

    struct Node *current = head;
    struct Node *previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    free(current);
    previous->next = NULL;

    return head;
}

// Function to display the linked list
void displayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to search for a value in the linked list
struct Node* searchValue(struct Node *head, int value) {
    struct Node *current = head;

    while (current != NULL) {
        if (current->data == value) {
            return current; // Value found
        }
        current = current->next;
    }

    return NULL; // Value not found
}
