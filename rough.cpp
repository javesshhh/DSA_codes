#include <bits/stdc++.h>
using namespace std;

int fn(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
    if(i==s1.length() && j==s2.length()) return 0;
    if(i==s1.length()) return s2.length()-j;
    if(j==s2.length()) return s1.length()-i;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
        return dp[i][j]=fn(i+1,j+1,s1,s2,dp);
    }
    else{
        return dp[i][j]=min({fn(i+1,j+1,s1,s2,dp),fn(i+1,j,s1,s2,dp),fn(i,j+1,s1,s2,dp)});
    }
}

static bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<string>v(n);
    unordered_map<string,int>m;
    for(int i=0;i<n;i++){
        cin>>v[i];
        m[v[i]]=i;
    }
    int len=s.length();
    vector<pair<int,int>>pq;
    for(int i=0;i<n;i++){
        vector<vector<int>>dp(len,vector<int>(v[i].length(),-1));
        int a=fn(0,0,s,v[i],dp);
        pq.push_back({a,m[v[i]]});
    }
    sort(pq.begin(),pq.end(),cmp);
    vector<int>ans;
    for(int i=0;i<k;i++){
        cout<<pq[i].second<<endl;
    }
}