// https://leetcode.com/problems/jump-game/description/


// recursion

class Solution {
public:
    
    bool fn(int i,vector<int>& nums,int n,vector<int>&dp){
        if(i>=n-1){
            return true;
        }
        // if(i>n-1){
        //     return false;
        // }
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j=1;j<=nums[i];j++){
            if(fn(i+j,nums,n,dp)==true){
                return dp[i]=true;
            }
        }
        return dp[i]= false;
    }
    
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return fn(0,nums,n,dp);
    }
};


// memoization

class Solution {
public:
    
    bool fn(int i,vector<int>& nums,int n,vector<int>&dp){
        if(i==n-1){
            return true;
        }
        if(i>n-1){
            return false;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j=1;j<=nums[i];j++){
            if(fn(i+j,nums,n,dp)==true){
                return dp[i]=true;
            }
        }
        return dp[i]= false;
    }
    
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return fn(0,nums,n,dp);
    }
};


