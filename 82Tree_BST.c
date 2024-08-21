#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int value;
    struct tree *left,*right;
}*root;

void InsertElement(struct tree *ptr,int ele)
{
    if(ele < ptr->value)
    {
        printf("a%da",ptr->value);
        if(ptr->left==NULL)
        {
            struct tree *newnode = (struct tree*)malloc(sizeof(struct tree));
            newnode->value=ele;
            newnode->left=NULL;
            newnode->right=NULL;
            ptr->left=newnode;
            return;
        }
        InsertElement(ptr->left,ele);
        
    }
    else
    {
        printf("b%db",ptr->value);
        if(ptr->right==NULL)
        {
            
            struct tree *newnode = (struct tree*)malloc(sizeof(struct tree));
            newnode->value=ele;
            newnode->left=NULL;
            newnode->right=NULL;
            ptr->right=newnode;
            return;
        }
        InsertElement(ptr->right,ele);
        
    }
}

void Insert()
{
    int ele;
    printf("Enter the Element to be inserted ");
    scanf("%d",&ele);
    if(root==NULL)
    {
        struct tree *newnode= (struct tree*)malloc(sizeof(struct tree));
        newnode->value=ele;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
        return;
    }    
    InsertElement(root,ele);
}

//Insert Without Recursion
void Insert2()
{
    int ele;
    printf("Enter the Element to be inserted ");
    scanf("%d",&ele);
    struct tree *ptr,*newnode= (struct tree*)malloc(sizeof(struct tree));
    newnode->value=ele;
    newnode->left=NULL;
    newnode->right=NULL;
    ptr=root;
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    while(1)
    {
        if(ele < ptr->value)
        {
            if(ptr->left==NULL)
            {
                ptr->left=newnode;
                return;
            }
            ptr=ptr->left;
            continue;
        }
        else
        {
            if(ptr->right==NULL)
            {
                ptr->right= newnode;
                return;
            }
            ptr=ptr->right;
        }
    }
}

int GetMinValue(struct tree *ptr)
{
    while(1)
    {
        if(ptr->left==NULL)
            return ptr->value;
        ptr=ptr->left;
    }
}

struct tree* GetMinParent(struct tree *ptr)
{
    while(1)
    {
        if(ptr->left->left==NULL)
            break;
        ptr=ptr->left;
    }
    return ptr;
}

void DeleteElement(struct tree *ptr,int ele)
{
    struct tree *delete,*parent,*temp;
    while(ptr->left!=NULL || ptr->right!=NULL)
    {
        if(ele < ptr->value)
        {
            if(ele==ptr->left->value)
            {
                delete=ptr->left;
                if(delete->right ==NULL)
                    ptr->left= ptr->left->left;
                else if(delete->left ==NULL && delete->right!=NULL)
                    ptr->left=ptr->left->right;
                else
                {
                    if(delete->right->left==NULL)
                    {
                        delete->right->left= ptr->left->left;
                        ptr->left= ptr->left->right;
                    }
                    else
                    {
                        parent= GetMinParent(delete->right);
                        temp= parent->left;
                        parent->left= parent->left->right;
                        temp->right= delete->right;
                        temp->left= delete->left;
                        ptr->left= temp;
                    }
                }
                free(delete);
                return;
            }
            ptr=ptr->left;
        }
        else
        {
            if(ele==ptr->right->value)
            {
                delete=ptr->right;
                if(delete->right ==NULL)
                    ptr->right= ptr->right->left;
                else if(delete->left ==NULL && delete->right!=NULL)
                    ptr->right= ptr->right->right;
                else
                {
                    if(delete->right->left==NULL)
                    {
                        delete->right->left= ptr->right->left;
                        ptr->right= ptr->right->right;
                    }
                    else
                    {
                        parent= GetMinParent(delete->right);
                        temp=parent->left;
                        parent->left=parent->left->right;
                        temp->right=delete->right;
                        temp->left= delete->left;
                        ptr->right=temp;
                    }
                }
                free(delete);
                return;
            }
            ptr=ptr->right;
        }
    }
}

void Delete()
{
    if(root==NULL)
    {
        printf("tree has no element");
        return;
    }
    int ele;
    struct tree *delete,*parent,*temp,*ptr=root;
    printf("Enter the element to be deleted ");
    scanf("%d",&ele);
    if(ptr->value==ele) //root
    {
        delete=ptr;
        if(root->right ==NULL)
            root= root->left;
        else if(root->left ==NULL && root->right!=NULL)
            root=root->right;
        else
        {
            if(root->right->left==NULL)
            {
                root->right->left= root->left;
                root= root->right;
            }
            else
            {
                parent= GetMinParent(delete->right);
                temp=parent->left;
                parent->left=parent->left->right;
                temp->right=root->right;
                temp->left= root->left;
                root=temp;
            }
        }
        free(delete);
        return;
    }
    DeleteElement(root,ele);
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
    while(ptr!=NULL)
    {
        if(ptr->value== ele)
        {
            printf("Element found");
            return;
        }
        else if(ele < ptr->value)
            ptr=ptr->left;
        else
            ptr=ptr->right;
    }
    printf("Element not found");
}


int main()
{
    root=NULL;
    int choice,ele;
    do
    {
        printf("\nEnter Choice 1->Insert, 2->Delete,  3->Inorder, 4->Preorder, 5->Postorder, 6->LevelOrder, 7->Height, 8->Search, 9->MinimumValue 0->Exit : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                Insert2();
                break;
            case 2:
                Delete();
                break;
            case 3:
                if(root!=NULL)
                    Inorder(root);
                break;
            case 4:
                if(root!=NULL)
                    Preorder(root);
                break;
            case 5:
                if(root!=NULL)
                    Postorder(root);
                break;
            case 6:
                if(root!=NULL)
                    LevelOrder(root);
                break;
            case 7:
                if(root!=NULL)
                    printf("\nHeight is %d ",Height(root));
                break;
            case 8:
                if(root!=NULL)
                {
                    printf("Enter the value to be searched ");
                    scanf("%d",&ele);
                    Search(root,ele);
                }
                break;
            case 9:
                if(root==NULL)
                {
                    printf("no element in tree \n");
                }
                else
                    printf("%d",GetMinValue(root));
                break;
            case 0:
                break;
            default:
                printf("Wrong Choice\n");
        }
    }while(choice!=0);
    
    return 0;
}