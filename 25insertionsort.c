#include <stdio.h>
#include <stdbool.h>

/*starts assigning key from the 2nd element and checks all element in left if greater than key then shift them to the right index, then place the key in its position in the sorted left array*/
void insertionsort(int arr[], int n)
{
    for(int i=1; i<n; i++) // starting from 2nd element as we need to compare only left elements and 1st element has nothing on left
    {
        int key=arr[i];
        int j;
        for(j=i-1; j>=0;j--)
        {
            if(arr[j]>key)        // if element is greater than key shift one index right
                arr[j+1]= arr[j];
            else
                break;
        }
        arr[j+1]= key;
    }
}

int main()
{
    int arr[]={31, 5, 3, 4, 67, 12, 300, 89};
    int n;
    n= sizeof(arr) / sizeof(arr[0]);
    
    printf("Array before  ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
     
    insertionsort(arr, n);
    
    printf("Array After sorting ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    
    return 0;
}
