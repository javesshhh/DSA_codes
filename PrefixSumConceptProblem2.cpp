// Luffy with his crew is on the way to Dressrosa,where he will be fighting one of the warlords of the sea Doflamingo.But now
// he is getting bored and wants do a fun activity.He is very much obsessed with palindromes.Given a string S of lower case
// English alphabet of length N and two Integers L and R he wants to know whether all the letters of the substring from index L
// to R(L and R included)can be rearranged to form a palindrome or not.He wants to know this for Q values of L and R and
// needs your help in finding the answer.
// Palindrome is a string of characters which when reversed reads same as the original String.

// https://www.youtube.com/watch?v=zwlCeWUGlE0&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=23&ab_channel=Luv

#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
cin>>t;
while(t--){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    while(q--){
        int l,r;
        cin>>l>>r;
        int hsh[26]={0};
        l--;
        r--;
        for(int i=l;i<=r;i++){
            hsh[s[i]-97]++;
        }
        int odd=0;
        for(int i=0;i<26;i++){
            if(hsh[i]%2!=0){
                odd++;
            }
        }
        if((r-l+1)%2==0 && odd==0){
            cout<<"Yes"<<endl;
        }
        if((r-l+1)%2!=0 && odd==1){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}
}