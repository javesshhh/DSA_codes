// Given 2d array a of N*N integers. Given Q queries and in each query given a,b,c and d
// print sum of square represented by (a,b) as top left point and(c,d)as bottom right point 
// Constraints
// 1<=N<=10^3
// 1<=a[i][j]<=10^9
// 1<=Q<=10^5
// 1<=a,b,c,d<=N

// #include <bits/stdc++.h>
// using namespace std;

// const int N=1e3+1;
// long long int arr[N][N]={0};

// int main() {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             cin>>arr[i][j];
//         }
//     }
//     int q;
//     cin>>q;
//     while(q--){
//         int a,b,c,d;
//         cin>>a>>b>>c>>d;
//         int sum=0;
//         for(int i=a;i<=c;i++){
//             for(int j=b;j<=d;j++){
//                 sum=sum+arr[i][j];
//             }
//         }
//         cout<<sum<<endl;
//     }
// }

// O(n^2) + O(q*N*N) == 1e5 * 1e3 * 1e3 == 1e11

#include <bits/stdc++.h>
using namespace std;

const int N=1e3+1;
long long int arr[N][N]={0};
long long int sum[N][N]={0};

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]=arr[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<sum[c][d]-sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1];
}
}

// O(n*n) + O(q) = O(n^2) = 1e6