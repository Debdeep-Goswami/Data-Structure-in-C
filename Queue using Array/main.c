
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
