#include <stdio.h>
#include "budgetManagement.h"

int budgetMenu(double budget[],
                   double expenditure[],
                   char department[][50]){
    int n;

    double remaining[maxDepartment];

    printf("How many departments? ");
    scanf("%d", &n);

    if (n <= 0 || n > maxDepartment) {
        printf("Invalid number of departments.\n");
        return 0;
    }

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

    for (i = 0; i < n; i++) {
        printf("\nDepartment %d Name: ", i + 1);
        scanf("%49s", department[i]);

        printf("Allocated Budget (N$): ");
        scanf("%lf", &budget[i]);

        while (budget[i] < 0) {
            printf("Budget cannot be negative. Enter again: ");
            scanf("%lf", &budget[i]);
        }

        printf("Expenditure (N$): ");
        scanf("%lf", &expenditure[i]);

        while (expenditure[i] < 0) {
            printf("Expenditure cannot be negative. Enter again: ");
            scanf("%lf", &expenditure[i]);
        }

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
        printf("Allocated Budget: N$%.2f\n", budget[i]);
        printf("Expenditure: N$%.2f\n", expenditure[i]);
        printf("Remaining Budget: N$%.2f\n", remaining[i]);

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
            printf("%s exceeded budget by N$%.2f\n",
                   department[i],
                   expenditure[i] - budget[i]);
            found = 1;
        }
    }

    if (found == 0) {
        printf("No department exceeded its allocated budget.\n");
    }
}
