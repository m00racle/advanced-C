#include <stdio.h>
#include <stdlib.h>

// declaring functions

int* maxSubArray(int *A, int A_length);

int main()
{
    // preparing to find max subarray
    int sample1[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    // WARNING: you need to define sample length here because if you pass it to 
    // function maxSubarray and tell it to measure size of it will be shrunk.
    int sample_length = sizeof(sample1)/sizeof(sample1[0]);
    int* results = maxSubArray(sample1, sample_length);
    printf("results 1: ");
    for (int i = 0; i <3; i++){
       printf("%d ", results[i]);
    }
    return 0;
}

int* maxSubArray(int *A, int A_length)
{
    // find the location and max sum of the subarray
    // with A : array as argument

    // declare array for return start, end, max sum of the sub array
    static int max_data[3] = {0, 0, 0};
    int max_sum = 0;
    int sum = 0;
    int start_index = 0;
    int end_index;
    int i = 0;
    // int A_length = sizeof(A) / sizeof(int);
    printf("length of A = %d \n", A_length);

    // for all data in A:
    for ( i = 0; i < A_length; i++) {
        // sum it with the previous sum
        sum = sum + A[i];
        // if the sum is gt max-sum then
        if (sum > max_sum) 
        {
            //  put the sum as max-sum 
            //  put the max-index = i
            max_sum = sum;
            end_index = i + 1;

        // elif teh sum < 0 then
        } else if (sum < 0)
        {
            //  if max sum > stored max sum: put the start, end, max_sum ke max_data
            if (max_sum > max_data[2]){
                max_data[0] = start_index;
                max_data[1] = end_index;
                max_data[2] = max_sum;
            }
            // reset sum to 0
            sum = 0;
            //  start = i
            start_index = i + 1;
        }
        
    }

    // only put the result if the maxsum > max data
    if (max_sum > max_data[2]){
        max_data[0] = start_index;
        max_data[1] = end_index;
        max_data[2] = max_sum;
    }

    return max_data;
}