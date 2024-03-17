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
    for(ptr=head; ptr ->next!= head; ptr=ptr->next)
        printf("%d ",ptr->value);
    printf("%d ",ptr->value);
}



int main()
{
    Create();
    Display();
    return 0;
}
