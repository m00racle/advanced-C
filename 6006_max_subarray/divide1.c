#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h> // this is to enable using INT_MAX which will be used to simulate infinity for int
// NOTE: this is because in C there is no infinity for int type and can't be casted from double 

/* this is merge sort */

// declare function Merge return void
void Merge(int* A, int p, int q, int r);
// declare function MergeSort return void
void MergeSort(int* A, int p, int r);
// define main function return int
int main()
{
    // creating static array (You don't need Static array since main function scope last till the run end)
    int sample[] = {5,2,4,7,1,3,-2,6};
    int p = 0;
    int r = sizeof(sample)/sizeof(sample[0]) - 1;
    
    printf("before sorting: ");
    for (int i = p; i <= r; i++)
    {
        // print each element
        printf("%d ", sample[i]);
    }

    // start sorting
    MergeSort(sample, p, r);

    printf("\nafter sorting: ");
    for (int i = p; i <= r; i++)
    {
        // print each element
        printf("%d ", sample[i]);
    }

    return 0;
}

// define Merge
void Merge(int* A, int p, int q, int r)
{
    // creating two new arrays
    int n1 = q - p + 1;
    int n2 = r - q;
    // let there be two left and right sub array
    int L[n1 + 1];
    int R[n2 + 1];
    // put the appropriate values inside each L and R sub array
    for (int i = 0; i < n1; i++)
    {
        // put the values of left sub array
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        // put the values to right sub array
        R[j] = A[q + j + 1];
    }
    // set the last element of left and right sub array
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    // start the merge process by comparing each element from L and R
    // reset the indexes
    int m = 0;
    int n = 0;
    // iterate each element from L and R and compare
    for (int k = p; k <= r; k++)
    {
        if (L[m] <= R[n])
        {
            // put element from L to A at index k
            A[k] = L[m];
            // increment index in L
            m++;
        } else 
        {
            // put element from R to A at index k
            A[k] = R[n];
            // increment index in R
            n++;
        }
    }
}

// define MergeSort?
void MergeSort(int* A, int p, int r)
{
    // if p is still lower than r you need to recursively call MergeSort
    if (p < r)
    {
        // calculate median value q using floor divide
        int q = floor((p + r)/2);
        // recursive steps
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        Merge(A, p, q, r);
    }
}