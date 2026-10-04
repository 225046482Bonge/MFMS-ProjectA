#include <stdio.h>
#include "budgetManagement.h"
#include "validation.h"

int budgetMenu(double budget[],
               double expenditure[],
               char department[][50]) {
    int n;

    double remaining[maxDepartment];

    n = getInt("How many departments? ", 1, maxDepartment);

    enterBudget(n, department, budget, expenditure, remaining);
    displayBudget(n, department, budget, expenditure, remaining);
    checkExceeded(n, department, budget, expenditure);
    return n;
}


void enterBudget(int n,
                 char department[][50],
                 double budget[],
                 double expenditure[],
                 double remaining[]) {
    int i;
    char prompt[60];

    for (i = 0; i < n; i++) {
        sprintf(prompt, "\nDepartment %d Name: ", i + 1);
        getNonEmptyString(prompt, department[i]);
        budget[i] = getDouble("Allocated Budget (N$): ", 0.0, 1000000000.0);
        expenditure[i] = getDouble("Expenditure (N$): ", 0.0, 1000000000.0);

        remaining[i] = budget[i] - expenditure[i];
    }
}

void displayBudget(int n,
                   char department[][50],
                   double budget[],
                   double expenditure[],
                   double remaining[]) {
    int i;

    printf("\n===== BUDGET REPORT =====\n");

    for (i = 0; i < n; i++) {
        printf("\nDepartment: %s\n", department[i]);
        printf("Allocated Budget: %s\n", formatMoney(budget[i]));
        printf("Expenditure: %s\n", formatMoney(expenditure[i]));
        printf("Remaining Budget: %s\n", formatMoney(remaining[i]));

        if (expenditure[i] <= budget[i])
            printf("Status: WITHIN BUDGET\n");
        else
            printf("Status: EXCEEDED BUDGET\n");
    }
}

void checkExceeded(int n,
                   char department[][50],
                   double budget[],
                   double expenditure[]) {
    int i;
    int found = 0;

    printf("\n===== EXCEEDED BUDGETS =====\n");

    for (i = 0; i < n; i++) {
        if (expenditure[i] > budget[i]) {
            printf("%s exceeded budget by %s\n",
                   department[i],
                   formatMoney(expenditure[i] - budget[i]));
            found = 1;
        }
    }

    if (found == 0) {
        printf("No department exceeded its allocated budget.\n");
    }
}
