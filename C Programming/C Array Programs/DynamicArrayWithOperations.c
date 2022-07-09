// PROGRAM TO CREATE ARRAY AND PERFORM OPERATIONS ON IT
// HEADER FILES
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
// FUNCTIONS DECLARATIONS
float *createMemoryblocks(int);
void takeElements(float *, int);
void showElements(float *, int);
void sortInAssending(float *, int);
void sortInDesending(float *, int);
int userAgree();
int choiceMenu();
float largestElement(float *, int);
float smallestElement(float *, int);
int searchElement(float *, int, float);
int deleteFirst(float *, int *);
int deleteLast(float *, int *);
int deleteParticular(float *, int *n, float);
int deleteMultiple(float*,int*,int,int);
void reverse(float *,int);
// FUNCTIONS DEFINITIONS
// FUNCTION FOR DELETE MULTIPLE ELEMENT TOGETHER
int deleteMultiple(float* ptr,int* n,int start_index,int hmnElements){
    int avilableElements =*n - start_index;
    if(start_index >=*n || hmnElements >= *n+1 || hmnElements >= avilableElements +1 ){
        return 0;
    }
    int i=start_index + hmnElements;
    for(;i<*n;i++){
        *(ptr+i-hmnElements)=*(ptr+i);
    }
    *n=*n-hmnElements;
    return 1;
}
// FUNCTION FOR REVERSE  ARRAY
void reverse(float* ptr,int n){
    int i;
    float temp;
    for(i=0;i<n/2;i++){
        temp=*(ptr+i);
        *(ptr+i)=*(ptr+n-1-i);
        *(ptr+n-1-i)=temp;
    }
}
// FUNCTION FOR DELETE A PARTICULAR ELEMENT
int deleteParticular(float *ptr, int *n, float element)
{
    int i, index;
    if (*n == 1)
        (*n)--;
    else
    {
        if ((index = searchElement(ptr, *n, element)) != -1)
        {
            for (i = *n - 1; i > index; i--)
                *(ptr + i - 1) = *(ptr + i);
            (*n)--;
            return 1;
        }
        return 0;
    }
}
// FUNCTION FOR DELETE FIRST ELEMENT
int deleteFirst(float *ptr, int *n)
{
    int i = 0;
    if (*n == 0)
        return 0;
    else if (*n == 1)
    {
        (*n)--;
        return 1;
    }
    else
    {
        for (i = 0; i < *n - 1; i++)
            *(ptr + i) = *(ptr + i + 1);
        (*n)--;
        return 1;
    }
}
// FUNCTION FOR DELETE LAST ELEMENT
int deleteLast(float *ptr, int *n)
{
    int i = 0;
    if (*n == 0)
        return 0;
    else
        (*n)--;
    return 1;
}
// FUNCTION FOR ALLOCATE MEMORY
float *createMemoryblocks(int n)
{
    if (n == 0)
    {
        printf("No Size Given !! Nothing Memory Space Allocated. Program END....\n");
        exit(0);
    }
    float *ptr = NULL;
    ptr = (float *)malloc(n * sizeof(float));
    return ptr;
}
// FUNCTION TO TAKE  ELEMENTS FROM USER
void takeElements(float *ptr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter Element : %d\n", i + 1);
        scanf("%f", ptr + i);
    }
}
// FUNCTION FOR SHOW ALL ELEMENTS
void showElements(float *ptr, int n)
{
    int i;
    if (n == 0)
        printf("No Elements In Memory \n");
    for (i = 0; i < n; i++)
        printf("Element %d :- %.2f \n", i + 1, *(ptr + i));
}
// FUNCTION FOR SORT ELEMENTS IN ASSENDING ORDER
void sortInAssending(float *ptr, int n)
{
    int i, j;
    float temp;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (*(ptr + j) < *(ptr + i))
            {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
}
// FUNCTION FOR SORT ELEMENTS IN DESENDING ORDER
void sortInDesending(float *ptr, int n)
{
    int i, j;
    float temp;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (*(ptr + j) > *(ptr + i))
            {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
}
// FUNCTION TO FIND LARGEST ELEMENT
float largestElement(float *ptr, int n)
{
    int i, large = *ptr;
    for (i = 1; i < n; i++)
    {
        large = *(ptr + i) > large ? *(ptr + i) : large;
    }
    return large;
}
// FUNCTION TO FIND SMALLEST ELEMENT
float smallestElement(float *ptr, int n)
{
    int i, small = *ptr;
    for (i = 1; i < n; i++)
    {
        small = *(ptr + i) < small ? *(ptr + i) : small;
    }
    return small;
}
// FUNCTION TO SERACH AN ELEMENT
int searchElement(float *ptr, int n, float element)
{
    int i;
    if (n == 0)
        printf("Given Array Size is Zero.So,Nothing Found \n");
    for (i = 0; i < n; i++)
        if (*(ptr + i) == element)
            return i;
    return -1;
}
// FUNCTION FOR TAKE USER'S PERMISION
int userAgree()
{
    int agree;
    static int count = 0;
    if (count == 0)
    {
        printf("Do You Want To Perform Operations On Elements\n");
    }
    else
    {
        printf("Again Want To Perform Operations On Elements\n");
    }
    printf("If YES then Press : 1\n");
    printf("If NO then Press : 0\n");
    scanf("%d", &agree);
    count++;
    return agree;
}
int choiceMenu()
{
    int choice;
    printf("Following Operations Available:-- \n");
    printf("Press 0 : For Exit !!\n");
    printf("Press 1 : Show All Elements\n");
    printf("Press 2 : For Elements Sort In Assending Order\n");
    printf("Press 3 : For Elements Sort In Desending Order\n");
    printf("Press 4 : For Get Largest Element\n");
    printf("Press 5 : For Get Smallest Element\n");
    printf("Press 6 : For Search An Element\n");
    printf("Press 7 : For Delete First Element\n");
    printf("Press 8 : For Delete Last Element\n");
    printf("Press 10 : For Reverse Array\n");
    printf("Press 11 : For Delete Multiple Elements\n");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int hmn;
    float *ptr = NULL;
    printf("How Many Elements You Want :- \n");
    scanf("%d", &hmn);
    ptr = createMemoryblocks(hmn);
    if (ptr == NULL)
    {
        printf("Sorry !! NO Space Available. Try again .Program END...\n");
        exit(0);
    }
    else
    {
        printf("Successfully Memory Allocated ..\n");
        printf("Enter Elements :- \n");
        takeElements(ptr, hmn);
        printf("All Elements are  :-\n");
        showElements(ptr, hmn);
        while (userAgree())
        {
            switch (choiceMenu())
            {
            case 0:
                exit(0);
            case 1:
                printf("All Elements are :-\n");
                showElements(ptr, hmn);
                break;
            case 2:
                sortInAssending(ptr, hmn);
                printf("Sorted Elements in Assending Order\n");
                showElements(ptr, hmn);
                break;
            case 3:
                sortInDesending(ptr, hmn);
                printf("Sorted Elements in Desending Order\n");
                showElements(ptr, hmn);
                break;
            case 4:
                printf("Largest Element is : %.2f\n", largestElement(ptr, hmn));
                break;
            case 5:
                printf("Smallest Element is : %.2f\n", smallestElement(ptr, hmn));
                break;
            case 6:
            {
                int index;
                float element;
                printf("Which Number You Want To Search !! Enter That Number :-\n");
                scanf("%f", &element);
                if ((index = searchElement(ptr, hmn, element)) == -1)
                {
                    printf("Element Not Found \n");
                }
                else
                {
                    printf("Element Found at Index : %d \n", index);
                }
            }
            break;
            case 7:
                if (deleteFirst(ptr, &hmn))
                {
                    printf("First Element Deleted Successfully\n");
                }
                else
                {
                    printf("Given Array Size is zero. So, Nothing Deleted\n");
                }
                break;
            case 8:
                if (deleteLast(ptr, &hmn))
                {
                    printf("Last Element Deleted Successfully\n");
                }
                else
                {
                    printf("Given Array Size is zero. So, Nothing Deleted\n");
                }
                break;
            case 9:
            {
                float element;
                printf("Which Element You Want To Delete . Enter That Element :-\n");
                scanf("%f", &element);
                if (deleteParticular(ptr, &hmn, element))
                    printf("Element Deleted Successfully\n");
                else
                    printf("Given Element Not Found. So, Nothing Deleted\n");
            }
            case 10:
                reverse(ptr,hmn);
            break;
            case 11:
                  {
                      int start_index,hmnelements;
                      printf("Enter Index FRom Where You Wnat To Delete Elements :-\n");
                      scanf("%d",&start_index);
                      printf("Enter How Many Elements You Want To Delete :-\n");
                      scanf("%d",&hmnelements);
                      if(deleteMultiple(ptr,&hmn,start_index,hmnelements))
                        printf("Deleted Elements Successfully ..\n");
                      else
                        printf("Error !! Please Check Your Given Arguments Or Info Are Wrong\n");  
                  } 
            break;
            default:
                printf("Invalid choice\n");
            }
        }
        free(ptr);
        getch();
    }
}