#include <bits/stdc++.h>
using namespace std;

int main() {
    string s="aabaa";
    string rev;
     for(int i=s.length()-1;i>=0;i--){
        cout<<s[i];
        // another method
        
        rev.push_back(s[i]); // push_back add the s[i] in rev string after every iteration
     }
     cout<<endl<<rev<<endl;

     // to check palindrome
     if(s==rev)
     cout<<"yes"<<endl;
     else
     cout<<"no"<<endl;

     int c=0;
     //another method to check palindrome
     for(int i=0;i<=s.length()/2;i++){
         if(s[i]==s[s.length()-1-i])
         continue;
         else{
             c++;
             break;
         }
     }
     if(c==0)
     cout<<"yes"<<endl;
     else
     cout<<"no"<<endl;
}