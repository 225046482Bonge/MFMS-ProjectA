#ifndef REPORTS_H
#define REPORTS_H

/*maximum number of departments*/
#define MAX_DEPARTMENTS 50

/*function declarations*/
void displayReportsMenu(
    double salaries[], int empCount,
    double budgets[], double expenditures[], char deptNames[][50], int deptCount,
    char supplierNames[][100], char supplierIDs[][20], int supplierCount,
    char assetNames[][100], char assetIDs[][20], double assetValues[], int assetCount
);

void generateEmployeeReport(double salaries[], int empCount);
void generateBudgetReport(double budgets[], double expenditures[], char deptNames[][50], int deptCount);
void generateSupplierReport(char supplierNames[][100], char supplierIDs[][20], int supplierCount);
void generateAssetReport(char assetNames[][100], char assetIDs[][20], double assetValues[], int assetCount);

#endif /* REPORTS_H */