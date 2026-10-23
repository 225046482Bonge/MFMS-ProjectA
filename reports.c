#include <stdio.h>
#include "reports.h"
#include "validation.h"


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


choice = getInt("Enter your choice (1-5): ", 1, 5);

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


void generateEmployeeReport(double salaries[], int empCount) {
double totalSalary = 0;
double highestSalary;
double lowestSalary;
double averageSalary;
int i;

printf("===============================================\n");
printf("-------------- Employee Report ----------------\n");
printf("===============================================\n");
if (empCount == 0) {
printf("No employees registered in the system.\n");
return;
}

highestSalary = salaries[0];
lowestSalary = salaries[0];

for (i = 0; i < empCount; i++) {
totalSalary += salaries[i];
if (salaries[i] > highestSalary) highestSalary = salaries[i];
if (salaries[i] < lowestSalary) lowestSalary = salaries[i];
}

averageSalary = totalSalary / empCount;

printf("Total Employees: %d\n", empCount);
printf("Average Salary: %s\n", formatMoney(averageSalary));
printf("Highest Salary: %s\n", formatMoney(highestSalary));
printf("Lowest Salary: %s\n\n", formatMoney(lowestSalary));
}


void generateBudgetReport(double budgets[], double expenditures[], char deptNames[][50], int deptCount) {
double totalAllocated = 0;
double totalExpenditure = 0;
double remainingBudget;
int exceededCount = 0;
int i;

printf("===============================================\n");
printf("--------------- Budget Report -----------------\n");
printf("===============================================\n");
if (deptCount == 0) {
printf("No departmental budget data available.\n");
return;
}

for (i = 0; i < deptCount; i++) {
totalAllocated += budgets[i];
totalExpenditure += expenditures[i];
}

remainingBudget = totalAllocated - totalExpenditure;

printf("Total Allocated Budget: %s\n", formatMoney(totalAllocated));
printf("Total Expenditure: %s\n", formatMoney(totalExpenditure));
printf("Remaining Budget: %s\n\n", formatMoney(remainingBudget));

printf("\nDepartments Exceeding Budget:\n");
for (i = 0; i < deptCount; i++) {
if (expenditures[i] > budgets[i]) {
printf(" %s (Exceeded by: %s)\n\n", deptNames[i], formatMoney(expenditures[i] - budgets[i]));
exceededCount++;
}
}
if (exceededCount == 0) {
printf("None. All departments are within budget.\n\n");
}
}

void generateSupplierReport(char supplierNames[][100], char supplierIDs[][20], int supplierCount) {
int i;

printf("===============================================\n");
printf("-------------- Supplier Report ----------------\n");
printf("===============================================\n\n");
if (supplierCount == 0) {
printf("No suppliers registered in the system.\n\n");
return;
}

printf("%-15s %-30s\n", "Supplier ID", "Supplier Name");
printf("---------------------------------------------\n");
for (i = 0; i < supplierCount; i++) {
printf("%-15s %-30s\n\n", supplierIDs[i], supplierNames[i]);
}
}

void generateAssetReport(char assetNames[][100], char assetIDs[][20], double assetValues[], int assetCount) {
int i;

printf("===============================================\n");
printf("----------------- Asset Report ----------------\n");
printf("===============================================\n\n");
if (assetCount == 0) {
printf("No assets registered in the system.\n\n");
return;
}

printf("%-15s %-30s %-15s\n", "Asset ID", "Asset Name", "Value");
printf("-----------------------------------------------------------\n");
for (i = 0; i < assetCount; i++) {
printf("%-15s %-30s %s\n\n", assetIDs[i], assetNames[i], formatMoney(assetValues[i]));
}
}
