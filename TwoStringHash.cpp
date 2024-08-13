// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/bob-and-string-easy/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string t;
        cin>>t;
        int hshs[26]={0};
        int hsht[26]={0};
        for(int i=0;i<s.length();i++)
        hshs[s[i]-97]++;
        for(int i=0;i<t.length();i++)
        hsht[t[i]-97]++;
        int x=0;
        for(int i=0;i<26;i++){
            if(hshs[i]==hsht[i]){
                continue;
            }
            else if(hshs[i]>hsht[i]){
                x=x+hshs[i]-hsht[i];
            }
            else{
                x=x-hshs[i]+hsht[i];
            }
        }
        cout<<x<<endl;
    }
}