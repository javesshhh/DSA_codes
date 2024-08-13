#include <bits/stdc++.h>
using namespace std;

int main(){
    // simply rotating array by 1 position clockwise
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++)
    // cin>>arr[i];
    // int arr1[n]={0};
    // arr1[0]=arr[n-1];
    // for(int i=1;i<=n-1;i++)
    // arr1[i]=arr[i-1];
    // for(int i=0;i<n;i++)
    // cout<<arr1[i];

    // another method to rotate array by k position clockwise

    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    // now to rotate array by k length, 
    // store the last k length subarray into another array 
    // and shift the rest elements by k index
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i]=arr[n-k+i];
    }
    int arr1[n];
    for(int i=0;i<n;i++)     // copying an array into another array
    arr1[i]=arr[i];
    for(int i=0;i<n-k;i++)   // shifting the rest elements by k index
    arr[i+k]=arr1[i];
    for(int i=0;i<k;i++)     // copying subarray into original array
    arr[i]=temp[i];
    for(int i=0;i<n;i++)
    cout<<arr[i];
}

// this approach has time complexity of O(n)
// but space complexity is high of S(n)
// another method will be of space complexity S(1) in file rotatingarray2
