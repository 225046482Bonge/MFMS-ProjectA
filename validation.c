#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "validation.h"


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


int getInt(char prompt[], int min, int max)
{
    int value = 0;
    int result;
    int valid = 0;

    do
    {
        printf("%s", prompt);
        result = scanf("%d", &value);
        scanf("%*[^\n]");   

        if (result != 1)
        {
            printf("Error: enter a whole number.\n");
        }
        else if (value < min || value > max)
        {
            printf("Error: enter a number between %d and %d.\n", min, max);
        }
        else
        {
            valid = 1;
        }
    } while (valid == 0);

    return value;
}


double getDouble(char prompt[], double min, double max)
{
    double value = 0.0;
    int result;
    int valid = 0;

    do
    {
        printf("%s", prompt);
        result = scanf("%lf", &value);
        scanf("%*[^\n]");   

        if (result != 1)
        {
            printf("Error: enter a number.\n");
        }
        else if (value < min || value > max)
        {
            printf("Error: value must be between %.2f and %.2f.\n", min, max);
        }
        else
        {
            valid = 1;
        }
    } while (valid == 0);

    return value;
}


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


int equalsIgnoreCase(char a[], char b[])
{
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0')
    {
        if (tolower((unsigned char)a[i]) != tolower((unsigned char)b[i]))
        {
            return 0;
        }
        i++;
    }
    return a[i] == b[i];
}


int nameContains(char text[], char part[])
{
    int textLength = strlen(text);
    int partLength = strlen(part);
    int i;
    int j;

    if (partLength == 0)
    {
        return 1;
    }

    for (i = 0; i + partLength <= textLength; i++)
    {
        j = 0;
        while (j < partLength &&
               tolower((unsigned char)text[i + j]) == tolower((unsigned char)part[j]))
        {
            j++;
        }
        if (j == partLength)
        {
            return 1;
        }
    }
    return 0;
}

char *formatMoney(double amount)
{
    static char buffers[4][40];
    static int next = 0;
    char plain[40];
    char *out = buffers[next];
    int negative = 0;
    int digits;
    int i;
    int o = 0;

    next = (next + 1) % 4;

    if (amount < 0)
    {
        negative = 1;
        amount = -amount;
    }

    sprintf(plain, "%.2f", amount);        
    digits = strlen(plain) - 3;             

    if (negative)
    {
        out[o++] = '-';
    }
    out[o++] = 'N';
    out[o++] = '$';

    for (i = 0; i < digits; i++)
    {
        out[o++] = plain[i];
        if ((digits - i - 1) % 3 == 0 && i < digits - 1)
        {
            out[o++] = ',';
        }
    }
    strcpy(out + o, plain + digits);        
    return out;
}
