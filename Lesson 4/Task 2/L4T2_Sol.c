/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Codility.com Lesson 4, Task 2: Missing Integer %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 Write a function:
 
 int solution(int A[], int N);
 
 that, given a non-empty zero-indexed array A of N integers, returns the minimal positive integer (greater than 0) that does not occur in A.
 
 For example, given:
 
 A[0] = 1
 A[1] = 3
 A[2] = 6
 A[3] = 4
 A[4] = 1
 A[5] = 2
 the function should return 5.
 
 Assume that:
 
 N is an integer within the range [1..100,000];
 each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
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
    
    int *count_array = count(A, N, N + 1);
    
    for (int i = 1; i < N + 1; i++)
        if (count_array[i] == 0)
            return i;
    
    return N + 1;
}