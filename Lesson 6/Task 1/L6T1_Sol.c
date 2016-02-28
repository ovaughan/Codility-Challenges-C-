/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Codility.com Lesson 6, Task 1: Distinct %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 Write a function
 
 int solution(int A[], int N);
 
 that, given a zero-indexed array A consisting of N integers, returns the number of distinct values in array A.
 
 Assume that:
 
 N is an integer within the range [0..100,000];
 each element of array A is an integer within the range [−1,000,000..1,000,000].
 For example, given array A consisting of six elements such that:
 
 A[0] = 2    A[1] = 1    A[2] = 1
 A[3] = 2    A[4] = 3    A[5] = 1
 the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.
 
 Complexity:
 
 expected worst-case time complexity is O(N*log(N));
 expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
 Elements of input arrays can be modified.
 */



/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Solution by Owen Vaughan, Feb 27 2016 %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 */

// This is a C program that should be run in the command line with arguments of the form: "1 2 3 ..", where A[] = {1, 2, 3, ..} is an array of N integers fulfilling the above conditions.


#include<stdio.h>
#include<stdlib.h>



// The following MergeSort function is taken from gist.github.com/mycodeschool/MergeSort_C.C

// Function to Merge Arrays L and R into A.
// lefCount = number of elements in L
// rightCount = number of elements in R.
void Merge(int *A, int *L, int leftCount, int *R, int rightCount)
{
    int i = 0, j = 0, k = 0;
    
    while(i < leftCount && j < rightCount)
    {
        if(L[i] < R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }
    
    while(i < leftCount)
        A[k++] = L[i++];
    
    while(j < rightCount)
        A[k++] = R[j++];
}

// Recursive function to sort an array of integers.
void MergeSort(int *A, int n)
{

    int mid,i, *L, *R;
    
    //special case
    if(n < 2)
        return;
    
    mid = n/2;  // find the mid index.
    
    // create left and right subarrays
    // mid elements (from index 0 till mid-1) should be part of left sub-array
    // and (n-mid) elements (from mid to n-1) will be part of right sub-array
    L = (int*)malloc( mid * sizeof(int));
    R = (int*)malloc( (n - mid) * sizeof(int));
    
    for(i = 0; i < mid; i++)
        L[i] = A[i];
    for(i = mid; i < n; i++)
        R[i-mid] = A[i];
    
    MergeSort(L, mid);  // sorting the left subarray
    MergeSort(R, n - mid);  // sorting the right subarray
    
    Merge(A, L, mid, R, n - mid);  // Merging L and R into A as sorted list.

    free(L);
    free(R);
}

int solution(int A[], int N) {
    
    // special cases
    if (N == 0)
        return 0;
    if (N == 1)
        return A[1];
    
    // sort the array
    MergeSort(A, N);
    
    // count distinc elements
    int num_dist = 1;
    for (int i = 1; i < N; i++)
        if (A[i] != A[i - 1])
            num_dist++;
    
    return num_dist;        
}


int main(int argc, char *argv[])
{
    // convert argument string to array of ints
    int input_array_length = argc - 1;
    int input_array[input_array_length];
    for (int i = 0; i < input_array_length; i++)
        input_array[i] = atoi(argv[i + 1]);
    
    // print the solution
    printf("%d\n", solution(input_array, input_array_length));
    
    return 0;
}

