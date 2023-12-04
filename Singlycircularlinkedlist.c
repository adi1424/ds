#include <stdio.h>
#include <stdlib.h>

// Node structure for the singly circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        // If the list is empty, make the new node the head and point to itself
        *head = newNode;
        (*head)->next = *head;
    } else {
        // Traverse the list to find the last node
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = newNode;
        newNode->next = *head;
    }

    printf("Node with data %d inserted.\n", data);
}

// Function to delete a node with a given data value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *current = *head, *prev = NULL;

    // If the node to be deleted is the head
    if (current->data == key) {
        while (current->next != *head) {
            current = current->next;
        }
        if (*head == (*head)->next) {
            // If there is only one node, make the list empty
            free(*head);
            *head = NULL;
        } else {
            // Remove the head and update the head to the next node
            prev = *head;
            *head = (*head)->next;
            current->next = *head;
            free(prev);
        }

        printf("Node with data %d deleted.\n", key);
        return;
    }

    // If the node to be deleted is not the head
    while (current->next != *head && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current->data != key) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    // Remove the node
    prev->next = current->next;
    free(current);

    printf("Node with data %d deleted.\n", key);
}

// Function to update a node with a given data value
void updateNode(struct Node* head, int oldData, int newData) {
    if (head == NULL) {
        printf("List is empty. Cannot update.\n");
        return;
    }

    struct Node* current = head;

    do {
        if (current->data == oldData) {
            // Update the data value
            current->data = newData;
            printf("Node with data %d updated to %d.\n", oldData, newData);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Node with data %d not found. Cannot update.\n", oldData);
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, key, newData;

    do {
        printf("\nSingly Circular Linked List Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Update\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;

            case 3:
                printf("Enter data to update: ");
                scanf("%d", &key);
                printf("Enter new data: ");
                scanf("%d", &newData);
                updateNode(head, key, newData);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 5);

    // Free the memory allocated for the nodes before exiting
    struct Node* current = head;
    struct Node* next;

    if (head != NULL) {
        do {
            next = current->next;
            free(current);
            current = next;
        } while (current != head);
    }

    return 0;
}
