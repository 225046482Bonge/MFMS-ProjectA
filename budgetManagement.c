#include <stdio.h>


int main() {
    int i, n;
    char maxDepartments = 50;
    char department[maxDepartments][50];
    double budget[maxDepartments];
    double expenditure[maxDepartments];
    double remaining[maxDepartments];

    printf("How many departments? ");
    scanf("%d", &n);

    if (n <= 0 && n > maxDepartments) {
        printf("Invalid number of departments.\n");
        return 1;
    }

    // Input
    for (i = 0; i < n; i++) {
        printf("Department %d Name: ", i + 1);
        scanf("%s", department[i]);

        printf("Allocated Budget (N$): ");
        scanf("%lf", &budget[i]);
        while (budget[i] < 0) {
            printf("Budget cannot be negative. Enter again: \n");
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

    // Display Information
   
    for (i = 0; i < n; i++) {
        printf("Department: %s\n", department[i]);
        printf("Allocated Budget: N$%.2lf\n", budget[i]);
        printf("Expenditure: N$%.2lf\n", expenditure[i]);
        printf("Remaining Budget: N$%.2lf\n", remaining[i]);

        if (expenditure[i] <= budget[i])
            printf("Status: Within Budget\n");
        else
            printf("Status: Exceeded Budget\n");
    }

    // Departments that exceeded budget
    
    int found = 0;

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

    return 0;
}