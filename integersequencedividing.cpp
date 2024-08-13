// You are given an integer sequence 1,2,…,n. 
// You have to divide it into two sets A and B in such a way that each element belongs to exactly one set and |sum(A)−sum(B)| is minimum possible.
// Print one integer — the minimum possible value of |sum(A)−sum(B)| if you divide the initial sequence 1,2,…,n into two sets A and B.

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    cin>>n;
    // n %= 4;
    // if(n == 0 || n == 3){
    //     cout<<0<<endl;
    // }
    // else{
    //     cout<<1<<endl;
    long long int sum;
    sum=n*(n+1)/2; 
    if(sum%2==0) //here the basic logic is when the sum of all numbers is even, then set can be divided into two equal halves
    cout<<0<<endl;
    else         // else when sum is odd, difference will always be 1
       cout<<1<<endl;
    
}