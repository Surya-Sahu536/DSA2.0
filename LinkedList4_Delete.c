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

void DeleteAtBegin()
{
    if(head==NULL)
        printf("No element available to delete");
    else
    {
        struct node *ele= head;
        head= head->next;
        free(ele);
    }
}

void DeleteAtEnd()
{
    struct node *ele,*ptr;
    if(head==NULL)
        printf("No element available to delete");
    else
    {
        for(ptr=head; ptr->next->next!=NULL;ptr=ptr->next);
        ele= ptr->next;
        free(ele);
        ptr->next= NULL;
    }
}

void DeleteAfterAnElement()
{
    int num;
    printf("\nEnter the number after which node to be deleted ");
    scanf("%d",&num);
    struct node *ele,*ptr;
    for(ptr=head; ptr!=NULL; ptr=ptr->next)
        if(ptr->value==num)
        {
            if(ptr->next!=NULL)
            {
                ele= ptr->next;
                ptr->next= ptr->next->next;
                free(ele);
            }
        }
}

void DeleteAtPosition(int pos)
{
    if(pos==1)
        DeleteAtBegin();
    else
    {
        struct node *ele,*ptr;
        int c;
        for(ptr=head,c=2; ptr!=NULL; ptr=ptr->next,c++)
        {
            if(c==pos)
            {
                ele= ptr->next;
                ptr->next = ptr->next->next;
                free(ele);
            }
        }
    }
}

int main()
{
    Create();
    Display();
    DeleteAtBegin();
    Display();
    DeleteAtEnd();
    Display();
    DeleteAfterAnElement();
    Display();
    int pos;
    printf("\nEnter the position at which element to be deleted ");
    scanf("%d",&pos);
    DeleteAtPosition(pos);
    Display();
    return 0;
}

