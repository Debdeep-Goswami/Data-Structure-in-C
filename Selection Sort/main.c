/**********************************************
            Selection Sort
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

/************************ Prototype of the Functions *****************/

void getData(int *,int);

void generateData(int *,int);

void selection_sort_ascending(int*,int);

void selection_sort_descending(int*,int);

void display(int*,int);

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

void getData(int *a,int no_of_elements)
{
    int i;
    printf("\nEnter %d data one by one \n",no_of_elements);
    for(i=0;i<no_of_elements;i++)
    {
        printf("\nEnter data number %d = ",i+1);
        scanf("%d",&a[i]);
    }
}

void generateData(int *a,int no_of_elements)
{
    int i;
    srand(time(0));
    for(i=0;i<no_of_elements;i++)
        a[i]=rand()%100;
}

void selection_sort_ascending(int *a,int no_of_elements)
{
    int min_index,temp,i,j;
    for(i=0;i<no_of_elements-1;i++)
    {
        min_index=i;

        for(j=i+1;j<no_of_elements;j++)
            if(a[min_index]>a[j])
                min_index=j;

        temp=a[min_index];
        a[min_index]=a[i];
        a[i]=temp;
    }
}

