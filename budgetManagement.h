#ifndef BUDGET_MANAGEMENT_H
#define BUDGET_MANAGEMENT_H

#define maxDepartment 50

void enterBudget(int start,
                 int n,
                 char department[][50],
                 double budget[],
                 double expenditure[],
                 double remaining[]);

void displayBudget(int n,
                   char department[][50],
                   double budget[],
                   double expenditure[],
                   double remaining[]);

void checkExceeded(int n,
                   char department[][50],
                   double budget[],
                   double expenditure[]);

int budgetMenu(double budget[],
               double expenditure[],
               char department[][50],
               int deptCount);

#endif