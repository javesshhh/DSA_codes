// https://www.youtube.com/watch?v=GrMBfJNk_NY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=6&ab_channel=takeUforward
// https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/
// https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-without-adjacents

// recusion TLE code

// User function template for C++
class Solution
{
public:
	int fn(int i, int *arr, int n)
	{
		if (i >= n)
		{
			return 0;
		}
		// if(dp[i]!=-1){
		//     return dp[i];
		// }
		// sum=sum+arr[i];
		int two = arr[i] + fn(i + 2, arr, n);
		// sum=sum-arr[i];
		int one = fn(i + 1, arr, n);
		return max(one, two);
	}

	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n)
	{
		// code here
		// int sum=0;
		// vector<int>dp(n,-1);
		return fn(0, arr, n);
		// return sum;
	}
};

// memoization code

// User function template for C++
class Solution
{
public:
	int fn(int i, int *arr, int n, vector<int> &dp)
	{
		if (i >= n)
		{
			return 0;
		}
		if (dp[i] != -1)
		{
			return dp[i];
		}
		// sum=sum+arr[i];
		int two = arr[i] + fn(i + 2, arr, n, dp);
		// sum=sum-arr[i];
		int one = fn(i + 1, arr, n, dp);
		return dp[i] = max(one, two);
	}

	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n)
	{
		// code here
		// int sum=0;
		vector<int> dp(n, -1);
		return fn(0, arr, n, dp);
		// return sum;
	}
};

// tabulation code

// User function template for C++
class Solution
{
public:
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n)
	{
		// code here
		vector<int> dp(n + 2, -1);
		dp[n] = 0;
		dp[n + 1] = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			int two = arr[i] + dp[i + 2];
			// sum=sum-arr[i];
			int one = 0 + dp[i + 1];
			dp[i] = max(one, two);
		}
		return dp[0];
	}
};

// space optimized code

// User function template for C++
class Solution
{
public:
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n)
	{
		// code here
		// vector<int>dp(n+2,-1);
		int next = 0;
		int next2 = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			int two = arr[i] + next2;
			// sum=sum-arr[i];
			int one = 0 + next;
			int curr = max(one, two);
			next2 = next;
			next = curr;
		}
		return next;
	}
};
