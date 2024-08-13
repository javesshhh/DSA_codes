// https://codeforces.com/problemset/problem/525/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    unordered_map <char,int>m;
    for(int i=0;i<2*n-2;i=i+2){
        m[s[i]]++;
        auto it=m.find(s[i+1]-'A'+'a');
        // this is to convert uppercase ascii to lowercase ascii
        //  and the decimal ascii type is converted to char as datatype for map is set to char
        // if(it!=m.end()){
        //     if(m[s[i+1]-'A'+'a']==0){
        //         cnt++;
        //     }
        // }
        if(it==m.end()){
            cnt++;
        }

        else if(it->second==0){
            cnt++;
        }

        else{
            m[s[i+1]-'A'+'a']--;
        }
    }
    cout<<cnt<<endl;
}