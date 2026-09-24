/* validation.c - Functions for input and validation (Student 6)
* Each value is initially read as text using fgets(), then verified
* one character at a time, so incorrect input (for instance, letters where a number
* is required) can never cause the program to fail. */
#include &lt;stdio.h&gt;
#include &lt;string.h&gt;
#include "validation.h"

/* Reads a single line into text[] and strips the newline that fgets() leaves behind */
void readText(char text[], int size)
{
fgets(text, size, stdin);
text[strcspn(text, "\n")] = '\0';
}

/* Returns 1 if text is an integer such as 25 or -3 (up to 9 digits) */
int isWholeNumber(char text[])
{
int length = strlen(text);
int start = 0;
int i;

if (text[0] == '-')
{
start = 1;
}

if (length - start &lt; 1 || length - start &gt; 9)
{
return 0;
}

for (i = start; i &lt; length; i++)
{
if (text[i] &lt; '0' || text[i] &gt; '9')
{
return 0;
}
}
return 1;
}

/* 1 if text is a number such as 15000, 15000.50 or -2.5 */
int isDecimalNumber(char text[])
{
int length = strlen(text);
int start = 0;
int digits = 0;
int dots = 0;
int i;

if (text[0] == '-')
{
start = 1;
}

if (length - start &gt; 15)
{
return 0;
}

for (i = start; i &lt; length; i++)
{
if (text[i] == '.')
{
dots++;
}
else if (text[i] &gt;= '0' &amp;&amp; text[i] &lt;= '9')
{
digits++;
}
else
{
return 0;
}
}

if (digits == 0 || dots &gt; 1)
{
return 0;
}
return 1;
}

/* returns 1 when the text is empty or has only spaces */
int isBlank(char text[])
{
int length = strlen(text);
int i;

for (i = 0; i &lt; length; i++)
{
if (text[i] != ' ')
{
return 0;
}
}
return 1;
}

/* 1 if text looks like name@example.com */
int isValidEmail(char text[])
{
int length = strlen(text);
int atCount = 0;
int atPosition = -1;
int lastDot = -1;
int i;

for (i = 0; i &lt; length; i++)
{
if (text[i] == ' ')
{
return 0;
}
if (text[i] == '@')
{
atCount++;
atPosition = i;
}
if (text[i] == '.')
{
lastDot = i;
}
}

if (atCount != 1 || atPosition == 0)
{
return 0;
}
if (lastDot &lt; atPosition + 2 || lastDot == length - 1)
{
return 0;
}
return 1;
}

/* Returns 1 when the text consists of 7 to 15 digits, with an optional leading + */
int isValidPhone(char text[])
{
int length = strlen(text);
int start = 0;
int i;

if (text[0] == '+')
{
start = 1;
}

if (length - start &lt; 7 || length - start &gt; 15)
{
return 0;
}

for (i = start; i &lt; length; i++)
{
if (text[i] &lt; '0' || text[i] &gt; '9')
{
return 0;
}
}
return 1;
}

/* Turns text already validated by isWholeNumber() into an int */
int textToInt(char text[])
{
int length = strlen(text);
int value = 0;
int sign = 1;
int start = 0;
int i;

if (text[0] == '-')
{
sign = -1;
start = 1;
}

/* Subtracting '0' from any digit character yields its numeric value: '7' - '0' = 7.
* Multiplying the accumulated value by 10 shifts it one place to the left. */
for (i = start; i &lt; length; i++)
{
value = value * 10 + (text[i] - '0');
}
return sign * value;
}

/* Turns text that isDecimalNumber() has already validated into a double */
double textToDouble(char text[])
{
int length = strlen(text);
double value = 0.0;
double place = 0.1;
int sign = 1;
int afterDot = 0;
int start = 0;
int i;

if (text[0] == '-')
{
sign = -1;
start = 1;
}

for (i = start; i &lt; length; i++)
{
if (text[i] == '.')
{
afterDot = 1;
}
else if (afterDot == 0)
{
value = value * 10 + (text[i] - '0');
}
else
{
value = value + (text[i] - '0') * place;
place = place / 10;
}
}
return sign * value;
}

/* Keeps asking until the user provides a whole number within the range from min to max */
int getInt(char prompt[], int min, int max)
{
char text[100];
int value = 0;
int valid = 0;

do
{
printf("%s", prompt);
readText(text, sizeof(text));

if (isWholeNumber(text) == 0)
{
printf("Error: please enter a whole number.\n");
}
else
{
value = textToInt(text);
if (value &lt; min || value &gt; max)
{
printf("Error: enter a number between %d and %d.\n", min, max);
}
else
{
valid = 1;
}
}
} while (valid == 0);

return value;
}

/* Keeps asking until the user inputs a number between min and max */
double getDouble(char prompt[], double min, double max)
{
char text[100];
double value = 0.0;
int valid = 0;

do
{
printf("%s", prompt);
readText(text, sizeof(text));

if (isDecimalNumber(text) == 0)
{
printf("Error: please enter a valid number.\n");
}
else
{
value = textToDouble(text);
if (value &lt; min || value &gt; max)
{
printf("Error: value must be between %.2f and %.2f.\n", min, max);
}
else
{
valid = 1;
}
}
} while (valid == 0);

return value;
}

/* Repeatedly prompts the user until non-empty text is entered (spaces are allowed within) */
void getNonEmptyString(char prompt[], char text[], int size)
{
do
{
printf("%s", prompt);
readText(text, size);

if (isBlank(text) == 1)
{
printf("Error: this field cannot be empty.\n");
}
} while (isBlank(text) == 1);
}

/* Keeps asking until the user provides a valid email */
void getEmail(char prompt[], char text[], int size)
{
do
{
printf("%s", prompt);
readText(text, size);

if (isValidEmail(text) == 0)
{
printf("Error: enter a valid email (e.g. name@example.com).\n");
}
} while (isValidEmail(text) == 0);
}

/* Repeatedly asks until a valid phone number is entered by the user */
void getPhone(char prompt[], char text[], int size)
{
do
{
printf("%s", prompt);
readText(text, size);

if (isValidPhone(text) == 0)
{
printf("Error: enter 7 to 15 digits (a leading + is allowed).\n");
}
} while (isValidPhone(text) == 0);
}

/* Awaits the user pressing Enter */
void pauseScreen()
{
char text[10];

printf("\nPress Enter to continue...");
readText(text, sizeof(text));
}