/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Codility.com Lesson 4, Task 1: Permutation Check %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 A non-empty zero-indexed array A consisting of N integers is given.
 
 A permutation is a sequence containing each element from 1 to N once, and only once.
 
 For example, array A such that:
 
 A[0] = 4
 A[1] = 1
 A[2] = 3
 A[3] = 2
 is a permutation, but array A such that:
 
 A[0] = 4
 A[1] = 1
 A[2] = 3
 is not a permutation, because value 2 is missing.
 
 The goal is to check whether array A is a permutation.
 
 Write a function:
 
 int solution(int A[], int N);
 
 that, given a zero-indexed array A, returns 1 if array A is a permutation and 0 if it is not.
 
 For example, given array A such that:
 
 A[0] = 4
 A[1] = 1
 A[2] = 3
 A[3] = 2
 the function should return 1.
 
 Given array A such that:
 
 A[0] = 4
 A[1] = 1
 A[2] = 3
 the function should return 0.
 
 Assume that:
 
 N is an integer within the range [1..100,000];
 each element of array A is an integer within the range [1..1,000,000,000].
 Complexity:
 
 expected worst-case time complexity is O(N);
 expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
 Elements of input arrays can be modified.
*/



/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Solution by Owen Vaughan, Feb 28 2016 %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

// This is the solution to the exercise, it is not a complete C program and will not compile.
// It can be checked on the website Codility.com

// function returns a pointer to a count array of length len
int *count(int *A, int N, int len)
{
    int *B = (int *)calloc(len, sizeof(int));
    
    for (int i = 0; i < N; i++)
        if (0 <= A[i] && A[i] < len)
            B[A[i]] += 1;
    
    return B;
}

int solution(int A[], int N)
{
    // Subtract 1 from all elements of A, so they now take values in 0, .., N - 1 (if a permutation)
    for (int i = 0; i < N; i++)
        A[i] -= 1;
    
    // create a count array based on A
    int *count_array = count(A, N, N);
    
    // check if there are any zeros
    for (int i = 0; i < N; i++)
        if (count_array[i] == 0)
            return 0;
    
    return 1;
}