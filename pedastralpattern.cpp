#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[3]={3,2,1};
        for(int i=6;i<n;i++){
            if((i+1)%3==1)
            arr[0]++;
            else if((i+1)%3==2)
            arr[1]++;
            else
            arr[2]++;
        }
        cout<<arr[1]<<" "<<arr[0]<<" "<<arr[2]<<endl;
    }
}