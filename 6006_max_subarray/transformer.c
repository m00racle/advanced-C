#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// declaring functions

int* maxSubArray(int *A, int A_length);

// declare find max subarray
int* FindMaxSubarray(int* A, int low, int high);

// declaring max-crossing-subarray
int* FindMaxCrossingSubarray(int *A, int low, int mid, int high);

// declaring DivMaxSubarray
int* DivMaxSubarray(int *A, int low, int high);

// helper function to copy one array to another:
void copyArray(int *src, int *dest, int size) {
    /*
        helper function to copy one array to another.
        Required if you want to preserve a state from returned static array
        the static array will be changed for each call to its function thus the previous state will also changed
        even as you refer it using new variable, this variable will only be a pointer to the same address as the static array
        thus when the static array elements changed then the varible element also changed thus unable to preserve the state

        Parameters:
            - src : pointer in this case for array consist of int(s) act as source of copy
            - dest : pointer to another prepared array for int(s) act as destination of copy
            - size : int specified number of element NOT the total size in bytes!!!
    */
  // Loop through each element of the arrays
  for (int i = 0; i < size; i++) {
    // Copy the i-th element from source to destination
    dest[i] = src[i];
  }
}

void test_run(int *A, int length, char* test_msg)
{
    /*  
        helper function to test run and print out the results

        Parameters:
            - A (int pointer to array) : the array to maximized
            - length (int) : length of the array
    */

    // select the method to find maximum sub-array
    int *results = DivMaxSubarray(A, 0, length - 1);
    
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

int* DivMaxSubarray(int *A, int low, int high)
{
    /*  
        using divide and conquer recursive algorithm
        find max sub array

        Parameters:
        A (int pointer Array) = array of int to find max sub array
        low (int) = lowest index of array element in scope
        high (int) = highest index of array element in scope
    */
    // I don't think I need to reset the returned array (div_data) 
    // the contains in it will not be used as if comparison
    static int div_data[3];
    // declare arrays to store low, high indexes, and max sum of each merge part
    int left_data[3];
    int right_data[3];
    int cross_data[3];

    int mid; // this is the complementary index between low and high
    // base case:
    if (high == low)
    {
        // means there only one element and thus the max sum will be that element only
        // return {low, high, the only element in subarray}
        div_data[0] = low;
        div_data[1] = high;
        div_data[2] = A[low];

        return div_data;
    } else
    {
        // run the recursive dividing steps by half of the arrray length
        mid = floor((low + high) / 2);

        // run the merge steps by selecting most optimum sum
        // begin with the left side low to mid:
        copyArray(DivMaxSubarray(A, low, mid), left_data, 3);
        // right side mid+1 to high
        copyArray(DivMaxSubarray(A, mid + 1, high), right_data, 3);
        // cross test 
        copyArray(FindMaxCrossingSubarray(A, low, mid, high), cross_data, 3);

        // determine which is the left, right, or cross to be returned to below recursive step;
        // REMEBER ALWAYS RETURN ARRAY AS div_data since it is the static array here!
        // meaning you need to copy the selected array to div_data array first
        // note the sum is in each data index [2]
        if (left_data[2] >= right_data[2] && left_data[5] >= cross_data[2])
        {
            copyArray(left_data, div_data, 3);
        } 
        else if (right_data[2] > left_data[2] && right_data[5] > cross_data[2])
        {
            copyArray(right_data, div_data, 3);
        }
        else
        {
            copyArray(cross_data, div_data, 3);
        }

        return div_data;
    }
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
    for (int i = 0; i < 3; i++) max_data[i] = 0;

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
                max_data[0] = start; max_data[1] = end; max_data[2] = max_sum; 
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
        max_data[0] = start; max_data[1] = end; max_data[2] = max_sum;
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
    // preparing the array to be returned : NOTE: it must be static to survive the end of scope
    static int result[3];
    
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

    // You can't directly initialize result[3] = {max_left, max_right, left_sum + right_sum}
    // because they are not constants, thus you need to assign them later 
    result[0] = max_left; result[1] = max_right; result[2] = left_sum + right_sum;

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