#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
};


int main()
{
    struct node *head,*ptr,*temp;
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
    
    for(ptr=head; ptr != NULL; ptr=ptr->next)
        printf("%d ",ptr->value);
    return 0;
}