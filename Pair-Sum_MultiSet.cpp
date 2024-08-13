// You have been given an integer array A and a number K. Now, you need to find out
// whether any two different elements of the array A sum to the number K. Two elements
// are considered to be different if they lie at different positions in the array. If there exists
// such a pair of numbers, print "YES" (without quotes), else print "NO" without quotes.






// THIS IS INCORRECT APPROACH



// #include <bits/stdc++.h>
// using namespace std;

// const int m=1e6+1;
// int hsh[m]={0};

// int main() {
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//         hsh[arr[i]]++;
//     }
//     int c=0;
//     for(int i=0;i<m,k-i>=0;i++){
//         if(hsh[i]!=0 && hsh[k-i]!=0){
//             c=1;
//             break;
//         }

//         else
//             continue;
//     }
//     if(c==1)
//         cout<<"YES"<<endl;
//     else
//         cout<<"NO"<<endl;
// }







// THIS IS CORRECT APPROACH



// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     sort(arr,arr+n);
//     int i=0,j=n-1;
//     int c=0;
//     while(i<j){
//         if(arr[i]+arr[j]==k){
//             cout<<"YES"<<endl;
//             c=1;
//             break;
//         }
//         else if(arr[i]+arr[j]<k){
//             i++;
//         }
//         else{
//             j--;
//         }
//     }
//     if(c==0){
//         cout<<"NO"<<endl;
//     }
// }

// THIS IS CORRECT APPROACH

#include <bits/stdc++.h>

using namespace std;

int main()

{
    int n, k, r;

    cin >> n >> k;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        cin >> r;
        v.push_back(r);
    }

    multiset<int> s;

    for (int i = 0; i < n; i++)
    {
        if (s.find(k - v[i]) != s.end())
        {
            cout << "YES" << endl;
            return 0;
        }
        s.insert(v[i]);
    }
    cout << "NO" << endl;
    return 0;
}