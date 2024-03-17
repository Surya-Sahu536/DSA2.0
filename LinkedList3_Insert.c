#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
}*head;

void Create()
{
    struct node *ptr,*temp;
    int n,num;
    printf("Enter the number of nodes ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        temp= (struct node*)malloc(sizeof(struct node));
        printf("Enter value ");
        scanf("%d",&num);
        temp->value= num;
        temp->next = NULL;
        if(i==1)
            head= temp;
        else
            ptr->next= temp;
        ptr=temp;
    }
}

void Display()
{
    struct node *ptr;
    printf("\nElements in the Linked List are\n");
    for(ptr=head; ptr != NULL; ptr=ptr->next)
        printf("%d ",ptr->value);
}

void InsertAtBegin()
{
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    printf("\nEnter value to be inserted at start ");
    scanf("%d",&(temp->value));
    temp->next=head;
    head=temp;
}

void InsertAtEnd()
{
    struct node *ptr,*temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter value to be inserted at end ");
    scanf("%d",&(temp->value));
    temp->next = NULL;
    if(head==NULL)
        head= temp;
    else
        for(ptr=head; ptr!=NULL;ptr=ptr->next)
            if(ptr->next == NULL)
            {
                ptr->next= temp;
                break;
            }    
}

void InsertAfterAnElement()
{
    int num;
    printf("\nEnter the number after which new node to be inserted ");
    scanf("%d",&num);
    struct node *ptr,*temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter value to be inserted ");
    scanf("%d",&(temp->value));
    temp->next = NULL;
    for(ptr=head; ptr!=NULL; ptr=ptr->next)
        if(ptr->value==num)
        {
            temp->next= ptr->next;
            ptr->next= temp;
        }
}

void InsertAtPosition(int pos)
{
    if(pos==1)
        InsertAtBegin();
    else
    {
        struct node *ptr,*temp = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter value to be inserted ");
        scanf("%d",&(temp->value));
        int c;
        for(ptr=head,c=2; ptr!=NULL; ptr=ptr->next,c++)
        {
            if(c==pos)
            {
                temp->next = ptr->next;
                ptr->next = temp;
            }
        }
    }
}

int main()
{
    Create();
    Display();
    InsertAtBegin();
    Display();
    InsertAtEnd();
    Display();
    InsertAfterAnElement();
    Display();
    int pos;
    printf("\nEnter the position at which element to be inserted ");
    scanf("%d",&pos);
    InsertAtPosition(pos);
    Display();
    return 0;
}

