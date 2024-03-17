#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int value;
    struct tree *left,*right;
}*root;

void Create(struct tree *ptr)
{
    char choice='\0',choice2='\0';
    printf("\nEnter the element ");
    scanf("%d",&(ptr->value));
    if(root==NULL)
       root=ptr;
    printf("Do you want a left node for %d (Y/y->YES) ",ptr->value);
    scanf(" %c",&choice);
    if((choice=='Y')||(choice=='y'))
    {
        struct tree *new1= (struct tree*)malloc(sizeof(struct tree));
        ptr->left= new1;
        Create(ptr->left);
        
    }
    printf("Do you want a right node for %d (Y/y->YES) ",ptr->value);
    scanf(" %c",&choice2);
    if((choice2=='Y')||(choice2=='y'))
    {
        struct tree *new2= (struct tree*)malloc(sizeof(struct tree));
        ptr->right = new2;
        Create(ptr->right);
    }
}

void Inorder(struct tree *ptr)
{
    if(ptr->left!=NULL)
        Inorder(ptr->left);
    printf("%d ",ptr->value);
    if(ptr->right!=NULL)
        Inorder(ptr->right);
}

void Preorder(struct tree *ptr)
{
    printf("%d ",ptr->value );
    if(ptr->left!=NULL)
        Preorder(ptr->left);
    if(ptr->right!=NULL)
        Preorder(ptr->right);
}

void Postorder(struct tree *ptr)
{
    if(ptr->left!=NULL)
        Postorder(ptr->left);
    if(ptr->right!=NULL)
        Postorder(ptr->right);
    printf("%d ",ptr->value );
}

int Height(struct tree *ptr)
{
    if(ptr==NULL)
        return 0;
    int lHeight= Height(ptr->left);
    int rHeight = Height(ptr->right);
    if(lHeight>rHeight)
        return ++lHeight;
    return ++rHeight;
}

void CurrentLevel(struct tree *ptr,int level)
{
    if(ptr==NULL)
        return;
    if(level==1)
        printf("%d ",ptr->value);
    else if(level>1)
    {
        CurrentLevel(ptr->left,level-1);
        CurrentLevel(ptr->right,level-1);
    }
}

int LevelOrder(struct tree *ptr)
{
    int height= Height(ptr);
    for(int i=1;i<=height;i++)
        CurrentLevel(ptr,i);
}


void Search(struct tree *ptr,int ele)
{
    if(ptr->value == ele)
        printf("\nElement found");
    if(ptr->left!=NULL)
        Search(ptr->left,ele);
    if(ptr->right!=NULL)
        Search(ptr->right,ele);
}


int main()
{
    root=NULL;
    root= (struct tree*)malloc(sizeof(struct tree));
    Create(root);
    int choice,ele;
    do
    {
        printf("\nEnter Choice 1->Inorder , 2->Preorder , 3->Postorder , 4->LevelOrder , 5->Height , 6->Search , 7->Exit : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                Inorder(root);
                break;
            case 2:
                Preorder(root);
                break;
            case 3:
                Postorder(root);
                break;
            case 4:
                LevelOrder(root);
                break;
            case 5:
                printf("\nHeight is %d ",Height(root));
                break;
            case 6:
                printf("Enter the value to be searched ");
                scanf("%d",&ele);
                Search(root,ele);
                break;
            case 7:
                break;
            default:
                printf("Wrong Choice\n");
        }
    }while(choice!=7);
    
    return 0;
}
