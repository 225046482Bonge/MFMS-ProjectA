/* validation.h - Input and validation functions (Student 6)
 * Everyone in the group uses these instead of calling scanf() directly.
 * Include this header once in each .c file that needs it. */

/* Reading text */
void readText(char text[], int size);

/* Checking text (return 1 if valid, 0 if not) */
int isWholeNumber(char text[]);
int isDecimalNumber(char text[]);
int isBlank(char text[]);
int isValidEmail(char text[]);
int isValidPhone(char text[]);

/* Converting text to a number */
int textToInt(char text[]);
double textToDouble(char text[]);

/* Validated input: each one repeats until the user enters a valid value */
int getInt(char prompt[], int min, int max);
double getDouble(char prompt[], double min, double max);
void getNonEmptyString(char prompt[], char text[], int size);
void getEmail(char prompt[], char text[], int size);
void getPhone(char prompt[], char text[], int size);

/* Waits for the user to press Enter */
void pauseScreen();
