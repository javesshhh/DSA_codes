// find factorial for n, 1<=n<=10^5

#include <bits/stdc++.h>
using namespace std;

// int main() {
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         int fact=1;
//         for(int i=1;i<=n;i++){
//             fact=fact*i;
//         }
//         cout<<fact<<endl;
//     }
// }
// complexity of above code is O(t*n), if t and n are nearly equal, then complexity is O(n^2)

// above complexity is n^2, so to reduce complexity we use method of pre-computation
// in this method, we pre-compute the required value and store it somewhere so it can be output when needed

int main() {
    long long int fact[100001];
    // at each index we store factorial of that index number
    // length is 100001 so as to store fact of last index that is 10^5
    fact[0]=fact[1]=1;
    for(int i=2;i<n;i++){
        fact[i]=fact[i-1]*i;           // factorials are pre-computed before test cases
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<fact[n]<<endl;
    }
}
// above code complexity is O(n)+O(t) = O(n)
// so we pre-stored values of factorial before test case loop to reduce complexity 
// and finally just printing factorial of n

// Another concept of pre-computation
// https://www.youtube.com/watch?v=4wqDE1zNUwc&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=22&ab_channel=Luv