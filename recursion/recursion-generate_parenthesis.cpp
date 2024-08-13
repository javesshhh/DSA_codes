// https://www.youtube.com/watch?v=eyCj_u3PoJE&ab_channel=AdityaVerma
// https://leetcode.com/problems/generate-parentheses/

#include <bits/stdc++.h>
using namespace std;

void generatee(vector<string>&v,int open,int close, string &s){
    if(open==0 &&  close==0){
        v.push_back(s);
        return;
    }
    if(open!=0){
        // string s1=s;
        // s1.push_back('(');
        s.push_back('(');
        // generatee(v,open-1,close,s1);
        generatee(v,open-1,close,s);
        s.pop_back();                          // backtracking
    }
    if(close>open){
        // string s2=s;
        // s2.push_back(')');
        s.push_back(')');
        // generatee(v,open,close-1,s2);
        generatee(v,open,close-1,s);
        s.pop_back();                          // backtracking
    }
    return;
}

int main() {
    int n;
    cin>>n;
    int open=n;
    int close=n;
    vector<string>v;
    string s;
    generatee(v,open,close,s);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}