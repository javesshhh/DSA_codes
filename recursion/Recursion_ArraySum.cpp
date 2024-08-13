#include <bits/stdc++.h>
using namespace std;

int arrsum(int n,int arr[]){
    if(n==0) return 0;
    return arr[n-1]+arrsum(n-1,arr);
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=arrsum(n,arr);
    cout<<sum;
}