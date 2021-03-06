/**********************************************
            Insertion Sort
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

/************************ Prototype of the Functions *****************/

void getData(int *,int);

void generateData(int *,int);

void insertion_sort_ascending(int*,int);

void insertion_sort_descending(int*,int);

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

void display(int *a,int no_of_elements)
{
    int i;
    printf("\nThe elements in the array :-\n");
    for(i=0;i<no_of_elements;i++)
        printf("  %d",a[i]);
    printf("\n");
}

void insertion_sort_ascending(int *a,int no_of_elements)
{
    int i,j,key;
    for(i=1;i<no_of_elements;i++)
    {
        key=a[i];
        j=i-1;

        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }

        a[j+1]=key;
    }
}

void insertion_sort_descending(int *a,int no_of_elements)
{
    int i,j,key;
    for(i=1;i<no_of_elements;i++)
    {
        key=a[i];
        j=i-1;

        while(j>=0 && a[j]<key)
        {
            a[j+1]=a[j];
            j--;
        }

        a[j+1]=key;
    }
}



int menu()
{
    int choice=-999;

    printf("\n______________________________________\n");
    printf("\n********* Insertion Sort *************");
    printf("\n______________________________________\n");

    printf("\n List of Choices\n");
    printf("\n Insert Data Manually\t\t\t = 1");
    printf("\n Insert Data Randomly\t\t\t = 2");
    printf("\n Display Data array\t\t\t = 3");
    printf("\n Insertion Sort in Ascending Order\t = 4");
    printf("\n Insertion Sort in Descending Order\t = 5");
    printf("\n Exit\t\t\t\t\t = 0");
    printf("\n\n Enter your Choice = ");
    scanf("%d",&choice);

    system("cls");
    return choice;
}

void run()
{
    int data_array[MAX],no_of_elements,search_element,choice=-999,position;
    while(choice!=0)
    {
        choice=menu();
        switch(choice)
        {
        case 0:
            break;

        case 1:
            printf("\nEnter the number of elements to be inserted manually = ");
            scanf("%d",&no_of_elements);
            getData(data_array,no_of_elements);
            break;

        case 2:
            printf("\nEnter the number of elements to be inserted randomly = ");
            scanf("%d",&no_of_elements);
            generateData(data_array,no_of_elements);
            break;

        case 3:
            display(data_array,no_of_elements);
            break;

        case 4:
            if(no_of_elements>1)
                insertion_sort_ascending(data_array,no_of_elements);
            else if(no_of_elements==1)
                printf("\nArray with Single Element is by default sorted\n");
            else
                printf("\nArray is Empty.. Add some data before sorting\n");
            break;

        case 5:
            if(no_of_elements>1)
                insertion_sort_descending(data_array,no_of_elements);
            else if(no_of_elements==1)
                printf("\nArray with Single Element is by default sorted\n");
            else
                printf("\nArray is Empty.. Add some data before sorting\n");
            break;

        default:
            printf("\nWrong Choice.. Try Again..\n");

        }
    }
}

/***************  End of Function Definitions  ****************/
