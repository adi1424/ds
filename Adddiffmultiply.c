#include <stdio.h>

void matrixAddition(int m, int n, int mat1[m][n], int mat2[m][n], int result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void matrixSubtraction(int m, int n, int mat1[m][n], int mat2[m][n], int result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void matrixMultiplication(int m1, int n1, int m2, int n2, int mat1[m1][n1], int mat2[m2][n2], int result[m1][n2]) {
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(int m, int n, int mat[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m1, n1, m2, n2;

    // Get dimensions of matrices from the user
    printf("Enter the dimensions of the first matrix (m1 n1): ");
    scanf("%d %d", &m1, &n1);

    printf("Enter the dimensions of the second matrix (m2 n2): ");
    scanf("%d %d", &m2, &n2);

    if (n1 != m2) {
        printf("Matrix multiplication not possible. Exiting...\n");
        return 1;
    }

    int matrix1[m1][n1], matrix2[m2][n2], result[m1][n2];

    // Get elements of matrices from the user
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    int choice;

    // Display menu and perform chosen operation
    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                matrixAddition(m1, n1, matrix1, matrix2, result);
                printf("Result of Addition:\n");
                displayMatrix(m1, n1, result);
                break;

            case 2:
                matrixSubtraction(m1, n1, matrix1, matrix2, result);
                printf("Result of Subtraction:\n");
                displayMatrix(m1, n1, result);
                break;

            case 3:
                matrixMultiplication(m1, n1, m2, n2, matrix1, matrix2, result);
                printf("Result of Multiplication:\n");
                displayMatrix(m1, n2, result);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
