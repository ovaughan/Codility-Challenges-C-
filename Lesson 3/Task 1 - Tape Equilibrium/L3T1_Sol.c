/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Codility.com Lesson 3, Task 1: Tape Equilibrium %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 A non-empty zero-indexed array A consisting of N integers is given. Array A represents numbers on a tape.
 
 Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].
 
 The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|
 
 In other words, it is the absolute difference between the sum of the first part and the sum of the second part.
 
 For example, consider array A such that:
 
 A[0] = 3
 A[1] = 1
 A[2] = 2
 A[3] = 4
 A[4] = 3
 We can split this tape in four places:
 
 P = 1, difference = |3 − 10| = 7
 P = 2, difference = |4 − 9| = 5
 P = 3, difference = |6 − 7| = 1
 P = 4, difference = |10 − 3| = 7
 Write a function:
 
 int solution(int A[], int N);
 
 that, given a non-empty zero-indexed array A of N integers, returns the minimal difference that can be achieved.
 
 For example, given:
 
 A[0] = 3
 A[1] = 1
 A[2] = 2
 A[3] = 4
 A[4] = 3
 the function should return 1, as explained above.
 
 Assume that:
 
 N is an integer within the range [2..100,000];
 each element of array A is an integer within the range [−1,000..1,000].
 Complexity:
 
 expected worst-case time complexity is O(N);
 expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
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
    
    int my_sol;
    
    int total = 0;
    
    //we will split the tape into two blocks. The integers "block1" and "block2" are the sum total of each block.
    int block1 = 0;
    int block2 = 0;
    
    // Sum over all elements of the array
    for (int i = 0; i < N; i++)
        total += A[i];
    
    //we start off with an empty block one and a full block 2
    block2 = total;

    //we set my_sol to the absolute value of the total of the initial configuration
    my_sol = abs(A[0] - (total - A[0]));

    for (int i = 0; i < (N - 1); i++)
    {
        //each iteration increases block one and decreases block 2 by the amount A[i]
        block1 += A[i];
        block2 -= A[i];
        
        // we check to see if the new configuration gives a lower total than before
        if ( abs(block1 - block2) < my_sol)
            my_sol = abs(block1 - block2);
    }    
    
    return my_sol;
}