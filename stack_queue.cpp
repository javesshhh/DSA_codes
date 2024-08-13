#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int>s;
    s.push(2);
    s.push(1);
    s.push(4);
    s.push(7);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    queue<string>q;
    q.push("abc");
    q.push("bfg");
    q.push("xsd");
    q.push("sdf");
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
}