#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        int high=arr[0]+arr[n-1];
        for(int k=1;k<n;k++){
            for(int i=0;i<n-k;i++){
                swap(arr[i],arr[n-k-1-i]);
            }
            for(int i=0;i<k;i++){
                swap(arr[n-k+i],arr[n-1-i]);
            }
            for(int i=0;i<n;i++){
                swap(arr[i],arr[n-1-i]);
            }
            int z=arr[0]+arr[n-1];
            high=max(high,z);
        }
        cout<<high<<endl;
    }
}