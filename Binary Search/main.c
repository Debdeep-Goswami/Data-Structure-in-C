/**********************************************
            Binary Search
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

/************************ Prototype of the Functions *****************/

void getData(int *,int);

void generateData(int *,int);

void sortData(int*,int);

int binary_search(int*,int,int);

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
    printf("\nEnter %d data one by one \n",i);
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

void sortData(int *a,int no_of_elements)
{
    int temp,i,j;
    for(i=0;i<no_of_elements-1;i++)
    {
        for(j=0;j<(no_of_elements-1)-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int binary_search(int *a,int no_of_elements,int search_element)
{
    int i,low=0,mid,high=no_of_elements;
    while(low<=high)
    {
        mid=(low+high)/2;

        if(search_element==a[mid])
            return mid;
        else if(search_element<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return 0;
}

