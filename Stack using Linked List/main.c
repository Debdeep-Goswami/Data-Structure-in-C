
/**********************************************
        Stack using Linked List
***********************************************/

#include <stdio.h>
#include <stdlib.h>

/******** Global variable declarations *********************/

typedef struct node
{
    int data;
    struct node * link;
}NODE;

NODE*head=NULL; //  This will work as the top of the stack

/*********************************************************/


/************************ Used Functions *****************/

//--------------------- Necessory for Stack Operation -------

void push(int);

int pop();

int showTop();

// -------------------- Other utility functions --------------

void run();

void display_stack();

int menu();

/********************************************************/

//_________________________ Main Function ________________

int main()
{
    run();
    return 0;
}

// _______________________ END of Main Function __________
