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

void Reverse()
{
    struct node *ptr,*prevnode=NULL,*nextnode=NULL;
    for(ptr=head;ptr!=NULL;ptr=nextnode)
    {
        if(ptr->next==NULL)
        {
            ptr->next= prevnode;
            head= ptr;
            break;
        }
        else
        {
            nextnode= ptr->next;
            ptr->next= prevnode;
            prevnode = ptr;
        }
    }
}


int main()
{
    Create();
    Display();
    Reverse();
    Display();
    return 0;
}

