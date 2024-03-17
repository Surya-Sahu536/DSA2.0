#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int queue[10];
int n,front, rear;

bool IsEmpty()
{
    if(front==-1 && rear==-1)
        return true;
    return false;
}

bool IsFull()
{
    if(rear==(n-1))
        return true;
    return false;
}

void Enqueue()
{
    if(IsFull())
    {
        printf("Queue is full(OVERFLOW)\n");
        return;
    }
    int ele;
    printf("\nEnter the value to be pushed ");
    scanf("%d",&ele);
    if(IsEmpty())
    {
        front=rear=0;
        queue[rear]=ele;
        return;
    }
    rear++;
    queue[rear]=ele;
}

void Dequeue()
{
    if(IsEmpty())
    {
        printf("queue is empty(UNDERFLOW)\n");
        return;
    }
    if(front==rear)
    {
        printf("The dequeued element is %d",queue[front]);
        front=rear=-1;
        return;
    }
    printf("The dequeued element is %d",queue[front]);
    front++;
}

void Display()
{
    printf("\nElements in the queue are \n");
    if(IsEmpty())
        return;
    for(int i=front;i<=rear;i++)
        printf("%d ",queue[i]);
}

int Peek_Front()
{
    return queue[front];
}

int Peek_Rear()
{
    return queue[rear];
}

int main()
{
    int choice;
    front=rear=-1;
    printf("Enter the size of the queue ");
    scanf("%d",&n);
    do
    {
        printf("\nEnter Choice 1->Enqueue , 2->Dequeue , 3->Peek_Front , 4->Peek_Rear , 5->Display , 6->Exit : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                if(IsEmpty())
                    printf("queue is empty \n");
                else
                    printf("%d",Peek_Front());
                break;
            case 4:
                if(IsEmpty())
                    printf("queue is empty \n");
                else
                    printf("%d",Peek_Rear());
                break;
            case 5:
                Display();
                break;
            case 6:
                break;
            default:
                printf("Wrong Choice\n");
        }
    }while(choice!=6);
    return 0;
}
