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

void SwapElementToNext()
{
    int ele;
    printf("\nEnter the element to be swapped ");
    scanf("%d",&ele);
    struct node *ptr,*temp;
    //1 3  4
    if(head->value==ele)
    {
        if(head->next==NULL)
            printf("No next element to swap\n");
        else if(head->next->next==NULL)
        {
            head->next->prev=NULL;
            head->prev=head->next;
            head->next->next=head;
            head= head->next;
            head->next->next=NULL;
        }
        else
                {
                    head->next->next->prev= head;
                    head->next->prev= NULL;
                    head->prev= head->next;
                    temp= head->next;
                    head->next= temp->next;
                    temp->next=head;
                    //printf("%dkk%d",temp->value,ptr->value);
                    head=temp;
                    
                }
                return;
        
    }
    else
    {
        for(ptr=head; ptr->next!=NULL; ptr=ptr->next)
        {
            if(ptr->next->value==ele)
            {
                if(ptr->next->next==NULL)
                    printf("No next element to swap\n");
                else if(ptr->next->next->next==NULL)
                {
                    ptr->next->next->prev=ptr;
                    ptr->next->prev=ptr->next->next;
                    temp=ptr->next->next;
                    ptr->next->next->next=ptr->next;
                    ptr->next->next=NULL;
                    ptr->next=temp;
                }
                else
                {
                    ptr->next->next->next->prev= ptr->next;
                    ptr->next->next->prev= ptr;
                    ptr->next->prev= ptr->next->next;
                    temp= ptr->next->next;
                    ptr->next->next=temp->next;
                    temp->next=ptr->next;
                    printf("%dkk%d",temp->value,ptr->value);
                    ptr->next=temp;
                    
                }
                return;
            }
        }
    }
}

int main()
{
    Create();
    Display();
    SwapElementToNext();
    Display();
    DisplayReverse();
    return 0;
}

