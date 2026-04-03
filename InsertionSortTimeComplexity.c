#include<stdio.h>
#include<windows.h>
void printarray(int arr[], int arrsize);
void insertionSort(int arr[], int arrsize);
void main()
{
    int arrsize, i;
    printf("Enter size of the array: ");
    scanf("%d", &arrsize);

    printf("\n Enter the elements of array: ");
    int arr[arrsize];
    for(i=0; i < arrsize;i++)
    {
        printf("\n Element%d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nThe unsorted array: ");
    printarray(arr,arrsize);

        LARGE_INTEGER frequency;  // ticks per second
        LARGE_INTEGER start, end; // tick counts
        double elapsedTime;

        // Get frequency of the performance counter
        QueryPerformanceFrequency(&frequency);

        // Record start time
        QueryPerformanceCounter(&start);

        // Run sorting algorithm


        insertionSort(arr, arrsize);

        // Record end time
        QueryPerformanceCounter(&end);

        // Calculate elapsed time in seconds
        elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

        // Convert to microseconds
        double microseconds = elapsedTime * 1e6;

        printf("\nInsertion Sort took %.6f seconds (%.2f microseconds).\n", elapsedTime, microseconds);


    printf("\n The sorted array: ");
    printarray(arr,arrsize);
    
}

void printarray(int arr[], int arrsize)
{
    int i;
    for(i=0; i<arrsize; i++)
    printf("%d ",arr[i]);
}

void insertionSort(int arr[], int arrsize)
{
    int i, key,j;
   // printf("insertionSort");

    for(i=1; i<arrsize; i++)
    {
        key=arr[i];
        j=i-1;
        while (key<arr[j] && j>=0)
        {
           arr[j+1]= arr[j] ;
           j-- ;
        }
        arr[j+1]=key;
        

    }
}