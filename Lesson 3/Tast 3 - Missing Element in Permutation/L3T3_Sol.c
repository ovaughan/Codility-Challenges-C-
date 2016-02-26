/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Codility.com Lesson 3, Task 3: Missing Element in Permutation %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 A zero-indexed array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.
 
 Your goal is to find that missing element.
 
 Write a function:
 
 int solution(int A[], int N);
 
 that, given a zero-indexed array A, returns the value of the missing element.
 
 For example, given array A such that:
 
 A[0] = 2
 A[1] = 3
 A[2] = 1
 A[3] = 5
 the function should return 4, as it is the missing element.
 
 Assume that:
 
 N is an integer within the range [0..100,000];
 the elements of A are all distinct;
 each element of array A is an integer within the range [1..(N + 1)].
 Complexity:
 
 expected worst-case time complexity is O(N);
 expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
 Elements of input arrays can be modified.
*/



/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Solution by Owen Vaughan, Feb 26 2016 %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

// This is the solution to the exercise, it is not a complete C program and will not compile.
// It can be checked on the website Codility.com

int solution(int A[], int N)
{
    // Special case: length of array is zero
    if (N == 0)
        return 1;
    
    // the potential total if the missing element was there
    // ie the sum of the first N + 1 integers
    unsigned long max_total = (((unsigned long)N + 1)*((unsigned long)N + 2))/2;
    
    // the actual total of our array of integers
    unsigned long actual_total = 0;
    
    for (int i = 0; i < N; i++)
        actual_total += A[i];
    
    // the missing element is the difference between the sum of the first N + 1 ints and our actual total
    return (int)(max_total - actual_total);
}
