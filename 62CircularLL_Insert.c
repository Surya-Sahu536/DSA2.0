#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
}*head;

void Create()
{
    struct node *ptr,*new;
    int n,num;
    printf("Enter the number of nodes ");
    scanf("%d",&n);
    if(n==0)
        return;
    for(int i=1;i<=n;i++)
    {
        new= (struct node*)malloc(sizeof(struct node));
        printf("Enter value ");
        scanf("%d",&num);
        new->value= num;
        new->next = NULL;
        if(i==1)
            head= new;
        else
            ptr->next= new;
        ptr=new;
    }
    ptr->next=head;
}

void Display()
{
    struct node *ptr;
    if(head!=NULL)
    {
        printf("\nElements in the Linked List are\n");
        for(ptr=head; ptr ->next!= head; ptr=ptr->next)
            printf("%d ",ptr->value);
        printf("%d ",ptr->value);
    }
}

void InsertAtEnd()
{
    struct node *ptr,*new;
    new= (struct node*)malloc(sizeof(struct node));
    printf("\nEnter element to be inserted at end ");
    scanf("%d", &(new->value));
    new->next=NULL;
    if(head==NULL)
    {
        head=new;
        head->next=head;
        return;
    }
    for(ptr=head; ptr->next!=head; ptr=ptr->next);
    ptr->next=new;
    new->next=head;
}

void InsertAtStart()
{
    struct node *ptr,*new;
    new= (struct node*)malloc(sizeof(struct node));
    printf("\nEnter element to be inserted at start ");
    scanf("%d", &(new->value));
    new->next=NULL;
    if(head==NULL)
    {
        head=new;
        head->next=head;
        return;
    }
    for(ptr=head; ptr->next!=head; ptr=ptr->next);
    ptr->next=new;
    new->next=head;
    head=new;
}

void InsertAtPosition(int pos)
{
    int c=2;
    if(pos==1)
    {
        InsertAtStart();
        return;
    }
    struct node *ptr,*new;
    new= (struct node*)malloc(sizeof(struct node));
    printf("\nEnter element to be inserted at start ");
    scanf("%d", &(new->value));
    for(ptr=head; ptr->next!=head; ptr=ptr->next,c++)
    {
        if(pos==c)
        {
            new->next=ptr->next;
            ptr->next=new;
            return;
        }
    }
    if(pos==c)
    {
        ptr->next=new;
        new->next=head;
    }
}


int main()
{
    Create();
    Display();
    InsertAtEnd();
    Display();
    InsertAtStart();
    Display();
    printf("\nEnter Position ");
    int pos;
    scanf("%d",&pos);
    InsertAtPosition(pos);
    Display();
    return 0;
}
