// https://www.youtube.com/watch?v=S49zeUjeUL0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=42&ab_channel=AdityaVerma
// https://leetcode.com/problems/super-egg-drop/description/
// explanation https://leetcode.com/problems/super-egg-drop/solutions/792736/cpp-explained-recursive-memoization-optimization-dp-well-explained-easy-to-unserstand/

// recursion

class Solution
{
public:
    int fn(int k, int n)
    {
        if (k == 1)
        {
            return n;
        }
        if (n == 1 || n == 0)
        {
            return n;
        }
        int ans = 1e5;
        for (int i = 1; i <= n; i++)
        {
            int mini = 1 + max(fn(k - 1, i - 1), fn(k, n - i));
            ans = min(ans, mini);
        }
        return ans;
    }

    int superEggDrop(int k, int n)
    {
        return fn(k, n);
    }
    // int find(int k,int n)
    // {   if(n==0||n==1) return n;  //if no. of floor 0 , 1 return n:
    //     if(k==1) return n;        // if 1 egg return number of floor
    //     int ans=1000000;
    //     for(int i=1;i<=n;i++)  // try from 1 to n floor , drop every floor and find minimum
    //     {
    //       int temp=1+max(find(k-1,i-1),find(k,n-i)) ;  //maximum for worst case
    //       ans=min(ans,temp);                                     //minimum attempts from maximum temp
    //     }

    //  /*
    //     Here we have k eggs and n floor
    //     if we drop from i  (i=1 to n):
    //      i) egg break , now we remain k-1 eggs and i-1 floor beacase after i(included) floor all the eggs will also break
    //     ii) egg not break , now we remain k eggs and n-i floor because before i (included) all eggs will be remain
    //   */
    //     return ans;

    // }
    // int superEggDrop(int K, int N) {
    //     //K -> egg , N -> floor
    //     return find(K,N);

    // }
};

// memoization - still TLE
// https://www.youtube.com/watch?v=gr2NtY-2QUY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=43&ab_channel=AdityaVerma

class Solution
{
public:
    int fn(int k, int n, vector<vector<int>> &dp)
    {
        if (k == 1)
        {
            return n;
        }
        if (n == 1 || n == 0)
        {
            return n;
        }
        if (dp[k][n] != -1)
        {
            return dp[k][n];
        }
        int ans = 1e5;
        for (int i = 1; i <= n; i++)
        {
            int mini = 1 + max(fn(k - 1, i - 1, dp), fn(k, n - i, dp));
            ans = min(ans, mini);
        }
        return dp[k][n] = ans;
    }

    int superEggDrop(int k, int n)
    {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return fn(k, n, dp);
    }
};

// optimized solution using binary search
// explanation https://leetcode.com/problems/super-egg-drop/solutions/792736/cpp-explained-recursive-memoization-optimization-dp-well-explained-easy-to-unserstand/

class Solution
{
public:
    int find(int k, int n, vector<vector<int>> &memo)
    {
        if (n == 0 || n == 1)
            return n; // if no. of floor 0 , 1 return n:
        if (k == 1)
            return n; // if 1 egg return number of floor
        if (memo[k][n] != -1)
            return memo[k][n];
        int ans = 1000000, l = 1, h = n, temp = 0;

        while (l <= h)
        {
            int mid = (l + h) / 2;
            int left = find(k - 1, mid - 1, memo); // egg broken check for down floors of mid
            int right = find(k, n - mid, memo);    // not broken check for up floors of mid
            temp = 1 + max(left, right);           // store max of both
            if (left < right)
            {                // since right is more than left and we need more in worst case
                l = mid + 1; // so l=mid+1 to gain more temp for worst case : upward
            }
            else // left > right so we will go downward
            {
                h = mid - 1;
            }
            ans = min(ans, temp); // store minimum attempts
        }

        /*
           Here we have k eggs and n floor
           if we drop from i  (i=1 to n):
            i) egg break , now we remain k-1 eggs and i-1 floor beacase after i floor all the eggs will also break
           ii) egg not break , now we remain k eggs and n-i floor because before i (included) all eggs will be remain
         */
        return memo[k][n] = ans;
    }
    int superEggDrop(int K, int N)
    {
        // K -> egg , N -> floor
        vector<vector<int>> memo(K + 1, vector<int>(N + 1, -1));
        return find(K, N, memo);
    }
};