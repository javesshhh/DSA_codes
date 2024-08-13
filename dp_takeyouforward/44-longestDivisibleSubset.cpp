// https://www.youtube.com/watch?v=gDuZwBW9VvM&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=45&ab_channel=takeUforward
// https://leetcode.com/problems/largest-divisible-subset/description/

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, 1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= n - 1; i++)
        {

            hash[i] = i; // initializing with current index
            for (int prev_index = 0; prev_index <= i - 1; prev_index++)
            {

                if (nums[i] % nums[prev_index] == 0 && 1 + dp[prev_index] > dp[i])
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
        temp.push_back(nums[lastIndex]);

        while (hash[lastIndex] != lastIndex)
        { // till not reach the initialization value
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
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