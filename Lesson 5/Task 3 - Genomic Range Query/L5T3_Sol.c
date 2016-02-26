/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Codility.com Lesson 5, Task 3: Genomic Range Query %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?
 
 The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).
 
 For example, consider string S = CAGCCTA and arrays P, Q such that:
 
 P[0] = 2    Q[0] = 4
 P[1] = 5    Q[1] = 5
 P[2] = 0    Q[2] = 6
 The answers to these M = 3 queries are as follows:
 
 The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
 The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
 The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.
 Assume that the following declarations are given:
 
 struct Results {
 int * A;
 int M;
 };
 
 Write a function:
 
 struct Results solution(char *S, int P[], int Q[], int M);
 
 that, given a non-empty zero-indexed string S consisting of N characters and two non-empty zero-indexed arrays P and Q consisting of M integers, returns an array consisting of M integers specifying the consecutive answers to all queries.
 
 The sequence should be returned as:
 
 a Results structure (in C), or
 a vector of integers (in C++), or
 a Results record (in Pascal), or
 an array of integers (in any other programming language).
 For example, given the string S = CAGCCTA and arrays P, Q such that:
 
 P[0] = 2    Q[0] = 4
 P[1] = 5    Q[1] = 5
 P[2] = 0    Q[2] = 6
 the function should return the values [2, 4, 1], as explained above.
 
 Assume that:
 
 N is an integer within the range [1..100,000];
 M is an integer within the range [1..50,000];
 each element of arrays P, Q is an integer within the range [0..N − 1];
 P[K] ≤ Q[K], where 0 ≤ K < M;
 string S consists only of upper-case English letters A, C, G, T.
 Complexity:
 
 expected worst-case time complexity is O(N+M);
 expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
 Elements of input arrays can be modified.
 
*/



/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Solution by Owen Vaughan, Feb 26 2016 %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

// This is a C program that should be run in the command line with arguments of the form:
// S[0]S[1]...S[N-1] P[0] P[1] .. P[M-1] Q[0] Q[1] .. Q[M - 1]
// Example: CAGCCTA 2 5 0 4 5 6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Results {
    int * A;
    int M;
};

struct Results solution(char *S, int P[], int Q[], int M) {
    
    struct Results result;

    // need to allocate memory at the address of pointer A
    result.A = (int *)malloc( M * sizeof(int));
    result.M = M;
    
    int N = strlen(S);
    
    // "impact_array" is an array derived from S, with elements taking values in 1 to 4 instead of ACGT.
    int impact_array[N];
    for (int i = 0; i < N; i++)
    {
        if (S[i] == 65)
            impact_array[i] = 1;
        if (S[i] == 67)
            impact_array[i] = 2;
        if ((int)S[i] == 71)
            impact_array[i] = 3;
        if (S[i] == 84)
            impact_array[i] = 4;
        
    }
    
    // for each element of the sequence, the array "last_nums" tells us where the last 1 is, the last 2, and the last 3. The last 4 is irrelevant
    int last_nums[N][3];
    
    // initialise to -1, which means there has been no last 1, 2, or 4.
    for (int i = 0; i < N; i++)
    {
        last_nums[i][0] = -1;
        last_nums[i][1] = -1;
        last_nums[i][2] = -1;
    }
    
    // calculate last_nums array
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
        {
            last_nums[i][0] = last_nums[i - 1][0];
            last_nums[i][1] = last_nums[i - 1][1];
            last_nums[i][2] = last_nums[i - 1][2];
        }
        
        if (impact_array[i] == 1)
            last_nums[i][0] = i;
        if (impact_array[i] == 2)
            last_nums[i][1] = i;
        if (impact_array[i] == 3)
            last_nums[i][2] = i;
    }
    
    // now we can loop over all queries
    for (int i = 0; i < M; i++)
    {
        //start by assuming the lowest impact member is 4.
        result.A[i] = 4;
        
        
        // special case P = Q
        if (P[i] == Q[i])
        {
            result.A[i] = impact_array[P[i]];
            
            continue;
        }

        // Give our assumptions, if P != Q then P < Q
        
        // check if the last 3 was in the range PQ
        if (last_nums[Q[i]][2] >= P[i])
            result.A[i] = 3;
        
        // check if the last 2 was in the range PQ
        if (last_nums[Q[i]][1] >= P[i])
            result.A[i] = 2;
        
        // check if the last 1 was in the range PQ
        if (last_nums[Q[i]][0] >= P[i])
            result.A[i] = 1;
    }
    
    return result;
}


int main(int argc, char *argv[])
{
    
    // From the given arguments, calculate M and P[] and Q[]
    int M = (argc - 2) / 2;
    int P[M], Q[M];
    for (int i = 0; i < M; i++)
    {
        P[i] = atoi(argv[2 + i]);
        Q[i] = atoi(argv[2 + M + i]);
    }
    
    // calculate the solution
    struct Results result = solution(argv[1], P, Q, M);
    
    // print the solution
    for (int i = 0; i < result.M; i++)
        printf("%d ", result.A[i]);
    
    printf("\n");
    
    return 0;
}