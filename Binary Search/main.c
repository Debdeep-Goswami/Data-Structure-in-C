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
    int low=0,mid,high=no_of_elements;
    while(low<=high)
    {
        mid=(low+high)/2;

        if(search_element==a[mid])
            return mid+1;
        else if(search_element<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

void display(int *a,int no_of_elements)
{
    int i;
    printf("\nThe elements in the array :-\n");
    for(i=0;i<no_of_elements;i++)
        printf("  %d",a[i]);
    printf("\n");
}

int menu()
{
    int choice=-999;

    printf("\n______________________________________\n");
    printf("\n********* Binary Search **************");
    printf("\n______________________________________\n");

    printf("\n List of Choices\n");
    printf("\n Insert Data Manually\t = 1");
    printf("\n Insert Data Randomly\t = 2");
    printf("\n Display Data array\t = 3");
    printf("\n Search Element\t\t = 4");
    printf("\n Exit\t\t\t = 0");
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
            sortData(data_array,no_of_elements);
            break;

        case 2:
            printf("\nEnter the number of elements to be inserted randomly = ");
            scanf("%d",&no_of_elements);
            generateData(data_array,no_of_elements);
            sortData(data_array,no_of_elements);
            break;

        case 3:
            display(data_array,no_of_elements);
            break;

        case 4:
            printf("\nEnter the element to be searched = ");
            scanf("%d",&search_element);
            position=binary_search(data_array,no_of_elements,search_element);
            if(position==-1)
                printf("\n%d Not found inside the array \n",search_element);
            else
                printf("\n%d Found inside the array \n",search_element);
            break;

        default:
            printf("\nWrong Choice.. Try Again..\n");

        }
    }
}

/***************  End of Function Definitions  ****************/

