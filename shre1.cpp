#include<bits/stdc++.h>
using namespace std;
const long long int m = 10e9+7 ;
const int n = 10e5 + 10 ;
long long int fact[n];

int main(){
    fact[0]=1;
    for (int i = 1; i < n; i++)
    {
        fact[i]=(fact[i-1]*i)%m;
    }
    int t ; 
    cin >> t ;
    while(t--){
        int x ;
        cin >> x ;
        cout << fact[x] << endl ;
    }

}