/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Codility.com Lesson 6, Task 4: Number of Disc Intersections %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 We draw N discs on a plane. The discs are numbered from 0 to N − 1. A zero-indexed array A of N non-negative integers, specifying the radiuses of the discs, is given. The J-th disc is drawn with its center at (J, 0) and radius A[J].
 
 We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and K-th discs have at least one common point (assuming that the discs contain their borders).
 
 The figure below shows discs drawn for N = 6 and A as follows:
 
 A[0] = 1
 A[1] = 5
 A[2] = 2
 A[3] = 1
 A[4] = 4
 A[5] = 0
 
 
 There are eleven (unordered) pairs of discs that intersect, namely:
 
 discs 1 and 4 intersect, and both intersect with all the other discs;
 disc 2 also intersects with discs 0 and 3.
 Write a function:
 
 int solution(int A[], int N);
 
 that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs. The function should return −1 if the number of intersecting pairs exceeds 10,000,000.
 
 Given array A shown above, the function should return 11, as explained above.
 
 Assume that:
 
 N is an integer within the range [0..100,000];
 each element of array A is an integer within the range [0..2,147,483,647].
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

// This solution was inspired by the solution from Rafal
// http://rafal.io/posts/codility-intersecting-discs.html


/*
 Idea:
 Brute force we need to count how many i and j satisfy
 A[i] + A[j] >= abs (j - i);
 
 This is given by
 A[i] + A[j] >= j - i, subtract instances of j = i and j < i which total N(N + 1)/2
 
 The equivalent calcuation is
 i + A[i] >= j - A[j].
 
 We can creat two arrays, i + A[i] and j - A[j] and sort them. The calculation is then relatively easy.
 */



#include<stdio.h>
#include<stdlib.h>


// The following MergeSort function is taken from gist.github.com/mycodeschool/MergeSort_C.C

// Function to Merge Arrays L and R into A.
// lefCount = number of elements in L
// rightCount = number of elements in R.
void Merge(long *A, long *L, long leftCount, long *R, long rightCount)
{
    long i = 0, j = 0, k = 0;
    
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
void MergeSort(long *A, long n)
{
    
    long mid, i;
    long *L, *R;
    
    //special case
    if(n < 2)
        return;
    
    mid = n/2;  // find the mid index.
    
    // create left and right subarrays
    // mid elements (from index 0 till mid-1) should be part of left sub-array
    // and (n-mid) elements (from mid to n-1) will be part of right sub-array
    L = (long*)malloc( mid * sizeof(long));
    R = (long*)malloc( (n - mid) * sizeof(long));
    
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

// This function computes the position in an ordered array A
// in which the values are first greater than r.
// If no elements are greater than r it returns n.
// This function has time complexity O(log n) and space complexity O(1)
void search_array(long *A, long n, long r, long *pos)
{
    long mid = n/2;
    
    if (A[*pos + mid] > r)
    {
        if (mid != 0)
            search_array(A, mid, r, pos);
    }
    else
    {
        if (mid == 0)
            *pos += 1;
        else
        {
            *pos += mid;
            search_array(A, (n - mid), r, pos);
        }
    }
}


int solution(int A[], int N)
{
    //special case
    if (N == 0)
        return 0;
    
    long A1[N], A2[N];
    
    // initialise the two arrays i + A[i] and j - A[j]
    for (int i = 0; i < N; i ++)
    {
        A1[i] = (long)i + (long)A[i];
        A2[i] = (long)i - (long)A[i];
    }
    
    // sort
    MergeSort(A1, (long)N);
    MergeSort(A2, (long)N);
    
    // total number of interesects and local intersection counter
    long total_num_intersects = 0;
    long num_intersects = 0;
    
    for (int i = 0; i < N; i++)
    {
        num_intersects = 0;
        
        search_array(A2, (long)N, A1[i], &num_intersects);
        
        total_num_intersects += num_intersects;
    }
    
    // Subtract cases that have been overcounted.
    // Here it is j - i <= 0, for i,j in n.
    total_num_intersects -= (long)N*((long)N + 1) / 2;
    
    if (total_num_intersects > 10000000)
        return -1;
    
    return total_num_intersects;
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