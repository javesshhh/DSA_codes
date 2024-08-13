// https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=44&ab_channel=takeUforward
// https://practice.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=printing-longest-increasing-subsequence
// https://takeuforward.org/data-structure/printing-longest-increasing-subsequence-dp-42/

// this code is for length of LIS, we will modify it to print

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    v[i] = max(v[i], v[j] + 1);
                }
            }
        }
        int res = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            res = max(res, v[i]);
        }
        return res;
    }
};

// printing LIS
// without lexographical

vector<int> longestIncreasingSubsequence(int n, vector<int> &nums)
{
    // Code here
    // int n = nums.size();
    vector<int> lis(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    int ind = 0;
    int val = lis[0];
    for (int i = 1; i < n; i++)
    {
        if (lis[i] > val)
        {
            val = lis[i];
            ind = i;
        }
    }
    // cout<<ind;
    vector<int> v;
    v.push_back(nums[ind]);
    int i = ind - 1;
    while (i >= 0)
    {
        if (nums[i] < nums[ind] && lis[ind] - 1 == lis[i])
        {
            v.push_back(nums[i]);
            ind = i;
        }
        i--;
    }
    sort(v.begin(), v.end());
    return v;
}

// printing LIS
// lexographical

class Solution
{
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
    {
        // Code here
        vector<int> dp(n, 1);
        vector<int> hash(n);

        for (int i = 0; i <= n - 1; i++)
        {
            hash[i] = i; // initializing with current index
            for (int prev_index = 0; prev_index <= i - 1; prev_index++)
            {
                if (arr[prev_index] < arr[i] && 1 + dp[prev_index] > dp[i])
                {
                    dp[i] = 1 + dp[prev_index];
                    hash[i] = prev_index;
                }
            }
        }

        int ans = -1;
        int lastIndex = -1;

        for (int i = 0; i <= n - 1; i++)
        {
            if (dp[i] > ans)
            {
                ans = dp[i];
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(arr[lastIndex]);

        while (hash[lastIndex] != lastIndex)
        { // till not reach the initialization value
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }

        // reverse the array
        reverse(temp.begin(), temp.end());

        // cout<<"The subsequence elements are ";

        // for(int i=0; i<temp.size(); i++){
        //     cout<<temp[i]<<" ";
        // }
        // cout<<endl;

        return temp;
    }
};

// another code

class Solution
{
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int> &nums)
    {
        // Code here
        vector<int> v(n, 1);
        // vector<int>index(n,0);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    v[i] = max(v[i], v[j] + 1);
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     index[i]=i;
        // }
        int index;
        int k = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > k)
            {
                k = v[i];
                index = i;
            }
        }
        int maxi = v[index] - 1;
        vector<int> ans;
        ans.push_back(nums[index]);
        while (maxi > 0)
        {
            int a = INT_MAX;
            int c;
            for (int i = 0; i < index; i++)
            {
                if (v[i] == maxi && nums[i] < a)
                {
                    c = i;
                    a = nums[i];
                }
            }
            index = c;
            ans.push_back(nums[index]);
            maxi--;
        }
        // int res = INT_MIN;
        // for (int i = 0; i < n; i++)
        // {
        //     res = max(res, v[i]);
        // }
        // return res;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};