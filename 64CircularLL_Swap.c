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
    printf("\nElements in the Linked List are\n");
    if(head!=NULL)
    {
        for(ptr=head; ptr ->next!= head; ptr=ptr->next)
            printf("%d ",ptr->value);
        printf("%d ",ptr->value);
    }
}

void SwapNodeToNextNode()
{
    int ele;
    struct node *ptr,*temp;
    printf("\nEnter the element of node to be swapped ");
    scanf("%d",&ele);
    if(head==NULL || head->next==head)
        return;
    if(head->next->next==head)
    {
        if((head->value==ele) || (head->next->value==ele))
            head=head->next;
        return;
    }
    for(ptr=head;ptr->next!=head;ptr=ptr->next)
    {
        if(ptr->next->value==ele)
        {
            if(ptr->next->next==head)
                head=ptr->next;
            temp=ptr->next->next;
            ptr->next->next= temp->next;
            temp->next=ptr->next;
            ptr->next=temp;
            return;
        }
    }
    if(head->value==ele)
    {
        head=head->next;
        temp=ptr->next->next;
            ptr->next->next= temp->next;
            temp->next=ptr->next;
            ptr->next=temp;
            
    }
}

int main()
{
    Create();
    Display();
    SwapNodeToNextNode();
    Display();
    return 0;
}
