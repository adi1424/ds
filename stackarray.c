#include <stdio.h>

#define MAX_SIZE 100

// Define structure for the stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Function prototypes
void initializeStack(struct Stack *stack);
void push(struct Stack *stack, int element);
int pop(struct Stack *stack);
void displayStack(struct Stack *stack);

int main() {
    struct Stack stack;
    int choice, element;

    initializeStack(&stack);

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(&stack, element);
                printf("Element %d pushed onto the stack.\n", element);
                break;
            case 2:
                element = pop(&stack);
                if (element != -1) {
                    printf("Element %d popped from the stack.\n", element);
                } else {
                    printf("Stack is empty. Cannot pop.\n");
                }
                break;
            case 3:
                displayStack(&stack);
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

// Function to initialize the stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int element) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow. Cannot push.\n");
    } else {
        stack->arr[++(stack->top)] = element;
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (stack->top == -1) {
        return -1; // Stack is empty
    } else {
        return stack->arr[(stack->top)--];
    }
}

// Function to display the stack
void displayStack(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}
