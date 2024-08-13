// https://leetcode.com/problems/two-sum/description/

// two pointer approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target && i!=j){
                    ans.push_back(i);
                    ans.push_back(j);
                    goto label;
                }
            }
        }
        label:
        return ans;
    }
};

// optimised approach


// https://cppsecrets.com/users/96531181051109712199104111112114975750461189964103109971051084699111109/C00-Two-Sum-LeetCode.php
// https://www.youtube.com/watch?v=dRUpbt8vHpo&ab_channel=takeUforward
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            int diff=target-nums[i];
            if(m.find(diff)!=m.end()){
                v.push_back(i);
                v.push_back(m[diff]);
                goto label;
            }
            m[nums[i]]=i;
        }
        label:
        return v;
    }
};