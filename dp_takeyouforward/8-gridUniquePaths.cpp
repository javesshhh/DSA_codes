// https://www.youtube.com/watch?v=sdE0A2Oxofw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=9&ab_channel=takeUforward
// https://takeuforward.org/data-structure/grid-unique-paths-dp-on-grids-dp8/
// https://leetcode.com/problems/unique-paths/description/
// https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-unique-paths5339

// recursive

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1){
            return 1;
        }
        if(m<0 || n<0){
            return 0;
        }
        int up=uniquePaths(m-1,n);
        int left=uniquePaths(m,n-1);
        return up + left;
    }
};


// memoization

class Solution {
public:
    int paths(int m, int n,vector<vector<int>>&dp) {
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        if(m==0 && n==0){
            return 1;
        }
        if(m<0 || n<0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int up=paths(m-1,n,dp);
        int left=paths(m,n-1,dp);
        return dp[m][n]= up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return paths(m-1,n-1,dp);
    }
};


// tabulation

class Solution {
public:



    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[0][0]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int up=0;
                int left=0;
                if(i==0 && j==0){
                    dp[0][0]=1;
                    continue;
                }
                if(i-1>=0) up=dp[i-1][j];
                if(j-1>=0) left=dp[i][j-1];
                dp[i][j]= up + left;
            }
        }
        return dp[m-1][n-1];
    }
};