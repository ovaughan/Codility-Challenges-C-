/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Codility.com Lesson 2, Task 2: Odd Occurrences in Array %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 A non-empty zero-indexed array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value, except for one element that is left unpaired.
 
 For example, in array A such that:
 
 A[0] = 9  A[1] = 3  A[2] = 9
 A[3] = 3  A[4] = 9  A[5] = 7
 A[6] = 9
 the elements at indexes 0 and 2 have value 9,
 the elements at indexes 1 and 3 have value 3,
 the elements at indexes 4 and 6 have value 9,
 the element at index 5 has value 7 and is unpaired.
 Write a function:
 
 int solution(int A[], int N);
 
 that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.
 
 For example, given array A such that:
 
 A[0] = 9  A[1] = 3  A[2] = 9
 A[3] = 3  A[4] = 9  A[5] = 7
 A[6] = 9
 the function should return 7, as explained in the example above.
 
 Assume that:
 
 N is an odd integer within the range [1..1,000,000];
 each element of array A is an integer within the range [1..1,000,000,000];
 all but one of the values in A occur an even number of times.
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

// This is a C program that should be run in the command line with arguments of the form: "1 2 3 ..", where A[] = {1, 2, 3, ..} is an array of N integers fulfilling the above coniditions.

#include <stdio.h>
#include <stdlib.h>


int solution(int A[], int N)
{

    // "odd_occurrences" is understood as a bit field
    int odd_occurrences = 0;
    
    
    for (int i = 0; i < N; i++)
    {
        // If bit A[i] is zero set it to 1, if it is 1 set it to zero.
        odd_occurrences = odd_occurrences ^ A[i];
    }
    
    return odd_occurrences;
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