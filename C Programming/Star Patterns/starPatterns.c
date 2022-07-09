#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// FUNCTION DECLARATIONS
int takeOnlyInt();
int choice();
void starPattern1(int);
void starPattern2(int);
void starPattern3(int);
void starPattern4(int);
void starPattern5(int);
void starPattern6(int);
void starPattern7(int);

// FUNCTION DEFINITIONS
int takeOnlyInt()
{
    int num = 0, ch;
    while (1)
    {
        ch = getch();
        if (ch == 13 || ch == 32)
            break;
        if (ch >= 48 && ch <= 57)
        {
            putch(ch);
            num = num * 10 + ch - 48;
        }
    }
    return num;
}

int choice()
{
    int choice;
    printf("Following Options Are Available :-\n");
    printf("Press 0 : Exit\n");
    printf("Press 1 : Star Pattern 1\n");
    printf("Press 2 : Star Pattern 2\n");
    printf("Press 3 : Star Pattern 3\n");
    printf("Press 4 : Star Pattern 4\n");
    printf("Press 5 : Star Pattern 5\n");
    printf("Press 6 : Star Pattern 6\n");
    printf("Press 7 : Star Pattern 7\n");
    printf("Press 8 : Star Pattern 8\n");
    printf("Enter Choice :- \n");
    choice = takeOnlyInt();
    printf("\n");
    return choice;
}

void starPattern1(int row)
{
    int i, j;
    printf("Star Pattern 1 :-\n");
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
}

void starPattern2(int row)
{
    int i, j, k;
    printf("Star Pattern 2 :-\n");
    for (i = 1; i <= row; i++)
    {
        for (k = 1; k <= row - i; k++)
            printf(" ");
        for (j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
}
void starPattern3(int row)
{
    int i, j;
    printf("Star Pattern 3 :-\n");
    for (i = row; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
}

void starPattern4(int row)
{
    int i, j, k;
    printf("Star Pattern 4 :-\n");
    for (i = 1; i <= row; i++)
    {
        for (k = 1; k < i; k++)
            printf(" ");
        for (j = i; j <= row; j++)
            printf("*");
        printf("\n");
    }
}
void starPattern5(int row)
{
    int i, j;
    printf("Star Pattern 5 :-\n");
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= row * 2 - 1; j++)
            j >= row + 1 - i &&j <= row - 1 + i ? printf("*") : printf(" ");
        printf("\n");
    }
}
void starPattern6(int row)
{
    int i, j;
    printf("Star Pattern 6 :-\n");
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= row * 2 - 1; j++)
            j >= i &&j <= row * 2 - i ? printf("*") : printf(" ");
        printf("\n");
    }
}
void starPattern7(row)
{
    int i, j, k = 1;
    printf("Star Pattern 6 :-\n");
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= row * 2 - 1; j++)

            if (j >= row + 1 - i && j <= row - 1 + i && k)
            {
                printf("*");
                k = 0;
            }
            else
            {
                printf(" ");
                k = 1;
            }
        printf("\n");
    }
}
void starPattern8(row)
{
    int i, j, k = 1;
    printf("Star Pattern 6 :-\n");
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= row * 2 - 1; j++)

            if (j >= i && j <= row *2 - i && k)
            {
                printf("*");
                k = 0;
            }
            else
            {
                printf(" ");
                k = 1;
            }
        printf("\n");
    }
}

// MAIN FUNCTION START
void main()
{
    while (1)
    {
        switch (choice())
        {
        case 0:
            exit(0);
        case 1:
        {
            int row;
            printf("How Many Rows : \n");
            row = takeOnlyInt();
            starPattern1(row);
        }
        break;
        case 2:
        {
            int row;
            printf("How Many Rows : \n");
            row = takeOnlyInt();
            starPattern2(row);
        }
        break;
        case 3:
        {
            int row;
            printf("How Many Rows : \n");
            row = takeOnlyInt();
            starPattern3(row);
        }
        break;
        case 4:
        {
            int row;
            printf("How Many Rows : \n");
            row = takeOnlyInt();
            starPattern4(row);
        }
        break;
        case 5:
        {
            int row;
            printf("How Many Rows : \n");
            row = takeOnlyInt();
            starPattern5(row);
        }
        break;
        case 6:
        {
            int row;
            printf("How Many Rows : \n");
            row = takeOnlyInt();
            starPattern6(row);
        }
        break;
        case 7:
        {
            int row;
            printf("How Many Rows : \n");
            row = takeOnlyInt();
            starPattern7(row);
        }
        break;
        case 8:
        {
            int row;
            printf("How Many Rows : \n");
            row = takeOnlyInt();
            starPattern8(row);
        }
        break;
        default:
            printf("Invalid Choice");
        }
    }
    getch();
}
// MAIN FUNCTION END