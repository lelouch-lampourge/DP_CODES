// C++ program to count all possible way to construct buildings
#include<iostream>
using namespace std;
 
// Returns count of possible ways for N sections
int countWays(int N)
{
    // Base case
    if (N == 1)
        return 4;  // 2 for one side and 4 for two sides
 
    // countB is count of ways with a building at the end
    // countS is count of ways with a space at the end
    // prev_countB and prev_countS are previous values of
    // countB and countS respectively.
 
    // Initialize countB and countS for one side
    int countB=1, countS=1, prev_countB, prev_countS;
 
    // Use the above recursive formula for calculating
    // countB and countS using previous values
    for (int i=2; i<=N; i++)
    {
        prev_countB = countB;
        prev_countS = countS;
 
        countS = prev_countB + prev_countS;
        countB = prev_countS;
    }
 
    // Result for one side is sum of ways ending with building
    // and ending with space
    int result = countS + countB;
 
    // Result for 2 sides is square of result for one side
    return (result*result);
}
 
// Driver program
int main()
{
    int N = 3;
    cout << "Count of ways for " << N
         << " sections is " << countWays(N);
    return 0;
}


/*
Optimized Solution:
Note that the above solution can be further optimized. If we take closer look at the results, for different values, we can notice that the results for two sides are squares of Fibonacci Numbers.

N = 1, result = 4 [result for one side = 2]
N = 2, result = 9 [result for one side = 3]
N = 3, result = 25 [result for one side = 5]
N = 4, result = 64 [result for one side = 8]
N = 5, result = 169 [result for one side = 13]
*/