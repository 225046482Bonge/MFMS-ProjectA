
#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "validation.h"

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


void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalary(void);
void displayEmployeeInfo(void);
void updateSalaries(double salaries[]);

int employeeMenu(double salaries[]) {
    int choice;

    do {
        printf("\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search for Employee\n");
        printf("4. Calculate Employee Salary\n");
        printf("5. Display Employee Information\n");
        printf("6. Exit\n");
        choice = getInt("Enter your choice: ", 1, 6);

        switch (choice) {
            case 1:
                addEmployee();
                updateSalaries(salaries);
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

    return employeeCount;
}


/* Copies each employee's gross salary into salaries[] so Reports can use it */
void updateSalaries(double salaries[]) {
    int i;

    for (i = 0; i < employeeCount; i++) {
        salaries[i] = employees[i].basicSalary
                    + employees[i].housingAllowance
                    + employees[i].transportAllowance
                    + employees[i].otherAllowance;
    }
}


void addEmployee(void) {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Employee list is full!\n");
        return;
    }

    printf("\n===== ADD EMPLOYEE =====\n");

    employees[employeeCount].employeeID = getInt("Enter Employee ID: ", 1, 999999);
    getNonEmptyString("Enter Employee Name: ", employees[employeeCount].name);
    getNonEmptyString("Enter Department: ", employees[employeeCount].department);
    employees[employeeCount].basicSalary = getDouble("Enter Basic Salary: ", 0, 1000000);
    employees[employeeCount].housingAllowance = getDouble("Enter Housing Allowance: ", 0, 1000000);
    employees[employeeCount].transportAllowance = getDouble("Enter Transport Allowance: ", 0, 1000000);
    employees[employeeCount].otherAllowance = getDouble("Enter Other Allowance: ", 0, 1000000);

    employeeCount++;

    printf("Employee added successfully!\n");
}


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


void searchEmployee(void) {
    int id, i, found = 0;

    id = getInt("Enter Employee ID to search: ", 1, 999999);

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


void calculateSalary(void) {
    int id, i, found = 0;
    float grossSalary, tax, netSalary;

    id = getInt("Enter Employee ID: ", 1, 999999);

    for (i = 0; i < employeeCount; i++) {
        if (employees[i].employeeID == id) {

            grossSalary = employees[i].basicSalary
                        + employees[i].housingAllowance
                        + employees[i].transportAllowance
                        + employees[i].otherAllowance;

            
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


void displayEmployeeInfo(void) {
    int id, i, found = 0;

    id = getInt("Enter Employee ID: ", 1, 999999);

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
