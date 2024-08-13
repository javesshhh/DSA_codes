#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int prev2=0;
    int prev=1;
    for(int i=2;i<=n;i++){
        int cur=prev+prev2;
        prev2=prev;
        prev=cur;
    }
    cout<<prev<<endl;
}

// time complexity : O(n) - due to for loop
// space complexity : O(1) - as we have eliminated use of vector space by using O(1) operation of just summing