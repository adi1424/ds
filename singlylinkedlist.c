#include <stdio.h>
#include <stdlib.h>

// Node structure for a term in the polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term with given coefficient and exponent
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into the polynomial in descending order of exponents
void insertTerm(struct Term** head, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);

    // If the list is empty or the new term has a higher exponent than the head
    if (*head == NULL || exponent > (*head)->exponent) {
        newTerm->next = *head;
        *head = newTerm;
    } else {
        // Traverse the list to find the correct position to insert the new term
        struct Term* current = *head;
        while (current->next != NULL && exponent < current->next->exponent) {
            current = current->next;
        }

        // Insert the new term
        newTerm->next = current->next;
        current->next = newTerm;
    }

    printf("Term (%dx^%d) added to the polynomial.\n", coefficient, exponent);
}

// Function to evaluate the polynomial for a given value of x
int evaluatePolynomial(struct Term* head, int x) {
    int result = 0;
    struct Term* current = head;

    while (current != NULL) {
        result += current->coefficient * power(x, current->exponent);
        current = current->next;
    }

    return result;
}

// Function to calculate the power of a number
int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Function to display the polynomial
void displayPolynomial(struct Term* head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    struct Term* current = head;

    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;

        if (current != NULL) {
            printf(" + ");
        }
    }

    printf("\n");
}

int main() {
    struct Term* polynomial = NULL;
    int choice, coefficient, exponent, x;

    do {
        printf("\nPolynomial Operations Menu:\n");
        printf("1. Add Term\n");
        printf("2. Evaluate Polynomial\n");
        printf("3. Display Polynomial\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter coefficient of the term: ");
                scanf("%d", &coefficient);
                printf("Enter exponent of the term: ");
                scanf("%d", &exponent);
                insertTerm(&polynomial, coefficient, exponent);
                break;

            case 2:
                if (polynomial == NULL) {
                    printf("Polynomial is empty. Cannot evaluate.\n");
                } else {
                    printf("Enter the value of x for evaluation: ");
                    scanf("%d", &x);
                    printf("Result of the polynomial for x = %d: %d\n", x, evaluatePolynomial(polynomial, x));
                }
                break;

            case 3:
                displayPolynomial(polynomial);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 4);

    // Free the memory allocated for the terms before exiting
    struct Term* current = polynomial;
    struct Term* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
