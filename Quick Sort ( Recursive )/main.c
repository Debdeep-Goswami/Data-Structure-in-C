/**********************************************
            Bubble Sort
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100


/******************  Global declarations  ***************/

int Data_array[MAX];

int No_of_elements;

/*********************************************************/

/************************ Prototype of the Functions *****************/

void getData();

void generateData();

void display();

//_______________________ Necessary Functions for Quick Sort ________

int partition(int,int);

void quick_sort(int,int);

void swap(int,int);

/*********************************************************************/


// _____________________ Utility Functions ________________

int menu();

void run();

/********************************************************/

//________________________ Main Function ________________

int main()
{
    run();
    return 0;
}

//__________________END of Main Function ________________


/*****************   Function Definitions  ***************/

void getData()
{
    int i;
    printf("\nEnter %d data one by one \n",No_of_elements);
    for(i=0;i<No_of_elements;i++)
    {
        printf("\nEnter data number %d = ",i+1);
        scanf("%d",&Data_array[i]);
    }
}

void generateData()
{
    int i;
    srand(time(0));
    for(i=0;i<No_of_elements;i++)
        Data_array[i]=rand()%100;
}

void display()
{
    int i;
    printf("\nThe elements in the array :-\n");
    for(i=0;i<No_of_elements;i++)
        printf("  %d",Data_array[i]);
    printf("\n");
}


int partition(int low,int high)
{
    int pivot=Data_array[low];
    int i=low,j=high;
    while(i<j)
    {
        while(Data_array[i]<=pivot)
            i++;
        while(Data_array[j]>pivot)
            j--;

        if(i<j)
            swap(i,j);
    }
    swap(low,j);
    return j;
}

void quick_sort(int low,int high)
{
    int j;
    if(low<high)
    {
        j=partition(low,high);
        quick_sort(low,j);
        quick_sort(j+1,high);
    }
}

void swap(int i,int j)
{
    int temp=Data_array[i];
    Data_array[i]=Data_array[j];
    Data_array[j]=temp;
}

int menu()
{
    int choice=-999;

    printf("\n______________________________________\n");
    printf("\n***********  Quick Sort  *************");
    printf("\n______________________________________\n");

    printf("\n List of Choices\n");
    printf("\n Insert Data Manually\t = 1");
    printf("\n Insert Data Randomly\t = 2");
    printf("\n Display Data array\t = 3");
    printf("\n Quick Sort\t\t = 4");
    printf("\n Exit\t\t\t = 0");
    printf("\n\n Enter your Choice = ");
    scanf("%d",&choice);

    system("cls");
    return choice;
}

void run()
{
    int choice=-999;
    while(choice!=0)
    {
        choice=menu();
        switch(choice)
        {
        case 0:
            break;

        case 1:
            printf("\nEnter the number of elements to be inserted manually = ");
            scanf("%d",&No_of_elements);
            getData();
            break;

        case 2:
            printf("\nEnter the number of elements to be inserted randomly = ");
            scanf("%d",&No_of_elements);
            generateData();
            break;

        case 3:
            display();
            break;

        case 4:
            quick_sort(0,No_of_elements);
            break;

        default:
            printf("\nWrong Choice.. Try Again..\n");

        }
    }
}

/***************  End of Function Definitions  ****************/
