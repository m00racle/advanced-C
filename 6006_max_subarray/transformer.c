#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// declaring functions

int* maxSubArray(int *A, int A_length);

// declare find max subarray
int* FindMaxSubarray(int* A, int low, int high);

// declaring max-crossing-subarray
int* FindMaxCrossingSubarray(int *A, int low, int mid, int high);

void test_run(int *A, int length, char* test_msg)
{
    /*  
        helper function to test run and print out the results

        Parameters:
            - A (int pointer to array) : the array to maximized
            - length (int) : length of the array
    */

    // select the method to find maximum sub-array
    int *results = FindMaxSubarray(A, 0, length - 1);
    
    // print out the results
    printf("\nTest Run %s results: ", test_msg);
    for (int i = 0; i <3; i++){
       printf("%d ", results[i]);
    }
}

int main()
{
    // preparing to find max subarray
    int sample1[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int sample2[] = {1,2,3,4,5};
    int sample3[] = {-1, -2, -3, -4};
    
    // pass the sample to test run:
    test_run(sample1, sizeof(sample1)/sizeof(sample1[0]), "sample 1");
    test_run(sample2, sizeof(sample2)/sizeof(sample2[0]), "sample 2");
    test_run(sample3, sizeof(sample3)/sizeof(sample3[0]), "sample 3");

    return 0;
}

// define FindMaxSubarray(int* A, int low, int high)
int* FindMaxSubarray(int* A, int low, int high)
{
    /* 
    Find Sub-array that will returns the best results

    Parameters:
    A (Array of int that MUST be static) 
    low (int) = the lowest index the start of the (sub) array
    high (int) = the highest index for the end of the (sub) array
    */

    // define
    static int max_data[3];
    // reset back to zero since max_data is static to ensure clean start for multiple calls.
    // note you can't just use max_data = {0, 0, 0}!
    for (int i = 0; i < 3; i++)
    {
        max_data[i] = 0;
    }

    // initialize other variables:
    int sum = 0;
    int max_sum = 0;
    int start = low; // start index of contiguous sub array
    int end; // end indes of the contiguous sub array
    
    // iterate all array to find max sub array
    for (int i = low; i <= high; i++)
    {
        // addind to the next 
        sum = sum + A[i];

        // only put contagous sub array if the sum is higher 
        if (sum > max_sum)
        {
            // put the max data
            max_sum = sum;
            end = i + 1;
        } else if (sum < 0)
        {
            // meaning there are new lows to be start
            // but first maintain the latest max sum
            if (max_sum > max_data[2])
            {
                // put the data into max_data
                max_data[0] = start;
                max_data[1] = end;
                max_data[2] = max_sum;
            }

            // because it is new low take it as new start
            start = i + 1;
            // reset the sum back to 0
            sum = 0;
        }
    }

    // filter the last result compare to the max data
    if (max_sum > max_data[2])
    {
        // put the data into max_data
        max_data[0] = start;
        max_data[1] = end;
        max_data[2] = max_sum;
    }

    return max_data;
}

// define MaxCrossing function
int* FindMaxCrossingSubarray(int *A, int low, int mid, int high)
{
    /* 
        process max-crossing sub array
        A = array of integers pointer
        low (int) = lowest index in the array A 
        mid (int) = the middle point index in array A
        high (int) = the high point index in array A
     */

    // initial left-sum
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left;
    int max_right;
    
    //decrement the index in array A from mid to low:
    for (int i = mid; i >= low; i--)
    {
        // find the max in left
        sum = sum + A[i];
        if (sum > left_sum)
        {
            // put this as the maximum sum on the left
            left_sum = sum;
            max_left = i;
        }
    }

    //now intialize the condition for the right side mid + i index
    int right_sum = INT_MIN;
    sum = 0;

    // increment the index in array A from mid + 1 to high;
    for (int j = mid + 1; j <= high; j++)
    {
        // find the max in the right 
        sum = sum + A[j];
        if (sum > right_sum)
        {
            // put this as the maximum sum of the right
            right_sum = sum;
            max_right = j;
        }
    }

    // preparing the array to be returned : NOTE: it must be static to survive the end of scope
    static int result[3];
    // You can't directly initialize result[3] = {max_left, max_right, left_sum + right_sum}
    // because they are not constants, thus you need to assign them later 
    result[0] = max_left;
    result[1] = max_right;
    result[2] = left_sum + right_sum;

    return result;
}


int* maxSubArray(int *A, int A_length) // DEPRECATED!
{
    /* DEPRECATED!
    Finding maximum sub-array from origina array (A)

    Parameters:
        - A (static int array) : pointer (must be STATIC to survive the end of scope destruct)
        - A_length (int) : length of the A array
     */
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