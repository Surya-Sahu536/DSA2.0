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
    printf("Elements in the Linked List are\n");
    for(ptr=head; ptr != NULL; ptr=ptr->next)
        printf("%d ",ptr->value);
}

int main()
{
    Create();
    Display();
    return 0;
}

