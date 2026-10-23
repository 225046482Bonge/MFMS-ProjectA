/* suppliers.c - Supplier Management module */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "suppliers.h"
#include "validation.h"

#define ID_LEN 20
#define NAME_LEN 100
#define EMAIL_LEN 50
#define PHONE_LEN 20
#define TOWN_LEN 50
#define INPUT_LEN 50

static char s_ids[MAX_SUPPLIERS][ID_LEN];
static char s_names[MAX_SUPPLIERS][NAME_LEN];
static char s_emails[MAX_SUPPLIERS][EMAIL_LEN];
static char s_phones[MAX_SUPPLIERS][PHONE_LEN];
static char s_towns[MAX_SUPPLIERS][TOWN_LEN];
static int s_count = 0;

static void toUpperStr(char *s)
{
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        s[i] = (char)toupper((unsigned char)s[i]);
    }
}

static int containsIgnoreCase(const char *text, const char *pattern)
{
    int i;
    int j;
    int tlen;
    int plen;

    tlen = (int)strlen(text);
    plen = (int)strlen(pattern);
    for (i = 0; i + plen <= tlen; i++) {
        for (j = 0; j < plen; j++) {
            if (tolower((unsigned char)text[i + j]) !=
                tolower((unsigned char)pattern[j])) {
                break;
            }
        }
        if (j == plen) {
            return 1;
        }
    }
    return 0;
}

static int findSupplierById(const char *id)
{
    int i;

    for (i = 0; i < s_count; i++) {
        if (strcmp(s_ids[i], id) == 0) {
            return i;
        }
    }
    return -1;
}

static void printHeader(void)
{
    printf("%-10s %-25s %-28s %-17s %-15s\n",
           "ID", "Name", "Email", "Telephone", "Town");
    printf("---------------------------------------------------------------"
           "-----------------------\n");
}

static void printSupplierRow(int i)
{
    printf("%-10.10s %-25.25s %-28.28s %-17.17s %-15.15s\n",
           s_ids[i], s_names[i], s_emails[i], s_phones[i], s_towns[i]);
}

static void addSupplier(void)
{
    char id[INPUT_LEN];
    char name[INPUT_LEN];
    char email[INPUT_LEN];
    char phone[INPUT_LEN];
    char town[INPUT_LEN];
    int valid;

    if (s_count >= MAX_SUPPLIERS) {
        printf("\nSupplier list is full (%d suppliers).\n", MAX_SUPPLIERS);
        return;
    }

    printf("\n--- Add Supplier ---\n");
    do {
        valid = 1;
        getNonEmptyString("Supplier ID: ", id);
        toUpperStr(id);
        if (strlen(id) >= ID_LEN) {
            printf("Error: ID must be shorter than %d characters.\n", ID_LEN);
            valid = 0;
        } else if (strchr(id, ' ') != NULL) {
            printf("Error: ID cannot contain spaces.\n");
            valid = 0;
        } else if (findSupplierById(id) != -1) {
            printf("Error: supplier ID %s already exists.\n", id);
            valid = 0;
        }
    } while (!valid);

    getNonEmptyString("Supplier name: ", name);
    getEmail("Email: ", email);
    getPhone("Telephone: ", phone);
    getNonEmptyString("Town/Location: ", town);

    strcpy(s_ids[s_count], id);
    strcpy(s_names[s_count], name);
    strcpy(s_emails[s_count], email);
    strcpy(s_phones[s_count], phone);
    strcpy(s_towns[s_count], town);
    s_count++;

    printf("\nSupplier %s added successfully.\n", id);
}

static void displaySuppliers(void)
{
    int i;

    printf("\n--- Registered Suppliers ---\n");
    if (s_count == 0) {
        printf("No suppliers have been registered yet.\n");
        return;
    }
    printHeader();
    for (i = 0; i < s_count; i++) {
        printSupplierRow(i);
    }
    printf("\nTotal suppliers: %d\n", s_count);
}

static void searchSuppliers(void)
{
    char term[INPUT_LEN];
    int choice;
    int i;
    int found;
    int match;

    if (s_count == 0) {
        printf("\nNo suppliers to search. Add a supplier first.\n");
        return;
    }

    printf("\n--- Search Suppliers ---\n");
    printf("1. By Supplier ID\n");
    printf("2. By Name (partial match)\n");
    printf("3. By Town/Location (partial match)\n");
    choice = getInt("Enter your choice: ", 1, 3);
    getNonEmptyString("Enter search text: ", term);
    if (choice == 1) {
        toUpperStr(term);
    }

    found = 0;
    for (i = 0; i < s_count; i++) {
        if (choice == 1) {
            match = (strcmp(s_ids[i], term) == 0);
        } else if (choice == 2) {
            match = containsIgnoreCase(s_names[i], term);
        } else {
            match = containsIgnoreCase(s_towns[i], term);
        }
        if (match) {
            if (found == 0) {
                printf("\n");
                printHeader();
            }
            printSupplierRow(i);
            found++;
        }
    }

    if (found == 0) {
        printf("\nNo matching suppliers found.\n");
    } else {
        printf("\n%d supplier(s) found.\n", found);
    }
}

static void printCompareLine(const char *label, const char *a, const char *b)
{
    printf("%-12s %-25.25s %-25.25s %s\n", label, a, b,
           (strcmp(a, b) == 0) ? "SAME" : "DIFFERENT");
}

static void compareSuppliers(void)
{
    char idA[INPUT_LEN];
    char idB[INPUT_LEN];
    int a;
    int b;

    if (s_count < 2) {
        printf("\nAt least two suppliers are needed to compare.\n");
        return;
    }

    printf("\n--- Compare Two Suppliers ---\n");
    getNonEmptyString("First supplier ID: ", idA);
    getNonEmptyString("Second supplier ID: ", idB);
    toUpperStr(idA);
    toUpperStr(idB);

    a = findSupplierById(idA);
    b = findSupplierById(idB);
    if (a == -1 || b == -1) {
        printf("One or both supplier IDs were not found.\n");
        return;
    }
    if (a == b) {
        printf("Please enter two different supplier IDs.\n");
        return;
    }

    printf("\n%-12s %-25s %-25s %s\n", "Field", s_ids[a], s_ids[b], "Result");
    printf("------------------------------------------------------------"
           "------------\n");
    printCompareLine("Name", s_names[a], s_names[b]);
    printCompareLine("Email", s_emails[a], s_emails[b]);
    printCompareLine("Telephone", s_phones[a], s_phones[b]);
    printCompareLine("Town", s_towns[a], s_towns[b]);
}

int supplierMenu(char names[][100], char ids[][20])
{
    int choice;
    int i;

    do {
        printf("\n========================================\n");
        printf("          SUPPLIER MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Suppliers\n");
        printf("4. Compare Two Suppliers\n");
        printf("5. Back to Main Menu\n");
        choice = getInt("Enter your choice: ", 1, 5);

        switch (choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySuppliers();
                break;
            case 3:
                searchSuppliers();
                break;
            case 4:
                compareSuppliers();
                break;
            default:
                break;
        }
    } while (choice != 5);

    for (i = 0; i < s_count; i++) {
        strcpy(ids[i], s_ids[i]);
        strcpy(names[i], s_names[i]);
    }
    return s_count;
}
