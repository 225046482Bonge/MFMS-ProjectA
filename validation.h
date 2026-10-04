#ifndef VALIDATION_H
#define VALIDATION_H

int getInt(char prompt[], int min, int max);
double getDouble(char prompt[], double min, double max);
void getNonEmptyString(char prompt[], char text[]);
void getEmail(char prompt[], char text[]);
void getPhone(char prompt[], char text[]);
int isBlank(char text[]);
int isValidEmail(char text[]);
int isValidPhone(char text[]);
int equalsIgnoreCase(char a[], char b[]);   
int nameContains(char text[], char part[]);   
char *formatMoney(double amount);

#endif
