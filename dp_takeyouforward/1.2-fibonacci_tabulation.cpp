#include <bits/stdc++.h>
using namespace std;


// https://leetcode.com/discuss/study-guide/1971008/how-to-convert-top-down-to-bottom-up-in-dp-problem
// very nice article for tabulation



int main() {
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
}

// time complexity : O(n) - due to for loop
// space complexity : O(n) - due to vector of size n