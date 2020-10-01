/**********************************************
            Merge Sort
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

int merge(int,int,int);

void merge_sort(int,int);

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

