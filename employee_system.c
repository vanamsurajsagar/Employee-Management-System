#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.txt"

// Define the Employee structure
typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

// Function declarations
void addEmployee();
void displayEmployees();

int main() {
    int choice;

    while (1) {
        printf("\n=== Employee Management System ===\n");
        printf("1. Add Employee Records\n");
        printf("2. Display All Employees\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a new employee and save to file
void addEmployee() {
    FILE *file = fopen(FILE_NAME, "a"); // Open file in append mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Employee emp;
    
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); // Clear the newline character from input buffer

    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0'; // Remove trailing newline character

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    // Write structure data into the file text lines
    fprintf(file, "%d,%s,%.2f\n", emp.id, emp.name, emp.salary);
    fclose(file);

    printf("Employee record saved successfully!\n");
}

// Function to read and display all employees from the file
void displayEmployees() {
    FILE *file = fopen(FILE_NAME, "r"); // Open file in read mode
    if (file == NULL) {
        printf("\nNo records found! Add an employee first.\n");
        return;
    }

    Employee emp;
    char line[100];

    printf("\n%-10s %-20s %-10s\n", "ID", "Name", "Salary");
    printf("--------------------------------------------\n");

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        // Parse the comma-separated text back into the structure parameters
        sscanf(line, "%d,%[^,],%f", &emp.id, emp.name, &emp.salary);
        printf("%-10d %-20s %-10.2f\n", emp.id, emp.name, emp.salary);
    }

    fclose(file);
}
