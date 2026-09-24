/* validation.h - Functions for input and validation (Student 6)
* Each member of the group relies on these rather than calling scanf() directly.
* Add this header a single time to every .c file that requires it. /

/ Reading text /
void readText(char text[], int size);

/ Verifying text (return 1 when valid, 0 when not) /
int isWholeNumber(char text[]);
int isDecimalNumber(char text[]);
int isBlank(char text[]);
int isValidEmail(char text[]);
int isValidPhone(char text[]);

/ Turning text into a number /
int textToInt(char text[]);
double textToDouble(char text[]);

/ Validated input: every function loops until the user supplies a valid value /
int getInt(char prompt[], int min, int max);
double getDouble(char prompt[], double min, double max);
void getNonEmptyString(char prompt[], char text[], int size);
void getEmail(char prompt[], char text[], int size);
void getPhone(char prompt[], char text[], int size);

/ Waits for the user to press Enter */
void pauseScreen();