#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int temp=0;
    for(int i=0;i<n/2;i++){
        temp=arr[i];             // you can also use swap stl function to swap directly
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
    for(int i=0;i<n;i++)
    cout<<arr[i];
}