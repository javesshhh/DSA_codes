// https://www.youtube.com/watch?v=R_Mfw4ew-Vo&ab_channel=takeUforward
// https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>
#define int long long int
using namespace std;

int fn(vector<int>&arr,int mid,int c){
    int cnt=1;
    int prev=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]-prev>=mid){
            cnt++;
            prev=arr[i];
        }
        if(cnt>=c) return 1;
    }
    return 0;
}

signed main() {
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int c;
        cin>>c;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int i=1;
        int j=arr[n-1]-arr[0];
        int ans;
        while (i<=j)
        {
            int mid=i+(j-i)/2;
            if(fn(arr,mid,c)){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}