#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "validation.h"

#define EMP_FILE "employees.txt"

static int employeeFind(char ids[][50], int count, char id[])
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (equalsIgnoreCase(ids[i], id))
        {
            return i;
        }
    }
    return -1;
}

static void printEmployeeHeader(void)
{
    printf("\n====================================================================================\n");
    printf("%-10s %-22s %-20s %-18s\n", "ID", "Name", "Department", "Monthly Salary");
    printf("====================================================================================\n");
}

static void printEmployeeRow(char ids[][50], char names[][50],
                             char departments[][50], double salaries[], int index)
{
    printf("%-10s %-22s %-20s %-18s\n",
           ids[index], names[index], departments[index], formatMoney(salaries[index]));
}

static int addEmployee(char ids[][50], char names[][50], char departments[][50],
                       double salaries[], int count)
{
    char id[50];

    if (count >= MAX_EMPLOYEES)
    {
        printf("\nError: Employee list is full (max %d employees).\n", MAX_EMPLOYEES);
        return count;
    }

    do
    {
        getNonEmptyString("\nEnter Employee ID: ", id);
        if (employeeFind(ids, count, id) != -1)
        {
            printf("Error: Employee ID '%s' already exists. Try another ID.\n", id);
        }
    } while (employeeFind(ids, count, id) != -1);

    strcpy(ids[count], id);
    getNonEmptyString("Enter Employee Name: ", names[count]);
    getNonEmptyString("Enter Department: ", departments[count]);
    salaries[count] = getDouble("Enter Monthly Salary (N$): ", 0.0, 1000000.0);

    printf("\nEmployee added successfully!\n");
    return count + 1;
}

static void displayEmployees(char ids[][50], char names[][50], char departments[][50],
                             double salaries[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo employee records available.\n");
        return;
    }

    printEmployeeHeader();
    for (i = 0; i < count; i++)
    {
        printEmployeeRow(ids, names, departments, salaries, i);
    }
    printf("====================================================================================\n");
    printf("Total employees: %d\n", count);
}

static void searchEmployeeById(char ids[][50], char names[][50], char departments[][50],
                               double salaries[], int count)
{
    char id[50];
    int index;

    if (count == 0)
    {
        printf("\nNo employees available to search.\n");
        return;
    }

    getNonEmptyString("\nEnter Employee ID to search: ", id);
    index = employeeFind(ids, count, id);

    if (index == -1)
    {
        printf("Employee with ID '%s' not found.\n", id);
    }
    else
    {
        printEmployeeHeader();
        printEmployeeRow(ids, names, departments, salaries, index);
        printf("====================================================================================\n");
    }
}

static void searchEmployeeByName(char ids[][50], char names[][50], char departments[][50],
                                 double salaries[], int count)
{
    char term[50];
    int found = 0;
    int i;

    if (count == 0)
    {
        printf("\nNo employees available to search.\n");
        return;
    }

    getNonEmptyString("\nEnter name (or part of a name) to search: ", term);

    printEmployeeHeader();
    for (i = 0; i < count; i++)
    {
        if (nameContains(names[i], term))
        {
            printEmployeeRow(ids, names, departments, salaries, i);
            found++;
        }
    }
    printf("====================================================================================\n");

    if (found == 0)
    {
        printf("No employees found matching '%s'.\n", term);
    }
    else
    {
        printf("Employees found: %d\n", found);
    }
}

static void salaryInformation(char names[][50], double salaries[], int count)
{
    double total = 0.0;
    int highest = 0;
    int lowest = 0;
    int i;

    if (count == 0)
    {
        printf("\nNo employee records available for salary information.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        total += salaries[i];
        if (salaries[i] > salaries[highest]) highest = i;
        if (salaries[i] < salaries[lowest]) lowest = i;
    }

    printf("\n========================================\n");
    printf("          SALARY INFORMATION            \n");
    printf("========================================\n");
    printf("Total Employees:      %d\n", count);
    printf("Total Monthly Salary: %s\n", formatMoney(total));
    printf("Average Salary:       %s\n", formatMoney(total / count));
    printf("Highest Salary:       %s (%s)\n", formatMoney(salaries[highest]), names[highest]);
    printf("Lowest Salary:        %s (%s)\n", formatMoney(salaries[lowest]), names[lowest]);
    printf("========================================\n");
}

static void employeeDetails(char ids[][50], char names[][50], char departments[][50],
                            double salaries[], int count)
{
    char id[50];
    int index;

    if (count == 0)
    {
        printf("\nNo employees available.\n");
        return;
    }

    getNonEmptyString("\nEnter Employee ID: ", id);
    index = employeeFind(ids, count, id);

    if (index == -1)
    {
        printf("Employee with ID '%s' not found.\n", id);
        return;
    }

    printf("\n========================================\n");
    printf("          EMPLOYEE INFORMATION          \n");
    printf("========================================\n");
    printf("ID:             %s\n", ids[index]);
    printf("Name:           %s\n", names[index]);
    printf("Department:     %s\n", departments[index]);
    printf("Monthly Salary: %s\n", formatMoney(salaries[index]));
    printf("Yearly Salary:  %s\n", formatMoney(salaries[index] * 12));
    printf("========================================\n");
}

static int loadEmployees(char ids[][50], char names[][50], char departments[][50],
                         double salaries[])
{
    FILE *file = fopen(EMP_FILE, "r");
    int count = 0;

    if (file == NULL)
    {
        return 0;
    }

    while (count < MAX_EMPLOYEES &&
           fscanf(file, " %49[^,],%49[^,],%49[^,],%lf",
                  ids[count], names[count], departments[count], &salaries[count]) == 4)
    {
        count++;
    }

    fclose(file);
    return count;
}

static void saveEmployees(char ids[][50], char names[][50], char departments[][50],
                          double salaries[], int count)
{
    FILE *file = fopen(EMP_FILE, "w");
    int i;

    if (file == NULL)
    {
        printf("Error: Unable to save employees to %s.\n", EMP_FILE);
        return;
    }

    for (i = 0; i < count; i++)
    {
        fprintf(file, "%s,%s,%s,%.2f\n", ids[i], names[i], departments[i], salaries[i]);
    }

    fclose(file);
}

int employeeMenu(double outSalaries[])
{
    char ids[MAX_EMPLOYEES][50];
    char names[MAX_EMPLOYEES][50];
    char departments[MAX_EMPLOYEES][50];
    double salaries[MAX_EMPLOYEES];
    int count = loadEmployees(ids, names, departments, salaries);
    int choice;
    int i;

    do
    {
        printf("\n========================================\n");
        printf("       EMPLOYEE MANAGEMENT MODULE       \n");
        printf("========================================\n");
        printf("1. Add New Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Search Employee by Name\n");
        printf("5. Salary Information\n");
        printf("6. Display Employee Information\n");
        printf("7. Save and Back to Main Menu\n");
        printf("========================================\n");

        choice = getInt("Select an option (1-7): ", 1, 7);

        switch (choice)
        {
            case 1:
                count = addEmployee(ids, names, departments, salaries, count);
                break;
            case 2:
                displayEmployees(ids, names, departments, salaries, count);
                break;
            case 3:
                searchEmployeeById(ids, names, departments, salaries, count);
                break;
            case 4:
                searchEmployeeByName(ids, names, departments, salaries, count);
                break;
            case 5:
                salaryInformation(names, salaries, count);
                break;
            case 6:
                employeeDetails(ids, names, departments, salaries, count);
                break;
            case 7:
                saveEmployees(ids, names, departments, salaries, count);
                printf("Saving employee records... Returning to main menu.\n");
                break;
        }
    } while (choice != 7);

    for (i = 0; i < count; i++)
    {
        outSalaries[i] = salaries[i];
    }
    return count;
}