// https://youtu.be/RIn3gOkbhQE
// https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:

    void subsets(int i,vector<int>& nums,vector<int>&a,vector<vector<int>>&ans){
        // if(i==nums.size()){
        //     ans.push_back(a);
        //     return;
        // }
        ans.push_back(a);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]){
                continue;
            }
            a.push_back(nums[j]);
            subsets(j+1,nums,a,ans);
            a.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>a;
        sort(nums.begin(),nums.end());
        subsets(0,nums,a,ans);
        return ans;
    }
};


// https://www.youtube.com/watch?v=Vn2v6ajA7U0&ab_channel=NeetCode

class Solution {
public:

    void subsets(int i,vector<int>& nums,vector<int>&a,vector<vector<int>>&ans){

        if(i==nums.size()){
            ans.push_back(a);
            return;
        }
        a.push_back(nums[i]);
        subsets(i+1,nums,a,ans);
        a.pop_back();
        while((i+1)<nums.size() && nums[i]==nums[i+1]){
            i=i+1;
        }
        subsets(i+1,nums,a,ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>a;
        sort(nums.begin(),nums.end());
        subsets(0,nums,a,ans);
        return ans;
    }
};