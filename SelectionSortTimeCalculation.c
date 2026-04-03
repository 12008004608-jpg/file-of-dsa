#include<stdio.h>
#include<windows.h>
void selectionSort(int arr[], int arraysize);
void displayArray(int arr[], int arraysize);
void swap();
void main()
{
    int arraysize, i;
    printf("Enter size of the array: ");
    scanf("%d", &arraysize);

    printf("Enter elements of the array: ");
    int arr[arraysize];
    for(i=0; i<arraysize; i++)
    {
        printf("\n Element %d : ",i);
        scanf("%d",&arr[i]);
    }

    printf("\n Display unsorted array: ");
    displayArray(arr, arraysize);

        LARGE_INTEGER frequency;  // ticks per second
        LARGE_INTEGER start, end; // tick counts
        double elapsedTime;

        // Get frequency of the performance counter
        QueryPerformanceFrequency(&frequency);

        // Record start time
        QueryPerformanceCounter(&start);

        // Run sorting algorithm



    selectionSort(arr, arraysize);

         // Record end time
        QueryPerformanceCounter(&end);

        // Calculate elapsed time in seconds
        elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

        // Convert to microseconds
        double microseconds = elapsedTime * 1e6;

        printf("\nSelection Sort took %.6f seconds (%.2f microseconds).\n", elapsedTime, microseconds);

    printf("\n Display sorted array: ");
    displayArray(arr, arraysize);
    

}//end of main


void displayArray(int arr[], int arraysize)
{
    int i;
    for(i=0; i<arraysize; i++)
    {
        printf("%d ", arr[i]);
    }
}


void selectionSort(int arr[], int arraysize)
{
    int swap_count=0;
    int min_index;
    for(int i=0; i<arraysize; i++)
    {
        min_index=i;
        for(int j=i+1; j<arraysize; j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index=j;
            }
        }
        // int temp= arr[i];
        // (arr[i]= arr[min_index]);
        // arr[min_index]=temp;
        if(i!=min_index)
        {
            swap(&arr[i], &arr[min_index]);
            swap_count++;
        }
        
    }
    printf("\nswap= %d ", swap_count);
}

void swap(int *a, int *b, int temp)
{
    temp=*a;
    *a=*b;
    *b=temp;
}

