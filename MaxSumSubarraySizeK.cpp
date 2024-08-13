// Problem link
// https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
// Article link
// https://www.geeksforgeeks.org/find-maximum-minimum-sum-subarray-size-k/


// Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.
// You don't need to read input or print anything. Your task is to complete
// the function maximumSumSubarray() which takes the integer k,
// vector Arr with size N, containing the elements of the array and
// returns the maximum sum of a subarray of size K.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<=N<=106
// 1<=K<=N

// A Simple Solution is to generate all subarrays of size k, compute their sums and finally return
// the maximum of all sums. The time complexity of this solution is O(n*k).

// but we need complexity to be O(n)

// An Efficient Solution is based on the fact that sum of a subarray (or window) of size k can
// be obtained in O(1) time using the sum of the previous subarray (or window) of size k. 
// Except for the first subarray of size k, for other subarrays, we compute the sum by removing 
// the first element of the last window and adding the last element of the current window.

// //////// this is the function written, passed on gfg /////////////////////

// long maximumSumSubarray(int K, vector<int> &Arr , int N){
//         long long int hsh[N-K+1]={0};
//         long long int sum1=0;
//     for(int i=0;i<K;i++){
//         sum1=sum1+Arr[i];
//     }
//     hsh[0]=sum1;
//     for(int i=0;i<N-K;i++){
//         sum1=sum1-Arr[i]+Arr[i+K];
//         hsh[i+1]=sum1;
//     }
//     sort(hsh,hsh+N-K+1);
//     return hsh[N-K];
//     }


//////////// the actual complete code //////////////////////

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    int arr[n];
    int hsh[n-k+1]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum1=0;
    for(int i=0;i<k;i++){
        sum1=sum1+arr[i];
    }
    hsh[0]=sum1;
    for(int i=0;i<n-k;i++){
        sum1=sum1-arr[i]+arr[i+k];
        hsh[i+1]=sum1;
    }
    sort(hsh,hsh+n-k+1);
    cout<<hsh[n-k]<<endl;
}