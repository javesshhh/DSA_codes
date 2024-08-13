/*
Given array a of N integers.Given Q queries
and in each query given a number X,print
count of that number in array.
Constraints
1<=N<=10^5
1<=a[i]<=10^7
1<=Q<=10^5
*/

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     cin>>arr[i];
//     int q;
//     cin>>q;
//     while(q--){
//         int x;
//         cin>>x;
//         int count=0;
//         for(int i=0;i<n;i++){
//             if(arr[i]==x)
//             count++;
//         }
//         cout<<count<<endl;
//     }
// }

// complexity of above code is O(n)+O(q*n), if q and n are nearly equal, then complexity is O(n^2)
// above complexity is n^2, so to reduce complexity we use method of pre-computation hashing
// in this method, we pre-compute the required value and store it in hash array so it can be output when needed

#include <bits/stdc++.h>
using namespace std;

const int m=1e7+1;
int hsh[m];
// in hashing we always declare global array for maximum size limit
// global arrays are always initialised with 0 at every index
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
    cin>>arr[i];
    hsh[arr[i]]++;
    }
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        cout<<hsh[x]<<endl;              // here value at each index gives count of that index number
    }
}

// to store negative number in hash array, u can either use maps
// or u can add certain number to make hash array start from 0 index
// eg. we have to store numbers ranging from -6 to 5, so add 6 to every number and locate any number by adding 6 to index