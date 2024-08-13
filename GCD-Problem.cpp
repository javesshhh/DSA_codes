// You are given an array A of integers of size N. You will be given Q queries where
// each query is represented by two integers L, R. You have to find the gcd (Greatest
// Common Divisor) of the array after excluding the part from range L to R inclusive
// (1 Based indexing).You are guaranteed that after excluding the part of the array
// remaining array is non empty.

// Input
// • First line of input contains an integer T denoting number test cases.
// For each test case,first line will contain two space separated integers N,Q.
// • Next line contains N space separated integers denoting array A
// For next Q lines, each line will contain a query denoted by two space
// separated integers L,R

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int t;
//     cin>>t;
//     while(t--){
//         int n,q;
//         cin>>n>>q;
//         int arr[n+1]={0};
//         for(int i=1;i<=n;i++){
//             cin>>arr[i];
//         }
//         while(q--){
//             int l,r;
//             cin>>l>>r;
//             int gc=0;                // as gcd of any no. with 0 is the number itself
//             // we could have also initialised gc as arr[1];
//             // both would work the same
//             for(int i=1;i<=l-1;i++){
//                 gc=__gcd(gc,arr[i]);    // __gcd() is inbuilt stl function
//             }
//             for(int i=r+1;i<=n;i++){
//                 gc=__gcd(gc,arr[i]);    // l to r are excluded and rest elements gcd is calculated
//             }
//             cout<<gc<<endl;
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int arr[n+10]={0};
        int fwd[n+10];
        int bck[n+10];
        fwd[0]=bck[n+1]=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<=n;i++){
            fwd[i]=__gcd(fwd[i-1],arr[i]);
        }
        for(int i=n;i>=1;i--){
            bck[i]=__gcd(bck[i+1],arr[i]);
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            cout<<__gcd( fwd[l-1],bck[r+1])<<endl;
        }
    }
}

// Video link for explanation
// https://www.youtube.com/watch?v=e3qhRh4UOug&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=24&ab_channel=Luv