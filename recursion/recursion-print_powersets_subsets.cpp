// https://www.youtube.com/watch?v=AxNNVECce8c&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=6&ab_channel=takeUforward
// concept

// https://leetcode.com/problems/subsets/
// problem


void generate(int i,vector<int>&nums,vector<int>&a,vector<vector<int>>&ans,int n){
        if(i==n) {
            ans.push_back(a);
            return;}
        a.push_back(nums[i]);           // element included in vector
        generate(i+1,nums,a,ans,n);
        a.pop_back();
        generate(i+1,nums,a,ans,n);     // last element not included in vector
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>a;
        int n=nums.size();
        generate(0,nums,a,ans,n);
        return ans;
    }