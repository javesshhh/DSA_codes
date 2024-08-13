#include <bits/stdc++.h>
using namespace std;

int main() {

    //simple parenthesis

    // string s;
    // cin>>s;
    // stack<char>st;
    // for(int i=0;i<s.size();i++){
    //     if(s[i]=='('){
    //         st.push(s[i]);
    //     }
    //     else if(s[i]==')'){
    //         if(st.empty()){
    //             goto end;
    //         }
    //         else{
    //             st.pop();
    //         }
    //     }
    // }
    // if(st.empty()){
    //     cout<<"yes"<<endl;
    // }
    // else{
    //     end:
    //     cout<<"no"<<endl;
    // }
    // return 0;


    // all types of parenthesis

    string s;
    cin>>s;
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')' || s[i]=='}' || s[i]==']'){
            if(st.empty() || (s[i]==')' && st.top()!='(') || (s[i]=='}' && st.top()!='{') || (s[i]==']' && st.top()!='[')){
                goto end;
            }
            else{
                st.pop();
            }
        }
    }
    if(st.empty()){
        cout<<"yes"<<endl;
    }
    else{
        end:
        cout<<"no"<<endl;
    }
    return 0;
}

// ANOTHER LOGIC
// https://www.youtube.com/watch?v=q-JB0hYyouo&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=40&ab_channel=Luv