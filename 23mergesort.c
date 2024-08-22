#include <stdio.h>

/*Creates left and right sub array and selects shortest element from either array to replace in main array 
Both sub arrays are already shorted in the previous iteration*/
void merge(int arr[], int left, int mid, int right)
{
    int length1= mid-left +1;
    int length2= right-mid;
    int lArr[length1], rArr[length2];
    
    // copies left half elements to left array and right half elements to right array
    for(int i=0; i<length1; i++)
        lArr[i]= arr[left+i];
    for(int j=0; j<length2;j++)
        rArr[j]= arr[mid +1 +j];
        
    int k=0, l=0, m=left;
    while(k<length1 && l<length2)  //iterate both left and right array, places the shorter element from either of the array to main array 
    {
        if(lArr[k] <= rArr[l])
        {
            arr[m]= lArr[k];
            k++;
        }
        else
        {
            arr[m] = rArr[l];
            l++;
        }
        m++;
    }
    while(k<length1)   // copies the remaining elements to main array
    {
        arr[m++]= lArr[k++];
    }
    while(l<length2)
    {
        arr[m++]= rArr[l++];
    }
}

/*divides the array from middle, applies same mergesort function to both left and right sub array to divide again
calls merge function to conqure the divided sub arrays*/
void mergesort(int arr[], int left, int right)
{
    if(left<right)
    {
        int mid= (left+right)/ 2;
        //printf("%dindex%dindex%d\n",left, mid, right);
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
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
     
    mergesort(arr, 0, n-1);
    
    printf("Array After sorting ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    
    return 0;
}
