
#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int employeeID;
    char name[50];
    char department[50];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
    float otherAllowance;
};

struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

/* Function declarations */
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalary(void);
void displayEmployeeInfo(void);

int main(void) {
    int choice;

    do {
        printf("\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search for Employee\n");
        printf("4. Calculate Employee Salary\n");
        printf("5. Display Employee Information\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                calculateSalary();
                break;

            case 5:
                displayEmployeeInfo();
                break;

            case 6:
                printf("Thank you for using the Employee Management System.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

/* Add an employee */
void addEmployee(void) {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Employee list is full!\n");
        return;
    }

    printf("\n===== ADD EMPLOYEE =====\n");

    printf("Enter Employee ID: ");
    scanf("%d", &employees[employeeCount].employeeID);

    getchar();

    printf("Enter Employee Name: ");
    fgets(employees[employeeCount].name,
          sizeof(employees[employeeCount].name), stdin);

    employees[employeeCount].name[
        strcspn(employees[employeeCount].name, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(employees[employeeCount].department,
          sizeof(employees[employeeCount].department), stdin);

    employees[employeeCount].department[
        strcspn(employees[employeeCount].department, "\n")] = '\0';

    printf("Enter Basic Salary: ");
    scanf("%f", &employees[employeeCount].basicSalary);

    printf("Enter Housing Allowance: ");
    scanf("%f", &employees[employeeCount].housingAllowance);

    printf("Enter Transport Allowance: ");
    scanf("%f", &employees[employeeCount].transportAllowance);

    printf("Enter Other Allowance: ");
    scanf("%f", &employees[employeeCount].otherAllowance);

    employeeCount++;

    printf("Employee added successfully!\n");
}

/* Display all employees */
void displayEmployees(void) {
    int i;

    if (employeeCount == 0) {
        printf("No employees have been added yet.\n");
        return;
    }

    printf("\n===== EMPLOYEE LIST =====\n");

    for (i = 0; i < employeeCount; i++) {
        printf("\nEmployee ID: %d\n", employees[i].employeeID);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Basic Salary: %.2f\n", employees[i].basicSalary);
        printf("Housing Allowance: %.2f\n", employees[i].housingAllowance);
        printf("Transport Allowance: %.2f\n", employees[i].transportAllowance);
        printf("Other Allowance: %.2f\n", employees[i].otherAllowance);
    }
}

/* Search for an employee */
void searchEmployee(void) {
    int id, i, found = 0;

    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < employeeCount; i++) {
        if (employees[i].employeeID == id) {
            printf("\nEmployee Found!\n");
            printf("ID: %d\n", employees[i].employeeID);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d was not found.\n", id);
    }
}

/* Calculate employee salary */
void calculateSalary(void) {
    int id, i, found = 0;
    float grossSalary, tax, netSalary;

    printf("Enter Employee ID: ");
    scanf("%d", &id);

    for (i = 0; i < employeeCount; i++) {
        if (employees[i].employeeID == id) {

            grossSalary = employees[i].basicSalary
                        + employees[i].housingAllowance
                        + employees[i].transportAllowance
                        + employees[i].otherAllowance;

            /* Example tax calculation */
            if (grossSalary <= 5000) {
                tax = 0;
            } else if (grossSalary <= 10000) {
                tax = grossSalary * 0.10;
            } else {
                tax = grossSalary * 0.20;
            }

            netSalary = grossSalary - tax;

            printf("\n===== SALARY DETAILS =====\n");
            printf("Employee Name: %s\n", employees[i].name);
            printf("Gross Salary: %.2f\n", grossSalary);
            printf("Tax: %.2f\n", tax);
            printf("Net Salary: %.2f\n", netSalary);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d was not found.\n", id);
    }
}

/* Display information about one employee */
void displayEmployeeInfo(void) {
    int id, i, found = 0;

    printf("Enter Employee ID: ");
    scanf("%d", &id);

    for (i = 0; i < employeeCount; i++) {
        if (employees[i].employeeID == id) {
            printf("\n===== EMPLOYEE DETAILS =====\n");
            printf("Employee ID: %d\n", employees[i].employeeID);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Basic Salary: %.2f\n", employees[i].basicSalary);
            printf("Housing Allowance: %.2f\n", employees[i].housingAllowance);
            printf("Transport Allowance: %.2f\n", employees[i].transportAllowance);
            printf("Other Allowance: %.2f\n", employees[i].otherAllowance);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found.\n");
    }
}
