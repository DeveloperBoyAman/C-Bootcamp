#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// FUNCTION DELARATIONS
int takeOnlyInt(void);
int choiceMenu(void);
void firstnNaturalNums(int);
void reverseFirstnNaturalNums(int);
void naturalNumsKtoN(int, int);
void reverseNaturalNumsKtoN(int, int);
void evenOrOdd(int);
void firstnEvenNums(int);
void firstnOddNums(int);
void evenNumsKtoN(int, int);
void oddNumsKtoN(int, int);
void reverseEvenNumsKtoN(int, int);
void reverseOddNumsKtoN(int, int);
void primeOrNot(int);
void primeNumsKtoN(int, int);
void printTable(int);
unsigned long int powerOfbase(int, int);
unsigned long int factorial(int);
void firstnFibonaci(int);
int nthNumberOfFibonacci(int);
// FUNCTION DEFINITIONS

int takeOnlyInt()
{
    int num = 0, ch;
    do
    {
        ch = getch();
        if (ch >= 48 && ch <= 57)
        {
            num = num * 10 + (ch - 48);
            putchar(ch);
        }
        if (ch == 32 || ch == 13)
            break;
    } while (1);
    printf("\n");
    return num;
}

int choiceMenu()
{
    int choice;
    printf("\nFollowing Programs Available :- ");
    printf("\nPress 0: Exit");
    printf("\nPress 1: Print First n Natural Numbers");
    printf("\nPress 2: Print Reverse First n Natural Numbers");
    printf("\nPress 3: Print Natural Numbers Between Given Numbers");
    printf("\nPress 4: Print Reverse Natural Numbers Between Given Numbers");
    printf("\nPress 5: Check A Number Is Even Or Odd");
    printf("\nPress 6: Print First n Even Numbers");
    printf("\nPress 7: Print First n Odd Numbers");
    printf("\nPress 8: Print Even Numbers Between Given Numbers");
    printf("\nPress 9: Print Odd Numbers Between Given Numbers");
    printf("\nPress 10: Print Reverse Even Numbers Between Given Numbers");
    printf("\nPress 11: Print Reverse Odd Numbers Between Given Numbers");
    printf("\nPress 12: Check A Number Is Prime or Not");
    printf("\nPress 13: Print Prime Numbers Between Given Numbers");
    printf("\nPress 14: Print Table Of Any Number");
    printf("\nPress 15: Find Power Of Any Base Number");
    printf("\nPress 16: Find Factorial Any  Number");
    printf("\nPress 17: Print First n Fibonaci  Numbers");
    printf("\nPress 18: Print Nth Number of Fibonacci Series");
    printf("\nEnter Your Choice :");
    scanf("%d", &choice);
    return choice;
}
void firstnNaturalNums(int n)
{
    if (n < 1)
        printf("\n Error !! Please Enter Positive Number");
    else
    {
        int i;
        printf("First %d Natural Numbers Are :- \n", n);
        for (i = 1; i <= n; i++)
            printf("%d\n", i);
    }
}
void reverseFirstnNaturalNums(int n)
{
    if (n < 1)
        printf("\n Error !! Please Enter Positive Number");
    else
    {
        int i;
        printf("First %d Reverse Natural Numbers Are :-\n ", n);
        for (i = n; i >= 1; i--)
            printf("%d\n", i);
    }
}
void naturalNumsKtoN(int startNum, int endNum)
{
    if (startNum > endNum)
        printf("\n Error !! Starting Number Cannot Be Greater Than Ending Number");
    else
    {
        int i;
        printf(" Natural Numbers Between %d To %d Are :-\n ", startNum, endNum);
        for (i = startNum; i <= endNum; i++)
            printf("\n%d", i);
    }
}
void reverseNaturalNumsKtoN(int startNum, int endNum)
{
    if (startNum > endNum)
        printf("\n Error !! Starting Number Cannot Be Greater Than Ending Number");
    else
    {
        int i;
        printf("Reverse Natural Numbers Between %d To %d Are :-\n ", startNum, endNum);
        for (i = endNum; i >= startNum; i--)
            printf("\n%d", i);
    }
}
void evenOrOdd(int n)
{
    if (n < 0)
        printf("Please Enter Positive Number\n");
    else if (n % 2 == 0)
        printf("%d is Even Number\n", n);
    else
        printf("%d is Odd Number\n", n);
}
void firstnEvenNums(int n)
{
    if (n < 1)
        printf("\n Error !! Please Enter Positive Number");
    else
    {
        int i;
        printf("First %d Even Numbers Are :- \n", n);
        for (i = 1; i <= n; i++)
            printf("%d\n", i * 2);
    }
}

void firstnOddNums(int n)
{
    if (n < 1)
        printf("\n Error !! Please Enter Positive Number");
    else
    {
        int i;
        printf("First %d Odd Numbers Are :- \n", n);
        for (i = 1; i <= n; i++)
            printf("%d\n", i * 2 - 1);
    }
}
void evenNumsKtoN(int startNum, int endNum)
{
    if (startNum > endNum)
        printf("\n Error !! Starting Number Cannot Be Greater Than Ending Number");
    else
    {
        int i;
        printf("Even Numbers Between %d To %d Are :-\n ", startNum, endNum);
        for (i = startNum; i <= endNum; i++)
            if (i % 2 == 0)
                printf("\n%d", i);
    }
}
void oddNumsKtoN(int startNum, int endNum)
{
    if (startNum > endNum)
        printf("\n Error !! Starting Number Cannot Be Greater Than Ending Number");
    else
    {
        int i;
        printf("Odd Numbers Between %d To %d Are :-\n ", startNum, endNum);
        for (i = startNum; i <= endNum; i++)
            if (i % 2 != 0)
                printf("\n%d", i);
    }
}
void reverseEvenNumsKtoN(int startNum, int endNum)
{
    if (startNum > endNum)
        printf("\n Error !! Starting Number Cannot Be Greater Than Ending Number");
    else
    {
        int i;
        printf("Reverse Even Numbers Between %d To %d Are :-\n ", startNum, endNum);
        for (i = endNum; i >= startNum; i--)
            if (i % 2 == 0)
                printf("\n%d", i);
    }
}
void reverseOddNumsKtoN(int startNum, int endNum)
{
    if (startNum > endNum)
        printf("\n Error !! Starting Number Cannot Be Greater Than Ending Number");
    else
    {
        int i;
        printf("Reverse Odd Numbers Between %d To %d Are :-\n ", startNum, endNum);
        for (i = endNum; i >= startNum; i--)
            if (i % 2 != 0)
                printf("\n%d", i);
    }
}
void primeOrNot(int n)
{
    int i;
    if (n < 0)
        printf("Please Enter Positive Number\n");
    else
    {
        for (i = 2; i < n; i++)
            if (n % i == 0)
                break;
    }
    if (i == n)
        printf("%d is a Prime Number\n", n);
    else
        printf("%d is  Not a Prime Number\n", n);
}
void primeNumsKtoN(int startNum, int endNum)
{
    if (startNum > endNum)
        printf("\n Error !! Starting Number Cannot Be Greater Than Ending Number");
    else
    {
        int i, j;
        printf("Prime Numbers Between %d To %d Are :-\n ", startNum, endNum);
        for (i = startNum; i <= endNum; i++)
        {
            for (j = 2; j < i; j++)
                if (i % j == 0)
                    break;
            if (i == j)
                printf("%d\n", i);
        }
    }
}
void printTable(int n)
{
    if (n < 1)
        printf("Please Enter Positive Number\n");
    else
    {
        int i;
        printf("Table of %d is :", n);
        for (i = 1; i <= 10; i++)
            printf("%d  * %d = %d\n", n, i, n * i);
    }
}
unsigned long int powerOfbase(int base, int power)
{
    unsigned long int result = 1;
    while (power > 0)
    {
        result *= base;
        power--;
    }
    return result;
}
unsigned long int factorial(int n)
{
    unsigned long int fact = 1;
    while (n > 0)
    {
        fact *= n;
        n--;
    }
    return fact;
}
void firstnFibonaci(int n)
{
    int prev = 0, next = 1, result, count = 1;
    if (n == 0)
        printf("Enter Number Greater Than 0\n");
    else
    {
        printf("First %d Fibonacci Numbers Are :-\n", n);
        while (count <= n)
        {
            if (count == 1)
                printf("%d\n", prev);
            else if (count == 2)
                printf("%d\n", next);
            else
            {
                result = prev + next;
                prev = next;
                next = result;
                printf("%d\n", result);
            }
            count++;
        }
    }
}
int nthNumberOfFibonacci(int n)
{
    int prev = 0, next = 1, result, count = 2;
    if (n == 0)
        printf("Enter Number Greater Than 0\n");
    else
    {
        if (n == 1)
            return prev;
        else if (n == 2)
            return next;
        else
        {
            while (count < n)
            {
                result = prev + next;
                prev = next;
                next = result;
                count++;
            }
            return result;
        }  
    }
    
}

// MAIN FUNCTION START
void main()
{
    while (1)
    {
        switch (choiceMenu())
        {
        case 0:
            printf("\nProgram Have End !!");
            exit(0);
        case 1:
        {
            int n;
            printf("How Many First Natural Numbers you Want To Print :-\n");
            n = takeOnlyInt();
            firstnNaturalNums(n);
        }
        break;
        case 2:
        {
            int n;
            printf("How Many First Reverse Natural Numbers you Want To Print :-\n");
            n = takeOnlyInt();
            reverseFirstnNaturalNums(n);
        }
        break;
        case 3:
        {
            int startNum, endNum;
            printf("Enter Starting Number And Ending Number :-\n");
            startNum = takeOnlyInt();
            endNum = takeOnlyInt();
            naturalNumsKtoN(startNum, endNum);
        }
        break;
        case 4:
        {
            int startNum, endNum;
            printf("Enter Starting Number And Ending Number :-\n");
            startNum = takeOnlyInt();
            endNum = takeOnlyInt();
            reverseNaturalNumsKtoN(startNum, endNum);
        }
        break;
        case 5:
        {
            int n;
            printf("Enter A Number :- \n");
            n = takeOnlyInt();
            evenOrOdd(n);
        }
        break;
        case 6:
        {
            int n;
            printf("How Many First Even Numbers you Want To Print :-\n");
            n = takeOnlyInt();
            firstnEvenNums(n);
        }
        break;
        case 7:
        {
            int n;
            printf("How Many First Odd Numbers you Want To Print :-\n");
            n = takeOnlyInt();
            firstnOddNums(n);
        }
        break;
        case 8:
        {
            int startNum, endNum;
            printf("Enter Starting Number And Ending Number :-\n");
            startNum = takeOnlyInt();
            endNum = takeOnlyInt();
            evenNumsKtoN(startNum, endNum);
        }
        break;
        case 9:
        {
            int startNum, endNum;
            printf("Enter Starting Number And Ending Number :-\n");
            startNum = takeOnlyInt();
            endNum = takeOnlyInt();
            oddNumsKtoN(startNum, endNum);
        }
        break;
        case 10:
        {
            int startNum, endNum;
            printf("Enter Starting Number And Ending Number :-\n");
            startNum = takeOnlyInt();
            endNum = takeOnlyInt();
            reverseEvenNumsKtoN(startNum, endNum);
        }
        break;
        case 11:
        {
            int startNum, endNum;
            printf("Enter Starting Number And Ending Number :-\n");
            startNum = takeOnlyInt();
            endNum = takeOnlyInt();
            reverseOddNumsKtoN(startNum, endNum);
        }
        break;
        case 12:
        {
            int n;
            printf("Enter A Number :- \n");
            n = takeOnlyInt();
            primeOrNot(n);
        }
        break;
        case 13:
        {
            int startNum, endNum;
            printf("Enter Starting Number And Ending Number :-\n");
            startNum = takeOnlyInt();
            endNum = takeOnlyInt();
            primeNumsKtoN(startNum, endNum);
        }
        case 14:
        {
            int n;
            n = takeOnlyInt();
            printTable(n);
        }
        break;
        case 15:
        {
            int base, power;
            unsigned long int result;
            printf("Enter Base Number:\n");
            base = takeOnlyInt();
            printf("Enter Power:\n");
            power = takeOnlyInt();
            result = powerOfbase(base, power);
            printf("Result is : %lu", result);
        }
        break;
        case 16:
        {
            int n;
            unsigned long int result;
            printf("Enter A Number:\n");
            n = takeOnlyInt();
            result = factorial(n);
            printf("Factorial of %d is : %lu\n", n, result);
        }
        break;
        case 17:
        {
            int n;
            printf("How Many Numbers You Want To Print:\n");
            n = takeOnlyInt();
            firstnFibonaci(n);
        }
        break;
        case 18:
        {
            int n, result;
            printf("Which Number of You Want To Print:\n");
            n = takeOnlyInt();
            result = nthNumberOfFibonacci(n);
            printf("Number is : %d \n", result);
        }
        break;
        default:
            printf("\n Invalid Choice");
        }
        getch();
    }
}
// MAIN FUNCTION END