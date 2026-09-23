/* test_validation.c - Small program to test the validation functions.
 * Build with: gcc test_validation.c validation.c -o test_validation */
#include <stdio.h>
#include "validation.h"

int main()
{
    char name[50];
    char email[100];
    char phone[30];
    int age;
    double salary;

    age = getInt("Enter age (1-100): ", 1, 100);
    salary = getDouble("Enter salary (0 or more): ", 0, 1000000);
    getNonEmptyString("Enter name: ", name, sizeof(name));
    getEmail("Enter email: ", email, sizeof(email));
    getPhone("Enter phone: ", phone, sizeof(phone));

    printf("\nAge: %d\nSalary: %.2f\nName: %s\nEmail: %s\nPhone: %s\n",
           age, salary, name, email, phone);
    return 0;
}
