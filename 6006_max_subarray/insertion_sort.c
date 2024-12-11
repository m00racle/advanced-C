#include <stdio.h>
#include <stdlib.h>

/*
    Insertion sort code
*/

void InsertionSort(int *A, int length);

int main()
{
    int sample[] = {5, 4, 3, 2, 1};
    int length = sizeof(sample) / sizeof(sample[0]);
    printf("before sorting: ");
    for (int i = 0; i < length; i++) printf("%d, ", sample[i]);
    // sorting
    InsertionSort(sample, length);

    printf("\nafter sorting: ");
    for (int i = 0; i < length; i++) printf("%d, ", sample[i]);
    return 0;
}

void InsertionSort(int *A, int length)
{
    /*
        Insertion sort for array of int A

        Parameters:
        A (pointer to array of ints)
        length (int) : length of array A
    */
    int key;
    int i;
    // start from index 1 to length -1
    for (int j = 1; j < length; j++)
    {
        key = A[j];
        // put the A[j] in slot where it is smaller then existing
        // this using while since the starting and the end of loop dynamically changing
        i = j - 1;
        while (i >= 0 && A[i] > key)
        {
            // shift the elements
            A[i + 1] = A[i];
            // increment i
            i--;
        }
        // if the A[i] < key then stop but the index i already shitfe to the left need to normalized to 
        A[i+1] = key;
    }
}