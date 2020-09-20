
/**********************************************
	Singly Linked List
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/******** Global declaration of the node structure *********/

typedef struct node
{
    int data;
    struct node * link;
}NODE;

/*********************************************************/

/************************ Prototype of the Functions *****************/

//________________________________Insert Functions_________

void insert_begin(NODE **head,int data);

void insert_end(NODE **head,int data);

void insert_after(NODE **head, int after, int data);
//_________________________________________________________

//________________________________Delete Functions_________

void delete_begin(NODE ** head);

void delete_end(NODE ** head);
//_________________________________________________________


// _____________________ Utility Functions ________________

void display_list(NODE *head);

void reverse_list(NODE **);

int len(NODE * head);

void generateRandomList(NODE ** head ,int no_of_nodes);

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

void insert_begin(NODE **head,int data)
{
    NODE *newNode=(NODE*)malloc(sizeof(NODE));
    newNode->data=data;
    newNode->link=*head;
    *head=newNode;
}

void insert_end(NODE **head,int data)
{
    NODE *newNode;
    NODE *temp=*head;

    if(*head==NULL)
        insert_begin(&(*head),data);
    else
    {
        while(temp->link!=NULL)
            temp=temp->link;

        newNode=(NODE*)malloc(sizeof(NODE));
        newNode->data=data;
        newNode->link=temp->link;
        temp->link=newNode;
    }
}

void insert_after(NODE **head, int after, int data)
{
    NODE *temp=*head;
    NODE *newNode=(NODE*)malloc(sizeof(NODE));
    if(*head==NULL)
    {
        printf("\nList is Empty, data Inserted as the first node of the list\n");
        insert_begin(&(*head),data);
    }
    else if(temp->data==after)
            insert_end(&(*head),data);
    else
    {
        newNode->data=data;
        while(temp->link!=NULL)
        {
            if(temp->data==after)
            {
                newNode->link=temp->link;
                temp->link=newNode;
                return;
            }
            temp=temp->link;
        }
        printf("\n Target node not found, data inserted at the end of the list\n");
        insert_end(&(*head),data);
    }

    return head;
}

void delete_begin(NODE ** head)
{
    NODE *temp=*head;
    *head=(*head)->link;
    free(temp);
    //return head;
}

void delete_end(NODE ** head)
{
    NODE *temp=*head;
    NODE *temp2=NULL;
    if(temp->link==NULL)
        delete_begin(&(*head));
    else
    {
        while(temp->link!=NULL)
        {
            temp2=temp;
            temp=temp->link;
        }
        temp2->link=NULL;
        free(temp);
    }
}

void display_list(NODE *head)
{
    NODE* temp = head;

    if(temp==NULL)
        printf("\nList is Empty..\n");
    else
    {
        printf("\nList Display\n");
        while(temp!=NULL)
        {
            printf("\t%d",temp->data);
            temp=temp->link;
        }
    }
    printf("\n");
}

void reverse_list(NODE ** head)
{
    NODE *curr = *head;
    NODE *prev = NULL,*next = NULL;

    if(curr==NULL);
    else
    {
        while(curr!=NULL)
        {
            next=curr->link;
            curr->link=prev;
            prev=curr;
            curr=next;
        }
    }
    *head=prev;
}

int len(NODE * head)
{
    int counter=0;
    NODE* temp = head;
    while(temp!=NULL)
    {
        counter++;
        temp=temp->link;
    }
    return counter;
}

void generateRandomList(NODE ** head,int no_of_nodes)
{
    int i;
    srand(time(0));
    for(i=0;i<no_of_nodes;i++)
        insert_end(&(*head),rand()%100);
}

int menu()
{
    int choice;
    printf("\nList of Choices\n");
    printf("\n Insert at the Begining\t\t = 1");
    printf("\n Insert at the end\t\t = 2");
    printf("\n Insert after \t\t\t = 3");
    printf("\n Delete from the Begining\t = 4");
    printf("\n Delete from the end\t\t = 5");
    printf("\n Display the list\t\t = 6");
    printf("\n Generate Random List\t\t = 7");
    printf("\n Reverse the List\t\t = 8");
    printf("\n Length of the List\t\t = 9");
    printf("\n Exit\t\t\t\t = 0");
    printf("\n\n Enter your Choice = ");
    scanf("%d",&choice);

    system("cls");
    return choice;
}


void run()
{
    NODE *head=NULL;

    int choice,data,after;
    printf("\nWelcome to the program of Linked List\n");

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
            insert_begin(&head,data);
            break;

        case 2:
            printf("\nEnter the data = ");
            scanf("%d",&data);
            insert_end(&head,data);
            break;

        case 3:

            printf("\nEnter the value of the target node = ");
            scanf("%d",&after);
            printf("\nEnter the data to be inserted = ");
            scanf("%d",&data);
            insert_after(&head,after,data);
            break;

        case 4:
            if(head!=NULL)
                delete_begin(&head);
            else
                display_list(head);
            break;

        case 5:
            if(head!=NULL)
                delete_end(&head);
            else
                display_list(head);
            break;

        case 6:
            display_list(head);
            break;

        case 7:
            printf("\nEnter the number of nodes to be inserted randomly = ");
            scanf("%d",&data);
            generateRandomList(&head,data);
            break;

        case 8:
            reverse_list(&head);
            break;

        case 9:
            data=len(head);
            printf("\n Length of the List is %d\n",data);
            break;

        default:
            printf("\nWrong Choice..Try again\n");
        }
    }
}

/***************  End of Function Definitions  ****************/
