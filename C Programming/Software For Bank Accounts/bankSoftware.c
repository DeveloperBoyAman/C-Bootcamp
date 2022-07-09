#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
// CREATE A BANk ACCOUNT DATA TYPE
typedef struct
{
    char name[20];
    char mobileNumber[15];
    char ifscCode[10];
    char accountNumber[17];
    char dOrG[10];
    int accountId;
    int age;
    int countTransactions;
    int countTotalTransactions;
    float accountBalance;
    float lastTenTransactions[10];
    struct
    {
        char village[20];
        char houseNumber[10];
    } address;
    struct
    {
        int date;
        int month;
        int year;
    } dob;
    struct
    {
        int date[10];
        int month[10];
        int year[10];
        int hour[10];
        int minute[10];
        int second[10];
        char amOrPm[10][3];

    } transactionDMYandTime;
    struct
    {
        int date;
        int month;
        int year;
        int hour;
        int minute;
        int second;
        char amOrPm[3];
    } accountCreatedDateTime;
} account;

// GLOBAL VARIABLES
account users[10];
int countUser, usersLimit = 10;

// FUNCTION DECLARATIONS
int usersChoice(void);
account createNewAccount();
void setAccountCreatedDateTime(account *);
void resetAccountValues(account *);
int validateName(account *);
int validateMobileNumber(account *);
int validateDob(account *);
int validateAddress(account *);
void createAccountNumber(account *);
void invalidDetailsMessage(void);
void deleteAccount(void);
int compareAccountNumber(char *, char *);
int compareAccountHolderName();
int idExistOrNot();
void depositCash();
void getCash();
void viewBalanceInAccount();
void setLastTenTransactions(account *, float, char);
void showLastTenTransactions();
void setTransactionsDMYandTime(account *);
// FUNCTION DEFINITIONS
// FUNCTION TO TAKE USER'S CHOICE
int usersChoice()
{
    int choice;
    printf(".............................................\n");
    printf("Press 0 : For Exit\n");
    printf("Press 1 : For Create A New Acccount\n");
    printf("Press 2 : For Get My Account Details\n");
    printf("Press 3 : For Delete A Account\n");
    printf("Press 4 : For Deposit Cash\n");
    printf("Press 5 : For Get Cash\n");
    printf("Press 6 : For Check Balance In Your Account\n");
    printf("Press 7 : For See Last Ten Deposits\n");
    scanf("%d", &choice);
    return choice;
}
// FUNCTION FOR CREATE A NEW ACCOUNT
account createNewAccount()
{
    account user;
    if (countUser < usersLimit)
    {
        printf("********* Please Enter valid Details **********\n");
        printf("Enter Account Holder Name \n");
        printf("Name Must be Contains less than 20 Characters And Cannot Contains Digits\n");
        fflush(stdin);
        gets(user.name);
        if (validateName(&user))
        {
            printf("Enter Mobile Number \n");
            printf("Mobile Number Must be of 10 Digits and Valid\n");
            fflush(stdin);
            gets(user.mobileNumber);
            if (validateMobileNumber(&user))
            {
                printf("Enter Date of Birth \n");
                printf("Please Enter Valid Date of Birth\n");
                printf("Enter Birth Date\n");
                scanf("%d", &user.dob.date);
                printf("Enter Birth Month\n");
                scanf("%d", &user.dob.month);
                printf("Enter Birth Year\n");
                scanf("%d", &user.dob.year);
                if (validateDob(&user))
                {
                    printf("Enter House Number\n");
                    printf("House Number Cannot Contains Alphabets characters And Must be Less than 10 Digits\n");
                    fflush(stdin);
                    gets(user.address.houseNumber);
                    // SET USERS AGE
                    SYSTEMTIME stime;
                    GetSystemTime(&stime);
                    user.age = stime.wYear - user.dob.year;
                    fflush(stdin);
                    printf("Enter Address \n");
                    printf("Enter village Name Or City Name\n");
                    printf("village or city Name Must be Contains less than 20 Characters And Cannot Contains Digits\n");
                    gets(user.address.village);
                    if (validateAddress(&user))
                    {
                        // SET ACCOUNT BALANCE
                        user.accountBalance = 0;
                        // SET COUNT TRANSACTIONS
                        user.countTransactions = 0;
                        user.countTotalTransactions = 0;
                        // SET ACCOUNT CREATED DATE AND TIME
                        setAccountCreatedDateTime(&user);
                        printf("________Successfully Account Created__________\n");
                        // CALL TO CREATE ACCOUT NUMBER
                        createAccountNumber(&user);
                        printf("Your Account Number is :- ");
                        puts(user.accountNumber);
                        // SET IFSC CODE
                        printf("Your Bank IFSC Code is :- ");
                        strcpy(user.ifscCode, "PUNB02789");
                        printf("%s\n", user.ifscCode);
                        // SET ACCOUNT ID
                        user.accountId = countUser + 1;
                        printf("Your Account ID is :- %d\n", user.accountId);
                        printf("Please Don't Forget Your Account ID And Account Number\n");

                        countUser++;
                        getch();
                        return user;
                    }
                    else
                        invalidDetailsMessage();
                }
                else
                    invalidDetailsMessage();
            }
            else
                invalidDetailsMessage();
        }
        else
            invalidDetailsMessage();
    }
    else
    {
        printf("Maximum Accounts Created So You Cannot Create A New Account\n");
    }
}
// FUNCTION FOR SET ACCOUNT CREATED DATE AND TIME
void setAccountCreatedDateTime(account *ptr)
{
    // SET DATE MONTH YEAR
    SYSTEMTIME sysTime;
    GetSystemTime(&sysTime);
    ptr->accountCreatedDateTime.date = sysTime.wDay;
    ptr->accountCreatedDateTime.month = sysTime.wMonth;
    ptr->accountCreatedDateTime.year = sysTime.wYear;
    // SET TIME
    time_t seconds;
    struct tm *timeStruct;
    int hour;
    seconds = time(NULL);
    timeStruct = localtime(&seconds);
    hour = timeStruct->tm_hour > 12 ? timeStruct->tm_hour - 12 : timeStruct->tm_hour;
    if (timeStruct->tm_hour > 12)
    {
        strcpy(ptr->accountCreatedDateTime.amOrPm, "PM");
    }
    else
    {
        strcpy(ptr->accountCreatedDateTime.amOrPm, "AM");
    }
    ptr->accountCreatedDateTime.hour = hour;
    ptr->accountCreatedDateTime.minute = timeStruct->tm_min;
    ptr->accountCreatedDateTime.second = timeStruct->tm_sec;
}
// FUNCTION FOR RESET ACCOUNT VALUES
void resetAccountValues(account *ptr)
{
    strcpy(ptr->name, "...");
    strcpy(ptr->mobileNumber, "...");
    strcpy(ptr->accountNumber, "...");
    strcpy(ptr->ifscCode, "...");
    ptr->accountId = -22;
    ptr->accountBalance = 0;
    ptr->age = 0;
    ptr->dob.date = 0;
    ptr->dob.month = 0;
    ptr->dob.year = 0;
    strcpy(ptr->address.houseNumber, "...");
    strcpy(ptr->address.village, "...");
}
// FUNCTION TO VALIDATE ACCOUNT HOLDER NAME
int validateName(account *ptr)
{
    int i;
    if ((ptr->name[0] < 65 || ptr->name[0] > 90) && (ptr->name[0] < 97 || ptr->name[0] > 122))
    {
        printf("Enterd Name is Invalid !!!\n");
        return 0;
    }
    for (i = 0; ptr->name[i]; i++)
        if ((ptr->name[i] < 65 || ptr->name[i] > 90) && (ptr->name[i] < 97 || ptr->name[i] > 122) && ptr->name[i] != 32)
        {
            printf("Enterd Name is Invalid !!!\n");
            return 0;
        }
    return 1;
}
// FUNCTION TO VALIDATE MOBILE NUMBER
int validateMobileNumber(account *ptr)
{
    int i;
    if (strlen(ptr->mobileNumber) == 10)
    {
        for (i = 0; ptr->mobileNumber[i]; i++)
            if (ptr->mobileNumber[i] < 48 || ptr->mobileNumber[i] > 57)
            {
                printf("Enterd Mobile Number is Invalid !!!\n");
                return 0;
            }
    }
    else
    {
        printf("Enterd Mobile Number is Invalid !!!\n");
        return 0;
    }
    return 1;
}
// FUNCTION TO VALIDATE DOB
int validateDob(account *ptr)
{
    SYSTEMTIME stime;
    GetSystemTime(&stime);
    if (ptr->dob.date < 1 || ptr->dob.date > 31 || ptr->dob.month < 1 || ptr->dob.month > 12 || ptr->dob.year < 1971 || ptr->dob.year > stime.wYear)
    {
        printf("Entered Date of Birth is Invalid !!!\n");
        return 0;
    }
    return 1;
}
// FUNCTION TO VALIDATE ADDRESS
int validateAddress(account *ptr)
{
    int i;
    for (i = 0; ptr->address.houseNumber[i]; i++)
        if (ptr->address.houseNumber[i] < 48 || ptr->address.houseNumber[i] > 57)
        {
            printf("Enterd House Number is Invalid !!!\n");
            return 0;
        }
    if ((ptr->address.village[0] < 65 || ptr->address.village[0] > 90) && (ptr->address.village[0] < 97 || ptr->address.village[0] > 122))
    {
        printf("Enterd Name is Invalid !!!\n");
        return 0;
    }
    for (i = 0; ptr->address.village[i]; i++)
        if ((ptr->address.village[i] < 48 || ptr->address.village[i] > 57) && (ptr->address.village[i] < 65 || ptr->address.village[i] > 90) && (ptr->address.village[i] < 97 || ptr->address.village[i] > 122) && ptr->address.village[i] != 32)
        {
            printf("Enterd Village or City Name is Invalid !!!\n\n");
            return 0;
        }
    return 1;
}

// FUNCTION TO CREATE A ACCOUNT NUMBER
void createAccountNumber(account *ptr)
{
    int i, lowerLimit = 0, upperLimit = 9;
    ptr->accountNumber[0] = '2';
    ptr->accountNumber[1] = '7';
    ptr->accountNumber[2] = '0';
    ptr->accountNumber[3] = '6';
    ptr->accountNumber[4] = '0';
    ptr->accountNumber[5] = '0';
    ptr->accountNumber[6] = '0';
    ptr->accountNumber[7] = '1';
    ptr->accountNumber[8] = '0';
    ptr->accountNumber[9] = '0';
    srand(countUser);
    for (i = 0; i < 6; i++)
    {
        ptr->accountNumber[i + 10] = ((rand() % (upperLimit - lowerLimit + 1)) + lowerLimit) + 48;
    }
    ptr->accountNumber[16] = '\0';
}
// FUNCTION FOR SHOW MESSAGE ON INVALID DETAILS
void invalidDetailsMessage()
{
    printf("OOPS !! Account Not Created \nPlease Enter Valid Details and Try Again.........\n\n");
    getch();
}
// FUNCTION TO GET MY ACCOUNT DETAILS
void getMyAccountDetails()
{
    int id;
    char acNum[17];
    printf("Enter Your Account ID for Access Your Account\n");
    scanf("%d", &id);
    if (idExistOrNot(id))
    {
        id -= 1;
        printf("Enter Your Account Number \n");
        fflush(stdin);
        gets(acNum);
        if (compareAccountNumber(users[id].accountNumber, acNum))
        {
            printf("********* YOUR ACCOUNT DETAILS ***********\n");
            int i;
            printf("Account Holder Name : ");
            puts(users[id].name);
            printf("Balance In Your Account : %.2f\n", users[id].accountBalance);
            printf("Account Number : ");
            puts(users[id].accountNumber);
            printf("Account ID : %d\n", users[id].accountId);
            printf("Account Created Date : %d/%d/%d\n", users[id].accountCreatedDateTime.date, users[id].accountCreatedDateTime.month, users[id].accountCreatedDateTime.year);
            printf("Account Created Time : %d:%d:%d %s\n", users[id].accountCreatedDateTime.hour, users[id].accountCreatedDateTime.minute, users[id].accountCreatedDateTime.second, users[id].accountCreatedDateTime.amOrPm);
            printf("Date of Birth : %d/%d/%d\n", users[id].dob.date, users[id].dob.month, users[id].dob.year);
            printf("Age : %d\n", users[id].age);
            printf("Address :-\n");
            printf("Village or City Name : %s\nHouse Number : %s\n", users[id].address.village, users[id].address.houseNumber);
        }
        else
        {
            printf("Incorrect Account Number!! Try Agian\n");
        }
    }
    else
        printf("Account ID Does Not Exist\n");
    getch();
}
// FUNCTION FOR DELETE AN ACCOUNT
void deleteAccount()
{
    int id, yesNo;
    char acNum[17];
    printf("Enter Your Account ID\n");
    scanf("%d", &id);
    if (idExistOrNot(id))
    {
        id -= 1;
        printf("Enter Your Account Number \n");
        fflush(stdin);
        gets(acNum);
        if (compareAccountNumber(users[id].accountNumber, acNum))
        {
            printf("Are You You Want To delete This Account..\n");
            printf("If YES Than Press : 1\nIf NO Than Press :0\n");
            scanf("%d", &yesNo);
            if (yesNo == 1)
            {
                resetAccountValues(&users[id]);
                countUser--;
                printf("Account Deleted ....\n");
            }
        }
        else
        {
            printf("Incorrect Account Number!! Try Agian\n");
        }
    }
    else
        printf("Account ID Does Not Exist\n");
    getch();
}
// FUNCTION FOR COMPARE ACCOUNT NUMBER
int compareAccountNumber(char *ptr1, char *ptr2)
{
    int i;
    if (strcmp(ptr1, ptr2))
        return 0;
    return 1;
}
// FUNCTION FOR SEARCH ID IS EXIST OR NOT
int idExistOrNot(int acId)
{
    for (int i = 0; i < 10; i++)
    {
        if (users[i].accountId == acId)
            return 1;
    }
    return 0;
}
// FUNCTION FOR COMPARE ACCOUNT HOLDER NAME
int compareAccountHolderName(char *ptr1, char *ptr2)
{
    int i;
    if (strcmp(ptr1, ptr2))
        return 0;
    return 1;
}
// FUNCTION FOR DEPOSIT CASH
void depositCash()
{
    int id;
    float amount;
    char acNum[17], acName[20];
    printf("Enter Your Account ID\n");
    scanf("%d", &id);
    if (idExistOrNot(id))
    {
        id -= 1;
        printf("Enter Your Name :\n");
        fflush(stdin);
        gets(acName);
        if (compareAccountHolderName(users[id].name, acName))
        {
            printf("Enter Your Account Number : \n");
            fflush(stdin);
            gets(acNum);
            if (compareAccountNumber(users[id].accountNumber, acNum))
            {
                printf("Enter Amount In Digits :");
                scanf("%f", &amount);
                if (amount > 0)
                {
                    users[id].accountBalance += amount;
                    printf("Rs.%.2f Have Depositd\n", amount);
                    setLastTenTransactions(&users[id], amount, 'd');
                }
                else
                {
                    printf("Incorrect Amount !!!! Try Again \n");
                }
            }
            else
            {
                printf("Incorrect Account !! Try Agian\n");
            }
        }
        else
        {
            printf("Incorrect Name !! Try Again\n");
        }
    }
    else
        printf("Account ID Does Not Exist\n");
    getch();
}
// FUNCTION FOR GET CASH
void getCash()
{
    int id;
    float amount;
    char acNum[17], acName[20];
    printf("Enter Your Account ID\n");
    scanf("%d", &id);
    if (idExistOrNot(id))
    {
        id -= 1;
        printf("Enter Your Name :\n");
        fflush(stdin);
        gets(acName);
        if (compareAccountHolderName(users[id].name, acName))
        {
            printf("Enter Your Account Number : \n");
            fflush(stdin);
            gets(acNum);
            if (compareAccountNumber(users[id].accountNumber, acNum))
            {
                printf("How Much Amount You Want to Withdraw \nEnter Amount In Digits :");
                scanf("%f", &amount);
                if (amount > 0)
                {
                    if (amount > users[id].accountBalance)
                    {
                        printf("Insufficient Balance In Your Account\n");
                    }
                    users[id].accountBalance -= amount;
                    printf("Rs.%.2f Have Debited\n", amount);
                    setLastTenTransactions(&users[id], amount, 'g');
                }
                else
                {
                    printf("Incorrect Amount !!!! Try Again \n");
                }
            }
            else
            {
                printf("Incorrect Account !! Try Agian\n");
            }
        }
        else
        {
            printf("Incorrect Name !! Try Again\n");
        }
    }
    else
        printf("Account ID Does Not Exist\n");
    getch();
}
// FUNCTION FOR SEE BALANCE IN ACCOUNT
void viewBalanceInAccount()
{
    int id;
    char acNum[17];
    printf("Enter Your Account ID\n");
    scanf("%d", &id);
    if (idExistOrNot(id))
    {
        id -= 1;
        printf("Enter Your Account Number \n");
        fflush(stdin);
        gets(acNum);
        if (compareAccountNumber(users[id].accountNumber, acNum))
        {
            printf("Balance In Your Account : %.2f", users[id].accountBalance);
        }
        else
        {
            printf("Incorrect Account Number!! Try Agian\n");
        }
    }
    else
        printf("Account ID Does Not Exist\n");
    getch();
}
// FUNCTION TO SET LAST TEN TRANSACTIONS
void setLastTenTransactions(account *ptr, float amount, char dOrG)
{
    if (ptr->countTransactions == 10)
    {
        ptr->countTransactions = 0;
    }
    ptr->lastTenTransactions[ptr->countTransactions] = amount;
    ptr->dOrG[ptr->countTransactions] = dOrG;
    setTransactionsDMYandTime(ptr);
    // INCREMENT TRANSACTIONS
    ptr->countTransactions++;
    ptr->countTotalTransactions++;
}
// FUNCTION FOR SET TRANSACTION DAY,MONTH,YEAR AND TIME
void setTransactionsDMYandTime(account *ptr)
{
    // SET DATE MONTH YEAR
    SYSTEMTIME sysTime;
    GetSystemTime(&sysTime);
    ptr->transactionDMYandTime.date[ptr->countTransactions] = sysTime.wDay;
    ptr->transactionDMYandTime.month[ptr->countTransactions] = sysTime.wMonth;
    ptr->transactionDMYandTime.year[ptr->countTransactions] = sysTime.wYear;
    // SET TIME
    int hour;
    time_t seconds;
    struct tm *timeStruct;
    seconds = time(NULL);
    timeStruct = localtime(&seconds);
    hour = timeStruct->tm_hour > 12 ? timeStruct->tm_hour - 12 : timeStruct->tm_hour;
    if (timeStruct->tm_hour > 12)
    {
        strcpy(ptr->transactionDMYandTime.amOrPm[ptr->countTransactions], "PM");
    }
    else
    {
        strcpy(ptr->transactionDMYandTime.amOrPm[ptr->countTransactions], "AM");
    }
    ptr->transactionDMYandTime.hour[ptr->countTransactions] = hour;
    ptr->transactionDMYandTime.minute[ptr->countTransactions] = timeStruct->tm_min;
    ptr->transactionDMYandTime.second[ptr->countTransactions] = timeStruct->tm_sec;
}
// FUNCTION FOR SHOW LAST TEN DEPOSITS
void showLastTenTransactions()
{
    int id;
    char acNum[17];
    printf("Enter Your Account ID\n");
    scanf("%d", &id);
    if (idExistOrNot(id))
    {
        id -= 1;
        printf("Enter Your Account Number \n");
        fflush(stdin);
        gets(acNum);
        if (compareAccountNumber(users[id].accountNumber, acNum))
        {
            if (users[id].countTotalTransactions > 0)
            {
                int i;
                printf("********** Your Last Ten Amounts of Deposits ************\n");
                i = users[id].countTotalTransactions > 10 ? users[id].countTransactions : 0;
                while (i < users[id].countTotalTransactions - users[id].countTransactions || i < users[id].countTransactions)
                {
                    if (users[id].dOrG[i] == 'd')
                    {
                        printf("Credited : %.2f On %d/%d/%d at %d:%d:%d %s\n", users[id].lastTenTransactions[i], users[id].transactionDMYandTime.date[i], users[id].transactionDMYandTime.month[i], users[id].transactionDMYandTime.year[i], users[id].accountCreatedDateTime.hour, users[id].accountCreatedDateTime.minute, users[id].accountCreatedDateTime.second, users[id].accountCreatedDateTime.amOrPm);
                    }
                    else
                    {
                        printf("Debited : %.2f On %d/%d/%d at %d:%d:%d %s\n", users[id].lastTenTransactions[i], users[id].transactionDMYandTime.date[i], users[id].transactionDMYandTime.month[i], users[id].transactionDMYandTime.year[i], users[id].accountCreatedDateTime.hour, users[id].accountCreatedDateTime.minute, users[id].accountCreatedDateTime.second, users[id].accountCreatedDateTime.amOrPm);
                    }
                    if (users[id].countTotalTransactions > 10 && i == 9)
                    {
                        for (int j = 0; j < users[id].countTransactions; j++)
                        {
                            if (users[id].dOrG[j] == 'd')
                            {
                                printf("Credited : %.2f On %d/%d/%d\n", users[id].lastTenTransactions[j], users[id].transactionDMYandTime.date[j], users[id].transactionDMYandTime.month[j], users[id].transactionDMYandTime.year[j]);
                            }
                            else
                            {
                                printf("Credited : %.2f\n", users[id].lastTenTransactions[j]);
                            }
                        }
                    }
                    i++;
                }
            }
            else
            {
                printf("No Transactions Yet \n");
            }
        }
        else
        {
            printf("Incorrect Account Number!! Try Agian\n");
        }
    }
    else
        printf("Account ID Does Not Exist\n");
    getch();
}
// MAIN FUNCTION START
void main()
{
    while (1)
    {
        printf("**** WELCOME TO BANKING WITH AMAN ****\n");
        printf(">>>> You Can Create Maximum 10 Accounts >>>>>\n");
        if (countUser == 0)
            printf("No Accounts Are Created Yet\n");
        else
            printf("%d Accounts Are Already Created \n", countUser);
        switch (usersChoice())
        {
        case 0:
            exit(0);
        case 1:
            users[countUser] = createNewAccount(&countUser);
            break;
        case 2:
            getMyAccountDetails();
            break;
        case 3:

            deleteAccount();
            break;
        case 4:
            depositCash();
            break;
        case 5:
            getCash();
            break;
        case 6:
            viewBalanceInAccount();
            break;
        case 7:
            showLastTenTransactions();
        default:
            printf("Invalid choice\n");
        }
    }
}
// MAIN FUNCTION END