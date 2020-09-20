
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

/************************ Used Functions *****************/

//________________________________Insert Functions_________

NODE* insert_begin(NODE *head,int data);

NODE* insert_end(NODE *head,int data);

NODE * insert_after(NODE* head, int after, int data);
//_________________________________________________________

//________________________________Delete Functions_________

NODE* delete_begin(NODE * head);

NODE* delete_end(NODE * head);
//_________________________________________________________

void display_list(NODE *head);

NODE* reverse_list(NODE*);

int len(NODE * head);

NODE* generateRandomList(NODE* head ,int no_of_nodes);

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


NODE* insert_begin(NODE *head,int data)
{
    NODE *newNode=(NODE*)malloc(sizeof(NODE));
    newNode->data=data;
    newNode->link=head;
    head=newNode;
    return head;
}

NODE* insert_end(NODE *head,int data)
{
    NODE *newNode;
    NODE *temp=head;

    if(head==NULL)
        head=insert_begin(head,data);
    else
    {
        while(temp->link!=NULL)
            temp=temp->link;

        newNode=(NODE*)malloc(sizeof(NODE));
        newNode->data=data;
        newNode->link=temp->link;
        temp->link=newNode;
    }
    return head;
}

NODE * insert_after(NODE* head, int after, int data)
{
    NODE *temp=head;
    NODE *newNode=(NODE*)malloc(sizeof(NODE));
    newNode->data=data;

    while(temp->link!=NULL)
    {
        if(temp->data==after)
        {
            newNode->link=temp->link;
            temp->link=newNode;
        }
        temp=temp->link;
    }
    return head;
}

NODE* delete_begin(NODE * head)
{
    NODE *temp=head;
    head=head->link;
    free(temp);
    return head;
}

NODE* delete_end(NODE * head)
{
    NODE *temp=head;
    NODE *temp2=NULL;

    while(temp->link!=NULL)
    {
        temp2=temp;
        temp=temp->link;
    }
    temp2->link=NULL;
    free(temp);

    return head;
}

void display_list(NODE *head)
{
    if(head==NULL)
        printf("\nList is Empty..\n");
    else
    {
        printf("\nList Display\n");
        NODE* temp = head;
        while(temp!=NULL)
        {
            printf("\t%d",temp->data);
            temp=temp->link;
        }
    }
    printf("\n");
}

NODE* reverse_list(NODE* head)
{
    NODE* curr=head;
    NODE *prev=NULL,*next=NULL;

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
        head=prev;
    }
    return head;
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

NODE* generateRandomList(NODE* head,int no_of_nodes)
{
    int i;
    srand(time(0));
    for(i=0;i<no_of_nodes;i++)
        head=insert_end(head,rand()%100);
    return head;
}

void run()
{
    NODE *head=NULL;

    int choice,data;
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
            head=insert_begin(head,data);
            break;

        case 2:
            printf("\nEnter the data = ");
            scanf("%d",&data);
            head=insert_end(head,data);
            break;

        case 3:
            head=delete_begin(head);
            break;

        case 4:
            head=delete_end(head);
            break;

        case 5:
            display_list(head);
            break;

        case 6:
            printf("\nEnter the number of nodes to be inserted randomly = ");
            scanf("%d",&data);
            head=generateRandomList(head,data);
            break;

        case 7:
            head=reverse_list(head);
            break;

        default:
            printf("\nWrong Choice..Try again\n");
        }
    }
}

int menu()
{
    int choice;
    printf("\nList of Choices\n");
    printf("\n Insert at the Begining\t\t = 1");
    printf("\n Insert at the end\t\t = 2");
    printf("\n Delete from the Begining\t = 3");
    printf("\n Delete from the end\t\t = 4");
    printf("\n Display the list\t\t = 5");
    printf("\n Generate Random List\t\t = 6");
    printf("\n Reverse the List\t\t = 7");
    printf("\n Exit\t\t\t\t = 0");
    printf("\n\n Enter your Choice = ");
    scanf("%d",&choice);
    return choice;
}

