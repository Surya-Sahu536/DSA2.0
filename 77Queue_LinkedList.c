#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue
{
    int value;
    struct queue *next;
}*front,*rear;

bool IsEmpty()
{
    if(front==NULL)
        return true;
    return false;
}

void Enqueue()
{
    struct queue *new= (struct queue*)malloc(sizeof(struct queue));
    printf("\nEnter the value to be pushed ");
    scanf("%d",&(new->value));
    new->next=NULL;
    if(IsEmpty())
    {
        front=rear=new;
        return;
    }
    rear->next=new;
    rear=new;
}

void Dequeue()
{
    if(IsEmpty())
    {
        printf("queue is empty(UNDERFLOW)\n");
        return;
    }
    struct queue *temp;
    if(front==rear)
    {
        printf("The dequeued element is %d",front->value);
        temp=front;
        front=rear=NULL;
        free(temp);
        return;
    }
    temp=front;
    printf("The dequeued element is %d",front->value);
    front=front->next;
    free(temp);
}

void Display()
{
    printf("\nElements in the queue are \n");
    if(IsEmpty())
        return;
    struct queue *ptr;
    for(ptr=front;ptr!=NULL;ptr=ptr->next)
        printf("%d ",ptr->value);
}

int Peek_Front()
{
    return front->value;
}

int Peek_Rear()
{
    return rear->value;
}

int main()
{
    int choice;
    front=rear=NULL;
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
