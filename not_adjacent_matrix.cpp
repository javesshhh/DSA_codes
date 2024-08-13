// https://codeforces.com/problemset/problem/1520/C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n][n];
        int k=0;
        if(n==1){
            cout<<1<<endl;
        }
        else if(n==2){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if((i+j)%2==0){
                        a[i][j]=++k;
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if((i+j)%2!=0){
                        a[i][j]=++k;
                    }
                }
            }
            for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
        }
    }
    }
}