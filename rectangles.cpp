// some positive integer length n.perform exactly three cuts to get four parts of the stick.
// how many ways are there to split a stick into four parts so that it's possible to form a rectangle using these parts, but is impossible to form a square.
# include <bits/stdc++.h>
using namespace std;

int main()
{
    // long long int a;
    // cin >> a;
    // int count = 0;
    // for (int i = 1; i < a / 2; i++)
    // {
    //     if ((a - 2 * i) % 2 == 0 && a != 4 * i)
    //         count++;
    // }
    // cout << count / 2 << endl;

    long long int a;
    cin >> a;
    int x = a/2; // length+breadth=a/2
    if(a%2!=0) cout<<0<<endl; //for odd length - not possible
    else {
    if(x%2){
        cout<<x/2; 
    }
    else 
    cout<<(x/2)-1;
}
}