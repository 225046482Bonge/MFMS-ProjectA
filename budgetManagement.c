#include <stdio.h>

const maxDepartment = 50

void enterBudget(int n,
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

void budgetMenu() {
    int n;

    char department[maxDepartment][50];
    double budget[maxDepartment];
    double expenditure[maxDepartment];
    double remaining[maxDepartment];

    printf("How many departments? ");
    scanf("%d", &n);

    if (n <= 0 || n > maxDepartment) {
        printf("Invalid number of departments.\n");
        return;
    }

    enterBudget(n, department, budget, expenditure, remaining);
    displayBudget(n, department, budget, expenditure, remaining);
    checkExceeded(n, department, budget, expenditure);
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
        printf("Allocated Budget: N$%.2lf\n", budget[i]);
        printf("Expenditure: N$%.2lf\n", expenditure[i]);
        printf("Remaining Budget: N$%.2lf\n", remaining[i]);

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
            printf("%s exceeded budget by N$%.2lf\n",
                   department[i],
                   expenditure[i] - budget[i]);
            found = 1;
        }
    }

    if (found == 0) {
        printf("No department exceeded its allocated budget.\n");
    }
}