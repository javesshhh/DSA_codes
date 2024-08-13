// https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/description/

// class Solution {
// public:

//     int fn(int i,int prev,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp){
//         if(i>=nums1.size()){
//             return 0;
//         }
//         if(dp[i][prev]!=-1){
//             return dp[i][prev];
//         }
//         if(prev==0){
//             int notake=fn(i+1,prev,nums1,nums2,dp);
//             int take1=1+fn(i+1,1,nums1,nums2,dp);
//             int take2=1+fn(i+1,2,nums1,nums2,dp);
//             dp[i][prev]=max({notake,take1,take2});
//         }
//         if(prev==1){
//             int take1=0,take2=0;
//             // int notake=fn(i+1,0,nums1,nums2,dp);
//             if(nums1[i]>=nums1[i-1])
//             int take1=1+fn(i+1,1,nums1,nums2,dp);
//             if(nums2[i]>=nums1[i-1])
//             int take2=1+fn(i+1,2,nums1,nums2,dp);
//             dp[i][prev]=max(take1,take2);
//         }
//         if(prev==2){
//             int take1=0,take2=0;
//             // int notake=fn(i+1,0,nums1,nums2,dp);
//             if(nums1[i]>=nums2[i-1])
//             int take1=1+fn(i+1,1,nums1,nums2,dp);
//             if(nums2[i]>=nums2[i-1])
//             int take2=1+fn(i+1,2,nums1,nums2,dp);
//             dp[i][prev]=max(take1,take2);
//         }
//         return dp[i][prev];
//     }

//     int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
//         int n=nums1.size();
//         vector<vector<int>>dp(n,vector<int>(3,-1));
//         return fn(0,0,nums1,nums2,dp);
//     }
// };

int f(int i, int flag, vector<int> &nums1, vector<int> &nums2, int n, vector<vector<int>> &dp)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i][flag] != -1)
        return dp[i][flag];
    if (flag == 0)
    {
        int pick1 = f(i + 1, 1, nums1, nums2, n, dp) + 1;
        int pick2 = f(i + 1, 2, nums1, nums2, n, dp) + 1;
        int notpick = f(i + 1, 0, nums1, nums2, n, dp);
        return dp[i][flag] = max({pick1, pick2, notpick});
    }
    else if (flag == 1)
    {
        int pick1 = 0;
        int pick2 = 0;
        if (nums1[i - 1] <= nums1[i])
            pick1 = f(i + 1, 1, nums1, nums2, n, dp) + 1;
        if (nums1[i - 1] <= nums2[i])
            pick2 = f(i + 1, 2, nums1, nums2, n, dp) + 1;
        return dp[i][flag] = max(pick1, pick2);
    }
    else if (flag == 2)
    {
        int pick1 = 0;
        int pick2 = 0;
        if (nums2[i - 1] <= nums1[i])
            pick1 = f(i + 1, 1, nums1, nums2, n, dp) + 1;
        if (nums2[i - 1] <= nums2[i])
            pick2 = f(i + 1, 2, nums1, nums2, n, dp) + 1;
        return dp[i][flag] = max(pick1, pick2);
    }
    return dp[i][flag] = 0;
}

class Solution
{
public:
    int maxNonDecreasingLength(vector<int> &nums1, vector<int> &nums2)
    {
        int flag = 0;
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return f(0, flag, nums1, nums2, n, dp);
    }
};