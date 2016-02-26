/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Codility.com Lesson 3, Task 2: Frog Jump %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 A small frog wants to get to the other side of the road. The frog is currently located at position X and wants to get to a position greater than or equal to Y. The small frog always jumps a fixed distance, D.
 
 Count the minimal number of jumps that the small frog must perform to reach its target.
 
 Write a function:
 
 int solution(int X, int Y, int D);
 
 that, given three integers X, Y and D, returns the minimal number of jumps from position X to a position equal to or greater than Y.
 
 For example, given:
 
 X = 10
 Y = 85
 D = 30
 the function should return 3, because the frog will be positioned as follows:
 
 after the first jump, at position 10 + 30 = 40
 after the second jump, at position 10 + 30 + 30 = 70
 after the third jump, at position 10 + 30 + 30 + 30 = 100
 Assume that:
 
 X, Y and D are integers within the range [1..1,000,000,000];
 X ≤ Y.
 Complexity:
 
 expected worst-case time complexity is O(1);
 expected worst-case space complexity is O(1).
*/



/*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Solution by Owen Vaughan, Feb 26 2016 %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

// This is the solution to the exercise, it is not a complete C program and will not compile.
// It can be checked on the website Codility.com

int solution(int X, int Y, int D) {

    // Z is the difference between X and Y
    int Z = Y - X;
    
    // The number we need to calculate is the integer part of Z/D
    
    // if D divides Z
    if ((Z % D) == 0)
        return (Z / D);
    else
    {
        //if D does not divide Z, then we take consider the next lowest integer that D divides, which is Z - (Z % D).
        return (Z - (Z % D))/D + 1;
    }
}
