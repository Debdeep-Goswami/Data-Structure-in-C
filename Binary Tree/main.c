
/**********************************************
            Binary Tree
***********************************************/

#include <stdio.h>
#include <stdlib.h>

/******** Global declaration of the node structure *********/

typedef struct node
{
    struct node * left;
    int data;
    struct node * right;
}NODE;

/*********************************************************/


/************************ Prototype of the Functions *****************/

NODE* createNode(int);

NODE* insertLeft(NODE*,int);

NODE* insertRight(NODE*,int);


void preorderTraversal(NODE*);

void inorderTraversal(NODE*);

void postorderTraversal(NODE*);


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
