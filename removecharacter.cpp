// Given two strings string1 and string2
// remove those characters from first string(string1) which are present in second string(string2).
// NOTE: Size of  first string is always greater than the size of  second string
// returns the result string after removing characters from string2  from string1

#include <bits/stdc++.h>
using namespace std;

int main() {
    // this code is wrong as it removes only a unique char at a time
// string s1,s2,s;
// cin>>s1>>s2;
// for(int i=0;i<s2.length();i++){
//     for(int j=0;j<s1.length();j++){
//         if(s1[j]==s2[i])
//         continue;
//         else if(s1[j]!=s2[i])
//         s.push_back(s1[j]);
//     }
// }
// cout<<s<<endl;

string s1,s2;
    cin>>s1>>s2;
    int hash[26] = {0};
    for(int i=0;i<s2.size();i++){
       hash[s2[i]-'a'] = 1;          // hash array of characters
       // s2[i]-'a' -> this is int operation so ascii values are operated
       // elements of str2 are counted 1 in character hash array starting from a to z
    }
    string ans = "";
    for(int i=0;i<s1.length();i++){
        if(hash[s1[i]-'a']==0){    // iterating over elements of str1, if hash count is zero, pushback this required char
            ans.push_back(s1[i]);
        }
    }
    cout<<ans<<endl;
}