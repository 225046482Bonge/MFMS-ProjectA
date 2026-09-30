#include <stdio.h>
#include "reports.h"

int main() {
    // 1. Mock Data for Employees
    double salaries[] = {15000.00, 22500.50, 9500.00};
    int empCount = 3;

    // 2. Mock Data for Budgets (HR is over budget, IT is under)
    double budgets[] = {50000.00, 120000.00};
    double expenditures[] = {55000.00, 95000.00};
    char deptNames[][50] = {"HR Department", "IT Department"};
    int deptCount = 2;

    // 3. Mock Data for Suppliers
    char supplierNames[][100] = {"NamTech Solutions", "Windhoek Logistics"};
    char supplierIDs[][20] = {"SUP-001", "SUP-002"};
    int supplierCount = 2;

    // 4. Mock Data for Assets
    char assetNames[][100] = {"Server Rack", "Office Laptops"};
    char assetIDs[][20] = {"AST-101", "AST-102"};
    double assetValues[] = {45000.00, 85000.00};
    int assetCount = 2;

    printf("\nStarting Reports Module Test\n");
    
    //launching the reports menu with mock data
    displayReportsMenu(
        salaries, empCount,
        budgets, expenditures, deptNames, deptCount,
        supplierNames, supplierIDs, supplierCount,
        assetNames, assetIDs, assetValues, assetCount
    );

    printf("\nTest completed successfully.\n");
    return 0;
}
