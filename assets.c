#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "validation.h"

#define MAX_ASSETS 50

void assetCondition(int condition, char text[]) {
    switch (condition) {
        case 1:
            strcpy(text, "Good");
            break;
        case 2:
            strcpy(text, "Fair");
            break;
        case 3:
            strcpy(text, "Poor");
            break;
        case 4:
            strcpy(text, "Broken. Needs Repair");
            break;
        default:
            strcpy(text, "Unknown");
            break;
    }
}

void assetPrintRow(char ids[][50], char names[][50], char types[][50],
                   char departments[][50], double values[], int conditions[], int index) {
    char condText[30];
    assetCondition(conditions[index], condText);
    
    printf("%-10s %-20s %-15s %-15s %-12.2f %-20s\n",
           ids[index], names[index], types[index],
           departments[index], values[index], condText);
}

int assetFind(char ids[][50], int count, char id[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(ids[i], id) == 0) {
            return i;
        }
    }
    return -1;
}

int addAsset(char ids[][50], char names[][50], char types[][50],
             char departments[][50], double values[], int conditions[], int count) {
    if (count >= MAX_ASSETS) {
        printf("\nError: Asset registry is full (Max %d assets).\n", MAX_ASSETS);
        return count;
    }

    char id[50];
    printf("\nEnter Asset ID: ");
    getNonEmptyString(id, sizeof(id));

    if (assetFind(ids, count, id) != -1) {
        printf("Error: Asset ID '%s' already exists.\n", id);
        return count;
    }

    strcpy(ids[count], id);

    printf("Enter Asset Name: ");
    getNonEmptyString(names[count], sizeof(names[count]));

    printf("Enter Asset Type: ");
    getNonEmptyString(types[count], sizeof(types[count]));

    printf("Enter Department: ");
    getNonEmptyString(departments[count], sizeof(departments[count]));

    values[count] = getDouble("Enter Asset Value ($): ", 0.0, 10000000.0);
    conditions[count] = getInt("Enter Condition (1-Good, 2-Fair, 3-Poor, 4-Broken): ", 1, 4);

    printf("\nAsset added successfully!\n");
    return count + 1;
}

void displayAssets(char ids[][50], char names[][50], char types[][50],
                   char departments[][50], double values[], int conditions[], int count) {
    if (count == 0) {
        printf("\nNo asset records available.\n");
        return;
    }

    printf("\n========================================================================================\n");
    printf("%-10s %-20s %-15s %-15s %-12s %-20s\n", "ID", "Name", "Type", "Department", "Value ($)", "Condition");
    printf("========================================================================================\n");

    for (int i = 0; i < count; i++) {
        assetPrintRow(ids, names, types, departments, values, conditions, i);
    }
    printf("========================================================================================\n");
}

void searchAssetById(char ids[][50], char names[][50], char types[][50],
                     char departments[][50], double values[], int conditions[], int count) {
    if (count == 0) {
        printf("\nNo assets available to search.\n");
        return;
    }

    char searchId[50];
    printf("\nEnter Asset ID to search: ");
    getNonEmptyString(searchId, sizeof(searchId));

    int index = assetFind(ids, count, searchId);
    if (index == -1) {
        printf("Asset with ID '%s' not found.\n", searchId);
    } else {
        printf("\nAsset Found:\n");
        printf("----------------------------------------------------------------------------------------\n");
        printf("%-10s %-20s %-15s %-15s %-12s %-20s\n", "ID", "Name", "Type", "Department", "Value ($)", "Condition");
        printf("----------------------------------------------------------------------------------------\n");
        assetPrintRow(ids, names, types, departments, values, conditions, index);
        printf("----------------------------------------------------------------------------------------\n");
    }
}

void searchAssetByDept(char ids[][50], char names[][50], char types[][50],
                       char departments[][50], double values[], int conditions[], int count) {
    if (count == 0) {
        printf("\nNo assets available to search.\n");
        return;
    }

    char dept[50];
    printf("\nEnter Department Name: ");
    getNonEmptyString(dept, sizeof(dept));

    int found = 0;
    printf("\n========================================================================================\n");
    printf("%-10s %-20s %-15s %-15s %-12s %-20s\n", "ID", "Name", "Type", "Department", "Value ($)", "Condition");
    printf("========================================================================================\n");

    for (int i = 0; i < count; i++) {
        if (strcasecmp(departments[i], dept) == 0) {
            assetPrintRow(ids, names, types, departments, values, conditions, i);
            found++;
        }
    }
    printf("========================================================================================\n");

    if (found == 0) {
        printf("No assets found for department '%s'.\n", dept);
    } else {
        printf("Total assets found in %s: %d\n", dept, found);
    }
}

void displayAssetSummary(double values[], int count) {
    if (count == 0) {
        printf("\nNo asset records available for summary.\n");
        return;
    }

    double totalValue = 0.0;
    double maxVal = values[0];
    double minVal = values[0];

    for (int i = 0; i < count; i++) {
        totalValue += values[i];
        if (values[i] > maxVal) maxVal = values[i];
        if (values[i] < minVal) minVal = values[i];
    }

    printf("\n========================================\n");
    printf("         ASSET FINANCIAL SUMMARY        \n");
    printf("========================================\n");
    printf("Total Records:       %d\n", count);
    printf("Total Asset Value:   $%.2f\n", totalValue);
    printf("Average Asset Value: $%.2f\n", totalValue / count);
    printf("Highest Asset Value: $%.2f\n", maxVal);
    printf("Lowest Asset Value:  $%.2f\n", minVal);
    printf("========================================\n");
}

void sortAssetsByValue(char ids[][50], char names[][50], char types[][50],
                       char departments[][50], double values[], int conditions[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (values[j] < values[j + 1]) {
                
                double tempVal = values[j];
                values[j] = values[j + 1];
                values[j + 1] = tempVal;

                int tempCond = conditions[j];
                conditions[j] = conditions[j + 1];
                conditions[j + 1] = tempCond;

                char tempStr[50];
                strcpy(tempStr, ids[j]);
                strcpy(ids[j], ids[j + 1]);
                strcpy(ids[j + 1], tempStr);

                strcpy(tempStr, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tempStr);

                strcpy(tempStr, types[j]);
                strcpy(types[j], types[j + 1]);
                strcpy(types[j + 1], tempStr);

                strcpy(tempStr, departments[j]);
                strcpy(departments[j], departments[j + 1]);
                strcpy(departments[j + 1], tempStr);
            }
        }
    }
    printf("\nAssets sorted by value (highest to lowest) successfully.\n");
}

int loadAssets(char ids[][50], char names[][50], char types[][50],
               char departments[][50], double values[], int conditions[]) {
    FILE *file = fopen("assets.txt", "r");
    if (!file) return 0; 

    int count = 0;
    while (count < MAX_ASSETS &&
           fscanf(file, "%49[^,],%49[^,],%49[^,],%49[^,],%lf,%d\n",
                  ids[count], names[count], types[count],
                  departments[count], &values[count], &conditions[count]) == 6) {
        count++;
    }

    fclose(file);
    return count;
}

void saveAssets(char ids[][50], char names[][50], char types[][50],
                char departments[][50], double values[], int conditions[], int count) {
    FILE *file = fopen("assets.txt", "w");
    if (!file) {
        printf("Error: Unable to save assets to assets.txt.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%s,%s,%.2f,%d\n",
                ids[i], names[i], types[i], departments[i], values[i], conditions[i]);
    }

    fclose(file);
}

void assetMenu(void) {
    char ids[MAX_ASSETS][50];
    char names[MAX_ASSETS][50];
    char types[MAX_ASSETS][50];
    char departments[MAX_ASSETS][50];
    double values[MAX_ASSETS];
    int conditions[MAX_ASSETS];

    int count = loadAssets(ids, names, types, departments, values, conditions);
    int choice;

    do {
        printf("\n========================================\n");
        printf("        ASSET MANAGEMENT MODULE         \n");
        printf("========================================\n");
        printf("1. Add New Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset by ID\n");
        printf("4. Search Assets by Department\n");
        printf("5. View Financial Summary\n");
        printf("6. Sort Assets by Value\n");
        printf("7. Save and Back to Main Menu\n");
        printf("========================================\n");

        choice = getInt("Select an option (1-7): ", 1, 7);

        switch (choice) {
            case 1:
                count = addAsset(ids, names, types, departments, values, conditions, count);
                break;
            case 2:
                displayAssets(ids, names, types, departments, values, conditions, count);
                break;
            case 3:
                searchAssetById(ids, names, types, departments, values, conditions, count);
                break;
            case 4:
                searchAssetByDept(ids, names, types, departments, values, conditions, count);
                break;
            case 5:
                displayAssetSummary(values, count);
                break;
            case 6:
                sortAssetsByValue(ids, names, types, departments, values, conditions, count);
                break;
            case 7:
                saveAssets(ids, names, types, departments, values, conditions, count);
                printf("Saving asset records... Returning to main menu.\n");
                break;
        }
    } while (choice != 7);
}
