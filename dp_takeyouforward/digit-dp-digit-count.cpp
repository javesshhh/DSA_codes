// https://lightoj.com/problem/digit-count
// https://www.youtube.com/watch?v=T6rERN8-lhQ&list=PLJSqVBBfSpyz_Lb0Baqg2V7cjAg3Rz3yz&ab_channel=ParasSaini

#include <bits/stdc++.h>
#define int long long int
#define mii map<int,int>
#define umii unordered_map<int,int>
#define pii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define tc int t; cin>>t; while(t--)
#define pb push_back
#define ppb pop_back()
#define gcd(a, b) __gcd(a, b)
#define fr(a,b) for(int i = a; i < b; i++)
#define frr(a,b) for(int i = a; i >= b; i--)
#define vin(a,n) for(int i=0;i<n;i++) cin>>a[i]
#define vout(a) for(auto x : a){cout<<x<<" ";} cout<<'\n'
#define yes cout<<"YES"<<'\n'
#define no cout<<"NO"<<'\n'
#define ret(a) cout<<a<<'\n'
#define mod 1000000007
using namespace std;

int power(int neeche, int upar) {
    if (upar == 0)
        return 1;
    int rizzress = power(neeche, upar / 2);
    if (upar % 2!=0)
        return rizzress * rizzress * neeche;
    else if (upar % 2==0)
        return rizzress * rizzress;
}

int dp[12][12];

int g(int pos,int prev,int m,vector<int>s){
    int res=0;
    if(pos==m){
        return 1;
    }
    if(dp[pos][prev]!=-1){
        return dp[pos][prev];
    }
    for(int j=0;j<s.size();j++){
        if(prev==0 || abs(prev-s[j])<=2){
            res=res+g(pos+1,s[j],m,s);
        }
    }
    return dp[pos][prev]=res;
}

signed main() {
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        int m;
        cin>>m;
        int n;
        cin>>n;
        vector<int>s(m);
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            s[i]=x;
        }
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<i<<": "<<g(0,0,n,s)<<endl;
        i++;
    }
    return 0;
}