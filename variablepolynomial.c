#include <stdio.h>
#include <stdlib.h>

// Define structure for a term in the polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
};

// Function prototypes
struct Term* createTerm(int coefficient, int exponent);
struct Term* insertTerm(struct Term *head, int coefficient, int exponent);
double evaluatePolynomial(struct Term *head, double x);
void displayPolynomial(struct Term *head);

int main() {
    struct Term *head = NULL;
    int choice, coefficient, exponent;
    double x;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Insert Term\n");
        printf("2. Evaluate Polynomial\n");
        printf("3. Display Polynomial\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the coefficient of the term: ");
                scanf("%d", &coefficient);
                printf("Enter the exponent of the term: ");
                scanf("%d", &exponent);
                head = insertTerm(head, coefficient, exponent);
                printf("Term inserted.\n");
                break;
            case 2:
                printf("Enter the value of x for evaluation: ");
                scanf("%lf", &x);
                printf("Result: %.2f\n", evaluatePolynomial(head, x));
                break;
            case 3:
                displayPolynomial(head);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free allocated memory before exiting
    struct Term *current = head;
    struct Term *nextTerm;
    while (current != NULL) {
        nextTerm = current->next;
        free(current);
        current = nextTerm;
    }

    return 0;
}

// Function to create a new term with the given coefficient and exponent
struct Term* createTerm(int coefficient, int exponent) {
    struct Term *newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into the singly linked list representing the polynomial
struct Term* insertTerm(struct Term *head, int coefficient, int exponent) {
    struct Term *newTerm = createTerm(coefficient, exponent);

    if (head == NULL) {
        return newTerm; // If list is empty, new term becomes the head
    }

    struct Term *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newTerm;

    return head;
}

// Function to evaluate the polynomial for a given value of x
double evaluatePolynomial(struct Term *head, double x) {
    double result = 0.0;

    struct Term *current = head;
    while (current != NULL) {
        result += current->coefficient * pow(x, current->exponent);
        current = current->next;
    }

    return result;
}

// Function to display the polynomial
void displayPolynomial(struct Term *head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    struct Term *current = head;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);

        if (current->next != NULL) {
            printf(" + ");
        }

        current = current->next;
    }

    printf("\n");
}
