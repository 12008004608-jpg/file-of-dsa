#include <stdio.h>
void bubblesort();
void main()
{
    int arr[5]={-2, 45, 0, 11, -9};
    bubblesort(arr, 5);

    printf("\n The sorted array: ");
     for(int i=0; i<5; i++)
     printf("%d ", arr[i]);
    
}

void bubblesort(int arr[], int arrsize)
{
    //display array contents

    int i , j;
    for(i=0; i<arrsize; i++)
    printf("%d  ", arr[i]);
    // printf("%d  ",arr[0]);
    //   printf("%d  ",arr[1]);
    //  printf("%d  ",arr[2]);
    //  printf("%d  ",arr[3]);
    //   printf("%d  ",arr[4]);

    //bubblesort
 
    printf("%d  %d  ", arr[i]);
    for ( i = 0; i < arrsize; i++)
    {
        
        for(j=0; j<arrsize-i; j++)
        {
            if (arr[j]<arr[j+1] == 0)
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                
            
            }
            printf("\n Step %d: ", j+1);
            for(int k=0; k<arrsize; k++)
            printf("%d ", arr[k]); 
                    
        }
         
      
      
    }

    
    
}