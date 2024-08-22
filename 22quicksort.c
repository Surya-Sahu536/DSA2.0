/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void swap(int* a, int* b)
{
    int temp= *a;
    *a= *b;
    *b= temp;
}

/*Returns the index where the pivot element should be*/
int PartitionSort(int arr[], int low, int upp)
{
    int pivot= arr[low];
    int i=low;
    int j=upp;
    
    while(i<j)   //runs until the 2 pointers cross each other
    {
        while(arr[i] <= pivot && i<=upp-1)  //from starting finds the index of element greater than pivot
            i++;
        while(arr[j]>= pivot && j >=low+1)  //from last finds the index of element less than pivot
            j--;
        if(i<j)
            swap(&arr[i], &arr[j]);  //if pointers not crossed swap value of both pointers
    }
    swap(&arr[low], &arr[j]);  //j pointer already crossed i pointer, so swap j pointer value with pivot
    return j;
}

/*Divides the array by partitionIndex(index where pivot element shoud be). Apply quicksort to both sub array*/
void quicksort(int arr[], int lowb, int uppb)
{
    if(lowb<uppb)
    {
        int partitionIndex= PartitionSort(arr, lowb, uppb);
        //printf("%dindex%dindex%d\n",lowb, partitionIndex, uppb);
        quicksort(arr, lowb, partitionIndex-1);
        quicksort(arr, partitionIndex+1, uppb);
    }
}

int main()
{
    int arr[]={6, 10, 56, 454, 34, 44, 90, 8, 9, 56, 1};
    int n;
    n= sizeof(arr) / sizeof(arr[0]);
    
    printf("Array before  ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
     
    quicksort(arr, 0, n-1);
    
    printf("Array After sorting ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    
    return 0;
}
