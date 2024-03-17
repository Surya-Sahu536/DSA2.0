#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack 
{
    int value;
    struct stack *next;
}*top;

bool IsEmpty()
{
    if(top==NULL)
        return true;
    return false;
}


void Push()
{
    struct stack *new = (struct stack*)malloc(sizeof(struct stack));
    printf("\nEnter the value to be pushed ");
    scanf("%d",&(new->value));
    new->next=NULL;
    if(top==NULL)
    {
        top=new;
        return;
    }
    new->next=top;
    top=new;
}

void Pop()
{
    if(IsEmpty())
    {
        printf("stack is empty(UNDERFLOW)\n");
        return;
    }
    struct stack *temp;
    printf("The popped element is %d",top->value);
    temp=top;
    top=top->next;
    free(temp);
}

void Display()
{
    printf("\nElementS in the stack from top to buttom are \n");
    if(top==NULL)
        return;
    struct stack *ptr;
    for(ptr=top;ptr!=NULL;ptr=ptr->next)
        printf("%d ",ptr->value);
}

int Peek()
{
    return top->value;
}

int main()
{
    int choice;
    do
    {
        printf("\nEnter Choice 1->Push , 2->Pop , 3->Peek , 4->Display , 5->Exit : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                Push();
                break;
            case 2:
                Pop();
                break;
            case 3:
                if(IsEmpty())
                    printf("stack is empty \n");
                else
                    printf("%d",Peek());
                break;
            case 4:
                Display();
                break;
            case 5:
                break;
            default:
                printf("Wrong Choice\n");
        }
    }while(choice!=5);
    return 0;
}
