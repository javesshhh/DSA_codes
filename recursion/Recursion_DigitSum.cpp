#include <bits/stdc++.h>
using namespace std;

int dsum(int n){
    if(n<=0) return 0;
    return n%10 + dsum(n/10);
}

int main() {
    int n;
    cin>>n;
    int sum=0;
    sum=dsum(n);
    cout<<sum;
}