// https://codeforces.com/problemset/problem/1521/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        long long int a,b;
        cin>>a>>b;
        if(b==1){
            cout<<"NO"<<endl;
        }
        else if(b==2){
            cout<<"YES"<<endl;
            cout<<a<<" "<<a*b<<" "<<a*(b+1)<<endl;
        }
        else{
            cout<<"YES"<<endl;
            cout<<a<<" "<<a*(b-1)<<" "<<a*b<<endl;
        }
    }
}