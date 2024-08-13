// Micro purchased an array A having N integer values.
// In one second he can increase value of each array element by 1. He wants each array element's value to become greater than or equal to K.
// Please help Micro to find out the minimum amount of time it will take, for him to do so.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int low=INT_MAX;
    for(int i=0;i<n;i++){
        low=min(arr[i],low);
    }
    if(low>=k)
    cout<<0<<endl;
    else
    cout<<k-low<<endl;   
}
}