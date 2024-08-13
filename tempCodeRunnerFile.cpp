#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    whike(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int a=0,b=0,c=0,d=0;
        for(auto it:s){
            if(s[i]=='A') a++;
            if(s[i]=='B') b++;

            if(s[i]=='C') c++;
            else d++;
         }
         cout<<min(a,n)+min(b,n)+min(c,n)+min(d,n)<<endl;
    }
}