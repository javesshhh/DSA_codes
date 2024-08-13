// A school method based C++ program to check if a
// number is prime
#include <bits/stdc++.h>
using namespace std;
 
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i < n; i++){
        if (n % i == 0)
            return false;
    }
 
    return true;
}

int main(){
    int n;
    cin>>n;
    if(isPrime(n))
    cout<<"prime"<<endl;
    else
    cout<<"not prime"<<endl;
}
