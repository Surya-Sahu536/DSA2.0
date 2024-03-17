#include <stdio.h>
#include <stdbool.h>
int stack[10];
int n,top;

bool IsEmpty()
{
    if(top==-1)
        return true;
    return false;
}

bool IsFull()
{
    if(top==n-1)
        return true;
    else
        return false;
}

void Push()
{
    if(IsFull())
    {
        printf("stack is full(OVERFLOW) ");
        return;
    }
    int ele;
    printf("\nEnter the value to be pushed ");
    scanf("%d",&ele);
    top++;
    stack[top]= ele;
}

void Pop()
{
    if(IsEmpty())
    {
        printf("stack is empty(UNDERFLOW)\n");
        return;
    }
    printf("The popped element is %d",stack[top]);
    top--;
}

void Display()
{
    printf("\nElementS in the stack are \n");
    for(int i=0;i<=top;i++)
        printf("%d ",stack[i]);
}

int Peek()
{
    return stack[top];
}

int main()
{
    int choice;
    top=-1;
    printf("\nEnter the size of the stack(Positive number) ");
    scanf("%d",&n);
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
