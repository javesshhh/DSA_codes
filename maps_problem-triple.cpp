// https://codeforces.com/contest/1669/problem/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        unordered_map<int,int>m;
        int count=0;
        int value=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]++;
        }
        for(int i=0;i<n;i++){
            int test=m[a[i]];
            if(test>=3){
                value=a[i];
                count=1;
                break;
            }
        }
        if(count==0){
            cout<<-1<<endl;
        }
        else if(count==1){
            cout<<value<<endl;
        }
    }
}