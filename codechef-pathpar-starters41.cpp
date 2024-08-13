// in such problems try to take different cases of odd and even numbers and try to analyse them
// we took case as n as even
// n=4
// 1 5 9  13
// 2 6 10 14
// 3 7 11 15
// 4 8 12 16 and like this pattern for n=6 or 8 or ....
// we took case as n is odd
// n=5
// 1 6  11 16 21
// 2 7  12 17 22
// 3 8  13 18 23
// 4 9  14 19 24
// 5 10 15 20 25 and like this pattern for n=7 or 9 or ....

// for sum we can go in any way we want, but just right and down movement allowed
// n even - parity of both 0 and 1 possible
// n odd -  parity of only 1 is possible // sum will never be even for any path possible
// this question is just observation and analysis based

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(n%2!=0 && k%2==0)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
}