#include <bits/stdc++.h>
using namespace std;

int palindrome(string &s,int i,int n){
    if(i>=n/2){
        return 1;
    }
    if(s[i]==s[n-i-1]){
        palindrome(s,i+1,n);
    }
    else if(s[i]!=s[n-i-1]){
        return 0;
    }
}

int main() {
    string s;
    cin>>s;
    int n=s.length();
    if(palindrome(s,0,n)==1){
        cout<<"palindrome"<<endl;
    }
    else if(palindrome(s,0,n)==0){
        cout<<"not"<<endl;
    }
}