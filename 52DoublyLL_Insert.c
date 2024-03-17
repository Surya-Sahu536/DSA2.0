#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *prev;
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
        temp->prev = NULL;
        if(i==1)
            head= temp;
        else
        {
            temp->prev= ptr; 
            ptr->next= temp;
        }
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

void DisplayReverse()
{
    struct node *ptr,*ptr2;
    printf("\nElements in the Linked List are\n");
    if(head!=NULL)
    {
        for(ptr=head; ptr->next != NULL; ptr=ptr->next);
        for(ptr2=ptr; ptr2!=NULL; ptr2=ptr2->prev)
        printf("%d ",ptr2->value);
    }
}

void InsertAtEnd()
{
    struct node *ptr,*new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter element to insert at end ");
    scanf("%d",&(new->value));
    new->next= NULL;
    if(head==NULL)
    {
        new->prev= NULL;
        head= new;
    }
    else
    {
        for(ptr=head;ptr->next!=NULL;ptr=ptr->next);
        ptr->next=new;
        new->prev= ptr;
    }
}

void InsertAtStart()
{
    struct node *ptr,*new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter element to insert at start ");
    scanf("%d",&(new->value));
    new->prev= NULL;
    if(head==NULL)
    {
        new->next=NULL;
        head= new;
    }
    else
    {
        new->next= head;
        head->prev= new;
        head=new;
    }
}

void InsertAtPosition(int pos)
{
    if(pos==1)
    {
        InsertAtStart();
        return;
    }
    int c;
    struct node *ptr,*new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter element to insert ");
    scanf("%d",&(new->value));
    new->next=NULL;
    new->prev= NULL;
    for(c=2,ptr=head; ptr!=NULL; ptr=ptr->next,c++)
    {
        if(c==pos)
        {
            if(ptr->next!=NULL)
            {
                ptr->next->prev=new;
                new->next=ptr->next;
                ptr->next=new;
                new->prev=ptr;
            }
            else
            {
                ptr->next=new;
                new->prev=ptr;
            }
        }
    }
}

int main()
{
    Create();
    Display();
    DisplayReverse();
    InsertAtEnd();
    Display();
    DisplayReverse();
    InsertAtStart();
    Display();
    DisplayReverse();
    int pos;
    printf("\nEnter the position ");
    scanf("%d",&pos);
    InsertAtPosition(pos);
    Display();
    DisplayReverse();
    return 0;
}

