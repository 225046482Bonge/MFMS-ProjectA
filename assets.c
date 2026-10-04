#include <stdio.h>
#include <string.h>
#include "assets.h"


void assetCondition(int condition, char text[]);{
    switch (condition){
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
            break:
    }

}



void assetPrintRow(char ids[][50], char names[][50], char assets[][50], char types[][50], char departments[][50], double values[], int conditions[],int * index){
    char condition[20];
    assetCondition(conditions[index], condition);
}
 

int assetFind(char ids[][50], int count, char id[]){
    int i; 

    for (i=0; i<count; i++){
        if (strcmp(ids[i], id) ==0){
            return i; 
        }  
    }
    return -1;
}



int addAsset(char ids[][50], char names[][50], char types[][50],char departments[][50], double values[], int conditions[], int count){
    const int MAX_ASSETS = 50; 
    char id[50];

    if (count>= MAX_ASSETS){
        printf("Register is full. \n");
        return count;
    }

    getNonEmptyString("Enter Asset ID", id, 50);

    if (assetFind(ids, count, id) != -1){
        printf("Asset ID already exists. \n");
        return count;
    } 

    strcpy(ids[count], id);
    getNonEmptyString("Enter Asset Name:", names[count], 50);
    getNonEmptyString("Enter Asset Type:", types[count], 50);
    getNonEmptyString("Enter Asset Department:", departments[count], 50);

    values[count] = getDouble("Enter Value:", 0.01, 1000000.00);
    conditions[count] = getInt("Enter Condition (1-4):", 1,4);

    printf("Enter added. \n");
    return count + 1;
}

void displayAssets(char ids[][50], char names[][50], char types[][50],
                   char departments[][50], double values[], int conditions[], int count) {
    int i;

    
    if (count == 0) {
        printf("No assets recorded.\n");
        return;
    }

    
    printf("\n%-10s %-20s %-15s %-15s %-12s %-15s\n", 
           "ID", "Name", "Type", "Department", "Value", "Condition");
    printf("-----------------------------------------------------------------------------------\n");

  
    for (i = 0; i < count; i++) {
        assetPrintRow(ids, names, types, departments, values, conditions, i);
    }

    
    printf("\nTotal assets: %d\n", count);
}

void assetMenu() {
    
    char ids[50][50];
    char names[50][50];
    char types[50][50];
    char departments[50][50];
    double values[50];
    int conditions[50];
    int count = 0;

    int choice;

    do {
       
        printf("\n--- Asset Management Menu ---\n");
        printf("1. Add asset\n");
        printf("2. Display all assets\n");
        printf("3. Search by ID\n");
        printf("4. Search by department\n");
        printf("5. Value summary\n");
        printf("6. Back to main menu\n");

    
        choice = getInt("Enter your choice: ", 1, 6);

        
        switch (choice) {
            case 1:
                count = addAsset(ids, names, types, departments, values, conditions, count);
                break;
            case 2:
                displayAssets(ids, names, types, departments, values, conditions, count);
                break;
            case 3:
            case 4:
            case 5:
                printf("Not ready yet.\n");
                break;
            case 6:
                printf("Returning to the main menu...\n");
                break;
        }
    } while (choice != 6);
} 

void searchAssetById(char ids[][50], char names[][50], char types[][50],
                     char departments[][50], double values[], int conditions[], int count) {
    char id[50];
    int position;

    getNonEmptyString("Enter Asset ID to search: ", id, 50);
    position = assetFind(ids, count, id);

    if (position != -1) {
        printf("\n%-10s %-20s %-15s %-15s %-12s %-15s\n", 
               "ID", "Name", "Type", "Department", "Value", "Condition");
        printf("-----------------------------------------------------------------------------------\n");
        assetPrintRow(ids, names, types, departments, values, conditions, position);
    } else {
        printf("Asset with ID '%s' not found.\n", id);
    }
}

void searchAssetByDept(char ids[][50], char names[][50], char types[][50],
                       char departments[][50], double values[], int conditions[], int count) {
    char department[50];
    int found = 0;
    int i;

    getNonEmptyString("Enter Department to search: ", department, 50);

    for (i = 0; i < count; i++) {
        if (strcmp(departments[i], department) == 0) {
            if (found == 0) {
                printf("\n%-10s %-20s %-15s %-15s %-12s %-15s\n", 
                       "ID", "Name", "Type", "Department", "Value", "Condition");
                printf("-----------------------------------------------------------------------------------\n");
            }
            assetPrintRow(ids, names, types, departments, values, conditions, i);
            found++;
        }
    }

    if (found == 0) {
        printf("No assets found in department '%s'.\n", department);
    } else {
        printf("\nTotal assets found: %d\n", found);
    }
}

void displayAssetSummary(double values[], int count) {
    double total = 0;
    double highest;
    double lowest;
    int i;

    if (count == 0) {
        printf("No assets available to display summary.\n");
        return;
    }

    
    highest = values[0];
    lowest = values[0];

   
    for (i = 0; i < count; i++) {
        total += values[i];

        if (values[i] > highest) {
            highest = values[i];
        }

        if (values[i] < lowest) {
            lowest = values[i];
        }
    }

    
    printf("\n--- Asset Value Summary ---\n");
    printf("Total Assets:     %d\n", count);
    printf("Total Value:      $%.2f\n", total);
    printf("Average Value:    $%.2f\n", total / count);
    printf("Highest Value:    $%.2f\n", highest);
    printf("Lowest Value:     $%.2f\n", lowest);
}

int loadAssets(char ids[][50], char names[][50], char types[][50],
               char departments[][50], double values[], int conditions[]) {
    const int MAX_ASSETS = 50;
    int count = 0;
    FILE *fp;

    fp = fopen("assets.txt", "r");
    if (fp == NULL) {
       
        return 0;
    }

    while (count < MAX_ASSETS && 
           fscanf(fp, "%49s %49s %49s %49s %lf %d", 
                  ids[count], names[count], types[count], 
                  departments[count], &values[count], &conditions[count]) == 6) {
        count++;
    }

    fclose(fp);
    return count;
}

void saveAssets(char ids[][50], char names[][50], char types[][50],
                char departments[][50], double values[], int conditions[], int count) {
    FILE *fp;
    int i;

    fp = fopen("assets.txt", "w");
    if (fp == NULL) {
        perror("Error opening file for saving");
        return;
    }

    for (i = 0; i < count; i++) {
        fprintf(fp, "%s %s %s %s %.2f %d\n",
                ids[i], names[i], types[i], 
                departments[i], values[i], conditions[i]);
    }

    fclose(fp);
    printf("Assets saved successfully to assets.txt\n");
}

void swapAssets(char ids[][50], char names[][50], char types[][50],
                char departments[][50], double values[], int conditions[], int j) {
    char tempStr[50];
    double tempDouble;
    int tempInt;

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

    tempDouble = values[j];
    values[j] = values[j + 1];
    values[j + 1] = tempDouble;

    tempInt = conditions[j];
    conditions[j] = conditions[j + 1];
    conditions[j + 1] = tempInt;
}

void sortAssetsByValue(char ids[][50], char names[][50], char types[][50],
                       char departments[][50], double values[], int conditions[], int count) {
    int i, j;

    if (count <= 1) {
        printf("Not enough assets to sort.\n");
        return;
    }

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (values[j] < values[j + 1]) {
                swapAssets(ids, names, types, departments, values, conditions, j);
            }
        }
    }

    printf("Assets successfully sorted by value!\n");
}

case 6:
    sortAssetsByValue(ids, names, types, departments, values, conditions, count);
    break;
case 7:
    saveAssets(ids, names, types, departments, values, conditions, count);
    printf("Returning to main menu...\n");
    break;