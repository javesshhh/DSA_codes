#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t; // for t test cases
    while(t--){
    int n;
    cin >> n;
    int sum = 0;
    while (n)
    {
        sum = sum + (n % 10); /// finding last digit of n and adding it to sum
        n = n / 10; //removing last digit of n
    }
    cout << sum << endl;
}
}