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

void SwapElementToNextElement()
{
    int ele,temp;
    printf("\nEnter the element to be swapped ");
    scanf("%d",&ele);
    struct node *ptr;
    for(ptr=head; ptr!=NULL; ptr=ptr->next)
    {
        if(ptr->value==ele)
        {
            if(ptr->next == NULL)
                printf("Element dont have a next element to be swapped\n");
            else
            {
                temp=ptr->next->value;
                ptr->next->value= ptr->value;
                ptr->value= temp;
                break;
            }
        }
    }
}

void SwapNodeToNextNode()
{
    int ele;
    printf("\nEnter element to be swapped ");
    scanf("%d",&ele);
    struct node *ptr,*temp;
    if(head->value==ele)
    {
        if(head->next==NULL)
            printf("Next Node is Null\n");
        else
        {
            temp=head->next->next;
            head->next->next=head;
            head=head->next;
            head->next->next=temp;
        }
    }
    else
    {
        for(ptr=head;ptr->next!=NULL;ptr=ptr->next)
        {
            if(ptr->next->value==ele)
            {
                if(ptr->next->next==NULL)
                    printf("Next Node is Null\n");
                else
                {
                    temp= ptr->next->next->next;
                    ptr->next->next->next= ptr->next;
                    ptr->next=ptr->next->next;
                    ptr->next->next->next= temp;
                    break;
                }
            }
        }
    }
}

int main()
{
    Create();
    Display();
    SwapElementToNextElement();
    Display();
    SwapNodeToNextNode();
    Display();
    return 0;
}

