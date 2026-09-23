/* validation.c - Input and validation functions (Student 6)
 * Every value is first read as text with fgets(), then checked
 * character by character, so wrong input (e.g. letters where a number
 * is expected) can never break the program. */
#include <stdio.h>
#include <string.h>
#include "validation.h"

/* Reads one line into text[] and removes the newline left by fgets() */
void readText(char text[], int size)
{
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = '\0';
}

/* 1 if text is a whole number such as 25 or -3 (up to 9 digits) */
int isWholeNumber(char text[])
{
    int length = strlen(text);
    int start = 0;
    int i;

    if (text[0] == '-')
    {
        start = 1;
    }

    if (length - start < 1 || length - start > 9)
    {
        return 0;
    }

    for (i = start; i < length; i++)
    {
        if (text[i] < '0' || text[i] > '9')
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

    if (length - start > 15)
    {
        return 0;
    }

    for (i = start; i < length; i++)
    {
        if (text[i] == '.')
        {
            dots++;
        }
        else if (text[i] >= '0' && text[i] <= '9')
        {
            digits++;
        }
        else
        {
            return 0;
        }
    }

    if (digits == 0 || dots > 1)
    {
        return 0;
    }
    return 1;
}

/* 1 if text is empty or contains only spaces */
int isBlank(char text[])
{
    int length = strlen(text);
    int i;

    for (i = 0; i < length; i++)
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

    for (i = 0; i < length; i++)
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
    if (lastDot < atPosition + 2 || lastDot == length - 1)
    {
        return 0;
    }
    return 1;
}

/* 1 if text is 7 to 15 digits, optionally starting with + */
int isValidPhone(char text[])
{
    int length = strlen(text);
    int start = 0;
    int i;

    if (text[0] == '+')
    {
        start = 1;
    }

    if (length - start < 7 || length - start > 15)
    {
        return 0;
    }

    for (i = start; i < length; i++)
    {
        if (text[i] < '0' || text[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}

/* Converts text already checked by isWholeNumber() into an int */
int textToInt(char text[])
{
    int length = strlen(text);
    int value = 0;
    int sign = 1;
    int i = 0;

    if (text[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    for (; i < length; i++)
    {
        value = value * 10 + (text[i] - '0');
    }
    return sign * value;
}

/* Converts text already checked by isDecimalNumber() into a double */
double textToDouble(char text[])
{
    int length = strlen(text);
    double value = 0.0;
    double place = 0.1;
    int sign = 1;
    int afterDot = 0;
    int i = 0;

    if (text[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    for (; i < length; i++)
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

/* Asks until the user enters a whole number from min to max */
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
            if (value < min || value > max)
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

/* Asks until the user enters a number from min to max */
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
            if (value < min || value > max)
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

/* Asks until the user enters text that is not empty (spaces allowed inside) */
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

/* Asks until the user enters a valid email */
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

/* Asks until the user enters a valid phone number */
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

/* Waits for the user to press Enter */
void pauseScreen()
{
    char text[10];

    printf("\nPress Enter to continue...");
    readText(text, sizeof(text));
}
