#include <bits/stdc++.h>
using namespace std;

void rev(int *arr,int i){
    if(i>=2){
        return;
    }
    swap(arr[i],arr[5-i-1]);
    rev(arr,i+1);
}

int main() {
    int arr[5]={1,2,8,5,6};
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    rev(arr,0);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}