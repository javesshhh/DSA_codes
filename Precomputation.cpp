// Given array a of N integers.Given Q queries
// and in each query given L and R print sum of
// array elements from index L to R (L,R included)

// Constraints
// 1<=N<=10^5
// 1<=a[i]<=10^9
// 1<=Q<=10^5
// 1<=L,R<=N
// as L and R are starting from 1, so indexing of array will be 1 based

// #include <bits/stdc++.h>
// using namespace std;

// const int n=1e5+10;   // size of array greater than 1e5
// int a[n]={0};

// int main() {
//     int n;
//     cin >>n;
//     for(int i=1;i<=n;i++){
//     cin >>a[i];
//     }
//     int q;
//     cin >>q;

//     while(q--){
//     int l,r;
//     cin >>l>>r;
//     long long sum=0;
//     for(int i=l;i<=r;i++){
//         sum+=a[i];
//    }
//     cout << sum << endl;
//     }
// }

// this in O(n2) complexity code
// can be optimised if we store the sums initially, technique c/a Prefix sum

#include <bits/stdc++.h>
using namespace std;

const int n=1e5+10;
int a[n]={0};
int sum[n]={0};

int main() {
    int n;
    cin >>n;
    for(int i=1;i<=n;i++){
    cin >>a[i];
    }
    sum[1]=a[1];
    for(int i=2;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int q;
    cin>>q;
    while(q--){
    int l,r;
    cin >>l>>r;
    cout << sum[r]-sum[l-1] << endl;
    }
}

// its complexity is O(n) -- optimised code