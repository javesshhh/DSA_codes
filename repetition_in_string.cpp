// https://cses.fi/problemset/task/1069/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    long long int cnt=1;
    long long int maxx=0;
    for(long long int i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1]){
            cnt++;
        }
        else{
            maxx=max(maxx,cnt);
            cnt=1;
        }
    }

    // the case when repetitions lasts till last,  then we wont be able to max the maxx, so doing it outside the loop
    maxx=max(maxx,cnt);
            cnt=1;
    cout<<maxx;
}