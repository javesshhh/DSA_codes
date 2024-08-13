#include <bits/stdc++.h>
using namespace std;

int fn(int prev,int i,vector<int>v){
    if(i>=v.size()) return 0;
    if(i<=2*prev + 1){
        return min(fn(prev,i+1,v),fn(i,i+1,v)+v[i]);
    }
    else{
        return fn(i,i+1,v)+v[i];
    }
}

int main() {
    return fn(1,0,v);
}