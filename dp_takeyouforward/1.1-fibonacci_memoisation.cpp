#include <bits/stdc++.h>
using namespace std;

int fibo(int n,vector<int>&dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    else return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
}

// time complexity : O(n) - this is bcoz we have to find fibonacci only one time for rest all time we wil store there values and just use them when needed
// space complexity : O(n)+O(n) - recursion stack space + vector of size n

int main() {
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);              // this is for memoisation
    cout<<fibo(n,dp)<<endl;
}