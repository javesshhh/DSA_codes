#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int arr[3];
        arr[0]=a;
        arr[1]=b;
        arr[2]=c;
        sort(arr,arr+3);
        if(a==b && b==c && c==a){
            cout<<"yes"<<endl;
        }
        if(arr[0]==arr[1])
        cout<<"yes"<<endl;
        else
        cout<<"no"<<endl;
    }
}