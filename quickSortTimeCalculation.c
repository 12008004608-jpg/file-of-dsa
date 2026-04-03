#include<stdio.h>
#include<windows.h>
void printArray(int arr[], int size);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);
void main()
{
    int size , i;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    int arr[size];
    printf("\n Enter the elements of the array: ");
    for(i=0; i<size; i++)
    {
        printf("\nElement [%d] : ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n Original array: ");
    printArray(arr, size);

        LARGE_INTEGER frequency;  // ticks per second
        LARGE_INTEGER start, end; // tick counts
        double elapsedTime;

        // Get frequency of the performance counter
        QueryPerformanceFrequency(&frequency);

        // Record start time
        QueryPerformanceCounter(&start);

        // Run sorting algorithm

        quickSort(arr, 0, size-1);

      // Record end time
        QueryPerformanceCounter(&end);

        // Calculate elapsed time in seconds
        elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

        // Convert to microseconds
        double microseconds = elapsedTime * 1e6;

        printf("\nQuick Sort took %.6f seconds (%.2f microseconds).\n", elapsedTime, microseconds);
    
    printf("\n The sorted array: ");
    printArray(arr, size);
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("\n arr[%d]=  %d",i, arr[i]);

    }
}

void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot= arr[high];
    int j=(low-1);
    

    for(int i=low; i< high; i++)
    {
        if(arr[i]<=pivot)
        {
            j++;

            swap(&arr[i],&arr[j]);

        }
    }
    swap(&arr[j+1],&arr[high]);

    return j+1;
}

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}