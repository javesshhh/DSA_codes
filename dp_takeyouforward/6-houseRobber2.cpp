// https://www.youtube.com/watch?v=3WaxQMELSkw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=7&ab_channel=takeUforward
// https://takeuforward.org/data-structure/dynamic-programming-house-robber-dp-6/
// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=stickler-theif-
// https://leetcode.com/problems/house-robber/description/
// https://leetcode.com/problems/house-robber-ii/description/

// similar to previous

class Solution {
public:

    int fn(vector<int>&arr)
    {
        // Your code here
        int n=arr.size();
        vector<int>dp(n+1,-1);
        // return fn(0,arr,n,dp);
        int next=arr[n-1];
        int next2=0;
        for(int i=n-2;i>=0;i--){
            int two=arr[i]+next2;
        int one=0+next;
        int curr=max(one,two);
        next2=next;
        next=curr;
        }
        return next;
    }

    int rob(vector<int>& nums) {
        vector<int>temp1;
        vector<int>temp2;
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }
        int ans1=fn(temp1);
        int ans2=fn(temp2);
        return max(ans1,ans2);
    }
};