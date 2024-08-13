// https://codeforces.com/problemset/problem/1535/B
// https://www.youtube.com/watch?v=OlhXre7CL9g&ab_channel=codeExplainer

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>v;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            v.push_back(arr[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]%2!=0){
            v.push_back(arr[i]);
        }
    }
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(__gcd(v[i],2*v[j])>1){
                c++;
            }
        }
    }
    cout<<c<<endl;
}
}