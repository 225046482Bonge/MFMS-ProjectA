/* validation.c - Functions for input and validation */
#include <stdio.h>
#include <string.h>
#include "validation.h"

/*if text is empty or contains only spaces */
int isBlank(char text[])
{
    int length = strlen(text);
    int i;

    if (length == 0)
    {
        return 1;
    }

    for (i = 0; i < length; i++)
    {
        if (text[i] != ' ')
        {
            return 0;
        }
    }
    return 1;
}

/*if text looks like name@example.com */
int isValidEmail(char text[])
{
    int length = strlen(text);
    int atCount = 0;
    int atPosition = -1;
    int lastDot = -1;
    int i;

    for (i = 0; i < length; i++)
    {
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

/* Returns 1 when the text consists of 7 to 15 digits, possibly preceded by + */
int isValidPhone(char text[])
{
    int length = strlen(text);
    int start = 0;
    int i;

    if (length > 0 && text[0] == '+')
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

/* Repeatedly prompts the user until a whole number between min and max is entered */
int getInt(char prompt[], int min, int max)
{
    int value = 0;

    do
    {
        printf("%s", prompt);
        scanf("%d", &value);

        if (value < min || value > max)
        {
            printf("Error: enter a number between %d and %d.\n", min, max);
        }
    } while (value < min || value > max);

    return value;
}

/* Asks until the user enters a number from min to max */
double getDouble(char prompt[], double min, double max)
{
    double value = 0.0;

    do
    {
        printf("%s", prompt);
        scanf("%lf", &value);

        if (value < min || value > max)
        {
            printf("Error: value must be between %.2f and %.2f.\n", min, max);
        }
    } while (value < min || value > max);

    return value;
}

/* Keeps prompting until the user provides non-empty text (spaces may appear within it).
 * The space at the start of the format discards a leftover Enter key from an
 * earlier scanf("%d") or scanf("%lf") call, as described in the Week 2 notes. */
void getNonEmptyString(char prompt[], char text[])
{
    do
    {
        printf("%s", prompt);
        scanf(" %49[^\n]", text);

        if (isBlank(text) == 1)
        {
            printf("Error: this field cannot be empty.\n");
        }
    } while (isBlank(text) == 1);
}

/* Keeps asking until the user enters a valid email */
void getEmail(char prompt[], char text[])
{
    do
    {
        printf("%s", prompt);
        scanf(" %49s", text);

        if (isValidEmail(text) == 0)
        {
            printf("Error: enter a valid email (e.g., name@example.com).\n");
        }
    } while (isValidEmail(text) == 0);
}

/* Keeps asking until the user provides a valid phone number */
void getPhone(char prompt[], char text[])
{
    do
    {
        printf("%s", prompt);
        scanf(" %49s", text);

        if (isValidPhone(text) == 0)
        {
            printf("Error: please enter between 7 and 15 digits (a leading + is permitted).\n");
        }
    } while (isValidPhone(text) == 0);
}
