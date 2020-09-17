
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

int len(NODE * head);

NODE* generateRandomList(NODE* head ,int no_of_nodes);

/********************************************************/

/*________________________ Main Function ________________*/

int main()
{
    run();
    return 0;
}

/*__________________END of Main Function ________________*/


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
    printf("\nInside display function\n");
    NODE* temp = head;
    while(temp!=NULL)
    {
        printf("\t%d",temp->data);
        temp=temp->link;
    }
    printf("\n");
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

void run()
{
    NODE *head=NULL;
    /*
    NODE *n1=(NODE*)malloc(sizeof(NODE));
    n1->data=50;
    n1->link=NULL;
    head=n1;
    head=insert_begin(head,40);
    head=insert_begin(head,30);
    head=insert_begin(head,20);
    head=insert_begin(head,10);
    display_list(head);
    head=insert_end(head,60);
    head=insert_end(head,70);
    head=insert_end(head,80);
    head=insert_end(head,90);
    head=insert_end(head,100);
    display_list(head);
    head=delete_begin(head);
    display_list(head);
    head=delete_end(head);
    display_list(head);
    */
    head=generateRandomList(head,100);
    display_list(head);

    head=delete_begin(head);
    head=delete_end(head);
    display_list(head);
}

NODE* generateRandomList(NODE* head,int no_of_nodes)
{
    int i;
    srand(time(0));
    for(i=0;i<no_of_nodes;i++)
    {
        head=insert_end(head,rand()%100);
    }
    return head;
}
