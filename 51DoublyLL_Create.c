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
    for(ptr=head; ptr->next != NULL; ptr=ptr->next);
    for(ptr2=ptr; ptr2!=NULL; ptr2=ptr2->prev)
        printf("%d ",ptr2->value);
        
}



int main()
{
    Create();
    Display();
    DisplayReverse();
    return 0;
}

