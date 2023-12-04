#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Define structure for the stack
struct Stack {
    char arr[MAX_SIZE];
    int top;
};

// Function prototypes
void initializeStack(struct Stack *stack);
void push(struct Stack *stack, char element);
char pop(struct Stack *stack);
char peek(struct Stack *stack);
int isOperator(char ch);
int precedence(char ch);
void infixToPostfix(char infix[], char postfix[]);

int main() {
    struct Stack stack;
    initializeStack(&stack);

    char infix[MAX_SIZE], postfix[MAX_SIZE];
    int choice;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Input Infix Expression\n");
        printf("2. Convert to Postfix\n");
        printf("3. Display Postfix Expression\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the infix expression: ");
                scanf("%s", infix);
                break;
            case 2:
                infixToPostfix(infix, postfix);
                printf("Infix expression converted to postfix.\n");
                break;
            case 3:
                printf("Postfix expression: %s\n", postfix);
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
void push(struct Stack *stack, char element) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow. Cannot push.\n");
    } else {
        stack->arr[++(stack->top)] = element;
    }
}

// Function to pop an element from the stack
char pop(struct Stack *stack) {
    if (stack->top == -1) {
        return '\0'; // Stack is empty
    } else {
        return stack->arr[(stack->top)--];
    }
}

// Function to get the top element of the stack without popping it
char peek(struct Stack *stack) {
    if (stack->top == -1) {
        return '\0'; // Stack is empty
    } else {
        return stack->arr[stack->top];
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to determine precedence of an operator
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initializeStack(&stack);

    int i, j;
    char ch;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Discard the '('
        } else if (isOperator(infix[i])) {
            while (precedence(infix[i]) <= precedence(peek(&stack)) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}
