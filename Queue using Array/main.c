
/**********************************************
        Queue using Array
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/******** Global variable declarations *********************/

int Front=0;

int Rear=0;

int Queue_Size;

int Queue[MAX];



/*********************************************************/


/************************ Prototype of the Functions *****************/

void enqueue(int);

int dequeue();

void display_queue();

// _____________________ Utility Functions ________________

void run();

int menu();

/********************************************************/

//_________________________ Main Function ________________

int main()
{
    run();
    return 0;
}

// _______________________ END of Main Function __________


/*****************   Function Definitions  ***************/

void enqueue(int data)
{
    if(Rear>=Queue_Size)
        printf("\nQueue is Full\n");
    else
        Queue[Rear++]=data;

}

int dequeue()
{
    int data,i;

    if(Front==Rear)
        return -999;
    else
    {
        data=Queue[Front];
        i=Front;
        while(i<Rear)
        {
            Queue[i]=Queue[i+1];
            i++;
        }
    }
    return data;
}

void display_queue()
{
    int i=Front;
    if(Front==Rear)
        printf("\nQueue is Empty..\n");
    else
        printf("Front -> ");
        while(i<Rear)
            printf("  %d",Queue[i++]);
        printf(" <- Rear\n");

}


int menu()
{
    int choice=-999;

    printf("\n______________________________________\n");
    printf("\n******** Queue using Array **********");
    printf("\n______________________________________\n");

    printf("\n List of Choices\n");
    printf("\n Insert Into the Queue\t= 1\n");
    printf("\n Delete from the Queue\t= 2 \n");
    printf("\n Display Queue\t\t= 3\n");
    printf("\n Exit\t\t\t= 0\n");

    printf("\n\n Enter your choice = ");
    scanf("%d",&choice);

    system("cls");

    return choice;
}
