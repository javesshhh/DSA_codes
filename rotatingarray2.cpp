#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int temp1=0;
    for(int i=0;i<(n-k)/2;i++){
        temp1=arr[i];                       // reversing last k length subarrray
        arr[i]=arr[n-k-1-i];
        arr[n-k-1-i]=temp1;
    }
    int temp2=0;
    for(int i=n-k;i<k/2;i++){
        temp2=arr[i];                       // reversing first n-k length subarray
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp2;
    }
    int temp3=0;
    for(int i=0;i<n/2;i++){
        temp3=arr[i];                       // reversing the complete array to get desired array
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp3;
    }
     for(int i=0;i<n;i++)
    cout<<arr[i];

}