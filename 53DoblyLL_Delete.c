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

void DeleteAtEnd()
{
    struct node *ptr,*temp;
    if(head==NULL)
    {
        printf("No element to delete\n");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        for(ptr=head;ptr->next->next!=NULL;ptr=ptr->next);
        temp=ptr->next;
        free(temp);
        ptr->next=NULL;
    }
}

void DeleteAtStart()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("No element to delete\n");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        head->next->prev=NULL;
        temp=head;
        head=head->next;
        free(temp);
    }
}

void DeleteAtPosition(int pos)
{
    if(head==NULL)
    {
        printf("No element to delete\n");
        return;
    }
    else if(pos==1)
    {
        DeleteAtStart();
        return;
    }
    int c;
    struct node *ptr,*temp;
    for(c=2,ptr=head; ptr->next!=NULL; ptr=ptr->next,c++)
    {
        if(c==pos)
        {
            if(ptr->next->next==NULL)
            {
                printf("gg");
                temp=ptr->next;
                ptr->next=NULL;
                free(temp);
                return;
            }
            else
            {
                temp=ptr->next;
                ptr->next->next->prev= ptr;
                ptr->next= ptr->next->next;
                free(temp);
            }
        }
    }
}

int main()
{
    Create();
    Display();
    DisplayReverse();
    //DeleteAtEnd();
    Display();
    DisplayReverse();
    //DeleteAtStart();
    Display();
    DisplayReverse();
    int pos;
    printf("\nEnter the position ");
    scanf("%d",&pos);
    DeleteAtPosition(pos);
    Display();
    DisplayReverse();
    return 0;
}

