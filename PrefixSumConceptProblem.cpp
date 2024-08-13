// Starting with a 1-indexed array of zeros and a list of operations,for each operation add a value to 
// each of the array element between two given indices,inclusive. Once all operations have been performed,
// return the maximum value in the array.


// BRUTE FORCE CODE

// #include <bits/stdc++.h>
// using namespace std;
// const int N=1e7+10;
// long long int ar[N];

// int main(){
//     int n,m;
//     cin >>n>>m;
//     while(m--){
//         int a,b,d;
//         cin >>a>>b>>d;
//         for(int i=a;i<=b;++i){
//             ar[i]+=d;
//         }
//     }
//     long long mx=-1;
//     for(int i=1;i<=n;++i){
//         if(mx<ar[i]){
//             mx=ar[i];
//         }
//     }
//     cout << mx << endl;
// }

// https://www.youtube.com/watch?v=4wqDE1zNUwc&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=23&ab_channel=Luv
// # CONCEPT

#include <bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long int ar[N];

int main(){
    int n,m;
    cin >>n>>m;
    while(m--){
        int a,b,d;
        cin >>a>>b>>d;
        ar[a]+=d;
        ar[b+1]-=d;
    }
    for(int i=1;i<=n;i++){
        ar[i]=ar[i]+ar[i-1];
    }
    long long mx=-1;
    for(int i=1;i<=n;++i){
        if(mx<ar[i]){
            mx=ar[i];
        }
    }
    cout << mx << endl;
}
