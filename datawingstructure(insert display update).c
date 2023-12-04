#include <stdio.h>
#include <string.h>

// Define structure for student data
struct Student {
    char name[50];
    int rollNo;
    long long prn;
};

// Function prototypes
void insertStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void updateStudent(struct Student students[], int count);

int main() {
    struct Student students[100]; // Assuming a maximum of 100 students
    int count = 0; // Number of students currently stored

    int choice;
    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Insert Student\n");
        printf("2. Display Students\n");
        printf("3. Update Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                updateStudent(students, count);
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

// Function to insert a new student
void insertStudent(struct Student students[], int *count) {
    if (*count < 100) {
        printf("Enter Student Details:\n");
        printf("Name: ");
        scanf("%s", students[*count].name);
        printf("Roll Number: ");
        scanf("%d", &students[*count].rollNo);
        printf("PRN: ");
        scanf("%lld", &students[*count].prn);

        (*count)++;
        printf("Student inserted successfully.\n");
    } else {
        printf("Cannot insert more students. Maximum limit reached.\n");
    }
}

// Function to display all students
void displayStudents(struct Student students[], int count) {
    if (count > 0) {
        printf("\nStudent Details:\n");
        for (int i = 0; i < count; i++) {
            printf("Name: %s\n", students[i].name);
            printf("Roll Number: %d\n", students[i].rollNo);
            printf("PRN: %lld\n", students[i].prn);
            printf("\n");
        }
    } else {
        printf("No students to display.\n");
    }
}

// Function to update student data
void updateStudent(struct Student students[], int count) {
    if (count > 0) {
        int rollToUpdate;
        printf("Enter the Roll Number of the student to update: ");
        scanf("%d", &rollToUpdate);

        int foundIndex = -1;
        for (int i = 0; i < count; i++) {
            if (students[i].rollNo == rollToUpdate) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex != -1) {
            printf("Enter updated details for student %s:\n", students[foundIndex].name);
            printf("Name: ");
            scanf("%s", students[foundIndex].name);
            printf("PRN: ");
            scanf("%lld", &students[foundIndex].prn);

            printf("Student details updated successfully.\n");
        } else {
            printf("Student with Roll Number %d not found.\n", rollToUpdate);
        }
    } else {
        printf("No students to update.\n");
    }
}
