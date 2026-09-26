/* validation.h - Functions for input and validation */

/* Validated input: every function loops until the user provides a valid value */
int getInt(char prompt[], int min, int max);
double getDouble(char prompt[], double min, double max);
void getNonEmptyString(char prompt[], char text[]);
void getEmail(char prompt[], char text[]);
void getPhone(char prompt[], char text[]);

/* Checking text (returns 1 when valid, 0 when not) */
int isBlank(char text[]);
int isValidEmail(char text[]);
int isValidPhone(char text[]);