#ifndef ASSETS_H
#define ASSETS_H

void assetCondition(int condition, char text[]);
void assetPrintRow(char ids[][50], char names[][50], char types[][50],char departments[][50], double values[], int conditions[], int index);
int assetFind(char ids[][50], int count, char id[]);
int addAsset(char ids[][50], char names[][50], char types[][50],char departments[][50], double values[], int conditions[], int count);
void displayAssets(char ids[][50], char names[][50], char types[][50],char departments[][50], double values[], int conditions[], int count);
int assetMenu(char names[][100], char ids[][20], double values[]);
void searchAssetById(char ids[][50], char names[][50], char types[][50],char departments[][50], double values[], int conditions[], int count);
void searchAssetByDept(char ids[][50], char names[][50], char types[][50],char departments[][50], double values[], int conditions[], int count);
void displayAssetSummary(double values[], int count);
#endif
