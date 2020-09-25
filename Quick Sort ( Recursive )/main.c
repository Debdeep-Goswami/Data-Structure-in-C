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

