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

//_______________________ Necessary Functions for Merge Sort ________

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
    if(No_of_elements==0)
        printf("\nArray is empty\n");
    else
    {
        printf("\nThe elements in the array :-\n");
        for(i=0;i<No_of_elements;i++)
            printf("  %d",Data_array[i]);
    }
    printf("\n");
}


int merge(int low,int mid,int high)
{
    int i,j,k;
    int temp_Data_array[MAX];

    for(i=low,j=mid+1,k=low ; i<=mid && j<=high ; k++)
    {
        //      Merging from both the part
        if(Data_array[i]<=Data_array[j])
            temp_Data_array[k]=Data_array[i++];
        else
            temp_Data_array[k]=Data_array[j++];
    }

    //      Copy of the data left in any of the part
    while(i<=mid)
        temp_Data_array[k++]=Data_array[i++];

    while(j<=high)
        temp_Data_array[k++]=Data_array[j++];

    //      Copy back the merged data into the original array
    for(k=low;k<=high;k++)
        Data_array[k]=temp_Data_array[k];
}

void merge_sort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;

        merge_sort(low,mid);
        merge_sort(mid+1,high);

        merge(low,mid,high);
    }
}
int menu()
{
    int choice=-999;

    printf("\n______________________________________\n");
    printf("\n***********  Merge Sort  *************");
    printf("\n______________________________________\n");

    printf("\n List of Choices\n");
    printf("\n Insert Data Manually\t = 1");
    printf("\n Insert Data Randomly\t = 2");
    printf("\n Display Data array\t = 3");
    printf("\n Merge Sort\t\t = 4");
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
            merge_sort(0,No_of_elements-1);
            break;

        default:
            printf("\nWrong Choice.. Try Again..\n");

        }
    }
}

/***************  End of Function Definitions  ****************/
