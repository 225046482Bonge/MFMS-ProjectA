#include <stdio.h>
#include "reports.h"

//main entry point for the Reports module called from main.c
void displayReportsMenu(
    double salaries[], int empCount,
    double budgets[], double expenditures[], char deptNames[][50], int deptCount,
    char supplierNames[][100], char supplierIDs[][20], int supplierCount,
    char assetNames[][100], char assetIDs[][20], double assetValues[], int assetCount
) {
    int choice;
    do {
        printf("==============================================\n");
        printf("---------------- REPORTS MENU ----------------\n");
        printf("==============================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Return to Main Menu\n\n");
        printf("Enter your choice: ");
        
        //input validation for menu choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); //clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                generateEmployeeReport(salaries, empCount);
                break;
            case 2:
                generateBudgetReport(budgets, expenditures, deptNames, deptCount);
                break;
            case 3:
                generateSupplierReport(supplierNames, supplierIDs, supplierCount);
                break;
            case 4:
                generateAssetReport(assetNames, assetIDs, assetValues, assetCount);
                break;
            case 5:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    } while (choice != 5);
}

// 1. Employee Report Implementation
void generateEmployeeReport(double salaries[], int empCount) {
    printf("===============================================\n");
    printf("-------------- Employee Report ----------------\n");
    printf("===============================================\n");
    if (empCount == 0) {
        printf("No employees registered in the system.\n");
        return;
    }

    double totalSalary = 0;
    double highestSalary = salaries[0];
    double lowestSalary = salaries[0];

    for (int i = 0; i < empCount; i++) {
        totalSalary += salaries[i];
        if (salaries[i] > highestSalary) highestSalary = salaries[i];
        if (salaries[i] < lowestSalary) lowestSalary = salaries[i];
    }

    double averageSalary = totalSalary / empCount;

    printf("Total Employees: %d\n", empCount);
    printf("Average Salary: N$%.2f\n", averageSalary);
    printf("Highest Salary: N$%.2f\n", highestSalary);
    printf("Lowest Salary: N$%.2f\n\n", lowestSalary);
}

// 2. Budget Report Implementation
void generateBudgetReport(double budgets[], double expenditures[], char deptNames[][50], int deptCount) {
    printf("===============================================\n");
    printf("--------------- Budget Report -----------------\n");
    printf("===============================================\n");
    if (deptCount == 0) {
        printf("No departmental budget data available.\n");
        return;
    }

    double totalAllocated = 0;
    double totalExpenditure = 0;

    for (int i = 0; i < deptCount; i++) {
        totalAllocated += budgets[i];
        totalExpenditure += expenditures[i];
    }

    double remainingBudget = totalAllocated - totalExpenditure;

    printf("Total Allocated Budget: N$%.2f\n", totalAllocated);
    printf("Total Expenditure:      N$%.2f\n", totalExpenditure);
    printf("Remaining Budget:       N$%.2f\n\n", remainingBudget);
    
    printf("\nDepartments Exceeding Budget:\n");
    int exceededCount = 0;
    for (int i = 0; i < deptCount; i++) {
        if (expenditures[i] > budgets[i]) {
            printf(" %s (Exceeded by: N$%.2f)\n\n", deptNames[i], expenditures[i] - budgets[i]);
            exceededCount++;
        }
    }
    if (exceededCount == 0) {
        printf(" None. All departments are within budget.\n\n");
    }
}

// 3. Supplier Report Implementation
void generateSupplierReport(char supplierNames[][100], char supplierIDs[][20], int supplierCount) {
    printf("===============================================\n");
    printf("-------------- Supplier Report ----------------\n");
    printf("===============================================\n\n");
    if (supplierCount == 0) {
        printf("No suppliers registered in the system.\n\n");
        return;
    }

    printf("%-15s %-30s\n", "Supplier ID", "Supplier Name");
    printf("---------------------------------------------\n");
    for (int i = 0; i < supplierCount; i++) {
        printf("%-15s %-30s\n\n", supplierIDs[i], supplierNames[i]);
    }
}

// 4. Asset Report Implementation
void generateAssetReport(char assetNames[][100], char assetIDs[][20], double assetValues[], int assetCount) {
    printf("===============================================\n");
    printf("----------------- Asset Report ----------------\n");
    printf("===============================================\n\n");
    if (assetCount == 0) {
        printf("No assets registered in the system.\n\n");
        return;
    }

    printf("%-15s %-30s %-15s\n", "Asset ID", "Asset Name", "Value");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < assetCount; i++) {
        printf("%-15s %-30s N$%.2f\n\n", assetIDs[i], assetNames[i], assetValues[i]);
    }
}
