// https://www.youtube.com/watch?v=mLfjzJsN8us&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=3&ab_channel=takeUforward
// https://www.youtube.com/watch?v=Y0lT9Fck7qI&ab_channel=NeetCode
// above link is detailed explanation
// https://leetcode.com/problems/climbing-stairs/
// exact similar to fibonacci

// when to use dp - generally when asked to find count total number of ways ( try all possible ways)
//                            when asked to return min or max possible solution (perform all ways and return best way)
//Steps To Solve The Problem After Identification

//Once the problem has been identified, the following three steps comes handy in solving the problem:

//Try to represent the problem in terms of indexes.
//Try all possible choices/ways at every index according to the problem statement.
//If the question states
//                       Count all the ways – return sum of all choices/ways.
//                       Find maximum/minimum- return the choice/way with maximum/minimum output.



// Approach:

// Using the top-down approach of recursion,try to reach stair 0 standing from n.
// There are two possible ways at each stair =>take 1 step or 2 steps at a time.
// This problem is similar to fibonacci problem.Because the recurrence relation of both these problem is exactly the same.
// The base case is:
// When standing at stair 1 or 0 there is only 1 possible way to come to 0.

// if(n==0 or n==1) {
//     return 1
// }
// return f(n-1)+f(n-2)

1.Recursion:(TLE)
// For the above recurrence relation, the recusive solution is:

class Solution {
public:
    int findWays(int n){
        if(n<=1) return 1; //base case
        return findWays(n-1)+findWays(n-2);
    }

    int climbStairs(int n) {
        return findWays(n);
    }
};

// Complexity
// Time complexity: O(2^n)= Exponential time complexity
// Space complexity:O(n)=if recursion depth is considered,else:O(1)

2.Memoization: (Accepted)
// In above recusrion, the same subproblems are solved again and again.
// This is recomputaion and to avoid it store the results of subproblems which are already solved in dp array.
// So when a problem needs to be solved, if it is already solved then directly return the anwswer stored in dp array instead of again computing it.

class Solution {
public:
    int findWays(int n, vector<int> &dp)
    {
        if (n <= 1) return 1;
        if (dp[n] != -1) return dp[n];//already solved subproblems
        return dp[n]=findWays(n - 1, dp) + findWays(n - 2, dp); //store the result of subproblem in dp array
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1); //fill all values with -1
        return findWays(n,dp);
    }
};

// Complexity
// Time complexity: O(n)= Linear time complexity
// Space complexity:O(n)+O(N)= extra space of size n(dp) and recursion depth n

3.Dynamic Programming: (Accepted)
// The above approach requires recursive stack space.
// To optimize that space, use bottom-up approach of TABULATION.
// Start from base case and based on previous results gradually build the result.

class Solution {
public:
    int climbStairs(int n) {
         vector<int>dp(n+1,-1);
         dp[0]=1,dp[1]=1; //base cases             // base case as initialization
         for(int i=2;i<=n;++i){
             dp[i]=dp[i-1]+dp[i-2];                // converting recursive solution into iterative
         }
        return dp[n];
    }
};

// Complexity 
// Time complexity: O(n)= Linear time complexity
// Space complexity:O(n) = Extra space of size n and no recusrion stack space used.

// 4. Space Optimzation of DP (OPTIMAL SOLUTION)
// If we carefully observe above tabulation, we only need previous two values to fill current index rather than whole dp array.
// So we just maintain only those two values in 2 variables and update them accordingly for subsequent iterations.

class Solution {
public:
    int climbStairs(int n) {
        int prev2=1,prev1=1; //initally at 0th and 1st index

        for(int i=2;i<=n;i++){
            int curr=prev1+prev2;
            prev2=prev1; //update pointers
            prev1=curr;
        }
        return prev1;
    }
};