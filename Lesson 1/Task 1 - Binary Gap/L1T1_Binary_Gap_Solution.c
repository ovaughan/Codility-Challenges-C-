/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Codility.com Lesson 1, Task 1: Binary Gap %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.
 
 For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.
 
 Write a function: 
 
 int solution(int N);
 
 that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.
 
 For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5.
 
 Assume that:
 • N is an integer within the range [1..2,147,483,647].
 
 Complexity:
 • expected worst-case time complexity is O(log(N));
 • expected worst-case space complexity is O(1).
*/



/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Solution by Owen Vaughan, Feb 26 2016 %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

// This is a C program that should be run in the command line with argument N, an integer within the range [1..2,147,483,647]


#include <stdio.h>
#include <stdlib.h>

int solution(int N)
{
    // "gap" will return the bitgap
    int gap = 0;
    
    // "active_gap" is an auxiliary variable used to find the active gap in a loop
    int active_gap = 0;
    
    // This checks to see if there has been at least one one. Needed in case of trailing zeros
    int at_least_one_one = 0;
    
    // The largest possible argument can have 31 bits, since 2^31 = 2,147,483,647
    for(int i = 0; i < 32; i++)
    {
        // if this bit is 1
        if ((N & (1 << i)) == (1 << i))
        {
            // check to see if the gap that preceded this bit is the biggest gap so far
            if (active_gap > gap && at_least_one_one == 1)
            {
                gap = active_gap;
            }
            
            // reset the active gap counter
            active_gap = 0;
            
            // there has been at least one one.
            at_least_one_one = 1;
        }
        else
        {
            // if this bit is zero, increase the active gap counter by one
            active_gap = active_gap + 1;
        }
    }
    
    return gap;
}


int main(int argc, char *argv[])
{
    printf("%d\n", solution(atoi(argv[1])));
    
    return 0;
}