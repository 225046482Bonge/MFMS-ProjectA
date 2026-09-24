/* main.c - Main menu and program start (Student 6) */
#include
#include "mfms.h"
#include "validation.h"

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
reportsMenu();
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