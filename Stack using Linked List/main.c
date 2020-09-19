
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

NODE *head=NULL; //  This will work as the top of the stack

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

void run()
{
    int choice,data;
    printf("\nWelcome to Stack operation program using Linked List\n");

    while(choice!=0)
    {
        choice=menu();
        switch(choice)
        {
        case 0:
            break;

        case 1:
            printf("\nEnter the data = ");
            scanf("%d",&data);
            push(data);
            break;

        case 2:
            data=pop();
            if(data==-999);
            else
                printf("\nItem popped = %d\n",data);
            break;

        case 3:
            //data=showTop();
            if(data==-999)
                printf("\nStack is Empty\n");
            else
                printf("\nItem at the top is = %d\n",data);
            break;

        case 4:
            //display_stack();
            break;

        default:
            printf("\nWrong Choice..Try again\n");
        }
    }
    return 0;
}

int menu()
{
    int choice;
    printf("\nList of Choices\n");
    printf("\n Push\t\t\t= 1\n");
    printf("\n Pop\t\t\t= 2 \n");
    printf("\n Show Top\t\t= 3\n");
    printf("\n Display Stack\t\t= 4\n");
    printf("\n Exit\t\t\t= 0\n");
    printf("\nEnter your choice = ");
    scanf("%d",&choice);
    return choice;
}

void push(int data)
{
    NODE *newNode=(NODE*)malloc(sizeof(NODE));
    if(newNode==NULL)
        printf("\nOverflow\n");
    else
    {
        newNode->data=data;
        newNode->link=head;
        head=newNode;
    }
}

int pop()
{
    int data=-999;
    NODE* temp=head;
    if(temp==NULL)
        printf("\nUnderflow\n");
    else
    {
        data=temp->data;
        head=head->link;
        free(temp);
    }
    return data;
}
