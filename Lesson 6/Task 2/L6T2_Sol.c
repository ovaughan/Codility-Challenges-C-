/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Codility.com Lesson 6, Task 2: Triangle %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 A zero-indexed array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:
 
 A[P] + A[Q] > A[R],
 A[Q] + A[R] > A[P],
 A[R] + A[P] > A[Q].
 For example, consider array A such that:
 
 A[0] = 10    A[1] = 2    A[2] = 5
 A[3] = 1     A[4] = 8    A[5] = 20
 Triplet (0, 2, 4) is triangular.
 
 Write a function:
 
 int solution(int A[], int N);
 
 that, given a zero-indexed array A consisting of N integers, returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.
 
 For example, given array A such that:
 
 A[0] = 10    A[1] = 2    A[2] = 5
 A[3] = 1     A[4] = 8    A[5] = 20
 the function should return 1, as explained above. Given array A such that:
 
 A[0] = 10    A[1] = 50    A[2] = 5
 A[3] = 1
 the function should return 0.
 
 Assume that:
 
 N is an integer within the range [0..100,000];
 each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
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

// This is the solution to the exercise, it is not a complete C program and will not compile.
// It can be checked on the website Codility.com

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


int solution(int A[], int N)
{
    
    // special case
    if (N < 3)
        return 0;
    
    // Sort A
    MergeSort(A, N);
    
    
    // key idea: once sorted, we only need to check each set of three consecutive numbers
    
    for (int i = 0; i < (N - 2); i++)
    {
        if ((long)A[i] + (long)A[i + 1] > (long)A[i + 2] && (long)A[i + 1] + (long)A[i + 2] > (long)A[i] && (long)A[i] + (long)A[i + 2] > (long)A[i + 1])
            return 1;
    }
    
    return 0;
}
