#include <stdio.h>
#include <conio.h>

// Function Declarations
int totalDigitInNumber(long int);
int getKthDigit(long int, int);
int totalDigitInRealNumber(double);

int totalDigitInNUmber(long int num)
{
    if (num == 0)
        return 1;
    if (num < 0)
        num = -num;
    int totalDigit = 0;
    while (num > 0)
    {
        num /= 10;
        totalDigit++;
    }
    return totalDigit;
}

int getKthDigit(long int num, int kth)
{
    int totalDigit, rem;
    if (num < 0)
        num = -num;
    if (!num && kth)
        return 1;
    totalDigit = totalDigitInNUmber(num);
    while (num > 0)
    {
        rem = num % 10;
        num /= 10;
        if (totalDigit == kth)
            return rem;
        totalDigit--;
    }
    return 0;
}
int totalDigitInRealNumber(double num)
{
    int integeralPart, totalDigitInInt;
    double fractionalPart;
    integeralPart = (int)num;
    totalDigitInInt = totalDigitInNUmber(integeralPart);
    fractionalPart = num - integeralPart;
    printf("Integeral Part is :%d\n", integeralPart);
    printf("Fractional Part is :%lf\n", fractionalPart);
    int multiplyForInt = 16 - totalDigitInInt;
    int multiply = 1;
    while (multiplyForInt)
    {
        multiply = multiply * 10;
        multiplyForInt--;
    }
    
    fractionalPart = fractionalPart * multiply;
    printf("Integeral Part is :%d\n", integeralPart);
    printf("Fractional Part is :%lf\n", fractionalPart);
}

int main()
{
    // long int num;
    // int whichDigit, getKth, totalDigit;
    // printf("Enter A Number:");
    // scanf("%ld", &num);
    // printf("*****************************\n");
    // totalDigit = totalDigitInNUmber(num);
    // printf("Total Digit in Number:%d\n", totalDigit);
    // printf("Enter Which Number of Digit You want to Get:");
    // scanf("%d", &whichDigit);
    // getKth = getKthDigit(num, whichDigit);
    // if (getKth)
    // {
    //     printf("%dth digit is : %d", whichDigit, getKth);
    // }
    // else
    // {
    //     printf("Invalid!! Digit Not Exist");
    // }


      double num  = 1341.24345;
     totalDigitInRealNumber(num);

}
