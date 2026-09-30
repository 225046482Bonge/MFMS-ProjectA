/* main.c - Main menu and program start */
#include <stdio.h>
#include "mfms.h"
#include "validation.h"
#include "reports.h"

void displayMenu()
{
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
}

int main()
{
    int choice;
    double salaries[100];
    double budgets[MAX_DEPARTMENTS];
    double expenditures[MAX_DEPARTMENTS];
    char deptNames[MAX_DEPARTMENTS][50];
    char supplierNames[100][100];
    char supplierIDs[100][20];
    char assetNames[100][100];
    char assetIDs[100][20];
    double assetValues[100];
    int empCount = 0;
    int deptCount = 0;
    int supplierCount = 0;
    int assetCount = 0;

    do
    {
        displayMenu();
        choice = getInt("Enter your choice: ", 1, 6);

        switch (choice)
        {
            case 1:
                employeeMenu();
                break;
            case 2:
                budgetMenu();
                break;
            case 3:
                supplierMenu();
                break;
            case 4:
                assetMenu();
                break;
            case 5:
                displayReportsMenu(salaries, empCount,
                                   budgets, expenditures, deptNames, deptCount,
                                   supplierNames, supplierIDs, supplierCount,
                                   assetNames, assetIDs, assetValues, assetCount);
                break;
            case 6:
                printf("\nThank you. Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
