#include <stdio.h>
#include<windows.h>
void mergeSort(int arr[], int l, int r);
void merge(int leftArray[], int Lsize, int rightArray[], int Rsize, int sortedArray[]);
void printArray(int arr[], int size);

int main()
{
    int size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("\nEnter the elements of array: ");
    for(i = 0; i < size; i++)
    {
        printf("\nElement arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nThe unsorted array:");
    printArray(arr, size);

     LARGE_INTEGER frequency;  // ticks per second
        LARGE_INTEGER start, end; // tick counts
        double elapsedTime;

        // Get frequency of the performance counter
        QueryPerformanceFrequency(&frequency);

        // Record start time
        QueryPerformanceCounter(&start);

        // Run sorting algorithm


    mergeSort(arr, 0, size - 1);

    // Record end time
        QueryPerformanceCounter(&end);

        // Calculate elapsed time in seconds
        elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

        // Convert to microseconds
        double microseconds = elapsedTime * 1e6;

        printf("\nMerge Sort took %.6f seconds (%.2f microseconds).\n", elapsedTime, microseconds);
    

    printf("\nThe sorted array:");
    printArray(arr, size);

    return 0;
}

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("\narr[%d] = %d", i, arr[i]);
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    int leftSize = mid - l + 1;
    int rightSize = r - mid;

    int leftArray[leftSize];
    int rightArray[rightSize];

    // Copy data into left and right arrays
    for (int i = 0; i < leftSize; i++)
        leftArray[i] = arr[l + i];

    for (int i = 0; i < rightSize; i++)
        rightArray[i] = arr[mid + 1 + i];

    // Recursive calls
    mergeSort(leftArray, 0, leftSize - 1);
    mergeSort(rightArray, 0, rightSize - 1);

    // Merge
    merge(leftArray, leftSize, rightArray, rightSize, arr + l);
}

void merge(int leftArray[], int Lsize, int rightArray[], int Rsize, int sortedArray[])
{
    int l = 0, r = 0, i = 0;

    while (l < Lsize && r < Rsize)
    {
        if (leftArray[l] < rightArray[r])
        {
            sortedArray[i++] = leftArray[l++];
        }
        else
        {
            sortedArray[i++] = rightArray[r++];
        }
    }

    while (l < Lsize)
    {
        sortedArray[i++] = leftArray[l++];
    }

    while (r < Rsize)
    {
        sortedArray[i++] = rightArray[r++];
    }
}