#include <stdio.h>
#include <stdbool.h>

/*check element with next element if greater then swap, by this way the largest element is stored on last*/
void bubblesort(int arr[], int n)
{
    bool swapped= false;
    for(int i=1; i<n; i++)  // will iterate one time less because last one remaining element would be already sorted
    {
        swapped=false;
        for(int j=0; j<n-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp= arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped= true;
            }
        }
        if(swapped== false)  // if nothing is getting swapped the the array is already sorted
            break;
    }
}

int main()
{
    int arr[]={13, 45, 56, 400, 11, 7, 45, 95, 78, 90};
    int n;
    n= sizeof(arr) / sizeof(arr[0]);
    
    printf("Array before  ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
     
    bubblesort(arr, n);
    
    printf("Array After sorting ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    
    return 0;
}
