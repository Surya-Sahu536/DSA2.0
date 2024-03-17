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
    printf("\nElements in the Linked List from end are\n");
    if(head!=NULL)
    {
        for(ptr=head; ptr->next != NULL; ptr=ptr->next);
        for(ptr2=ptr; ptr2!=NULL; ptr2=ptr2->prev)
            printf("%d ",ptr2->value);
    }
}

void Reverse()
{
    if(head==NULL)
        return;
    int temp,i,c=1;
    struct node *ptr,*end;
    for(end=head; end->next!=NULL;end=end->next,c++);
    for(i=1,ptr=head;i<=c/2;i++)
    {
        temp=end->value;
        end->value=ptr->value;
        ptr->value=temp;
        ptr=ptr->next;
        end=end->prev;
    }
}


int main()
{
    Create();
    Display();
    DisplayReverse();
    Reverse();
    Display();
    DisplayReverse();
    return 0;
}
