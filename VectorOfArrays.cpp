#include <bits/stdc++.h>
using namespace std;

void printVec ( vector <int> & v ) {
    cout << "size : " << v.size ( ) << endl ;
    for ( int i = 0 ; i < v.size ( ) ; ++ i ) {
        // v.size ( ) → > 0 ( 1 )
        cout << v[i];
        // assume v[i] as variable p, now consider it as 1st pair
        // so p.first will give first value of that pair and p.second will give its second value
        // ex. {1,2}, p.first -> 1 , p.second -> 2
    }
        cout << endl ;
}

int main() {
    int N;
    cin>>N;
    vector<int>v[N];
    // this is not vector of length N, instead it is N numbers of vectors of initial length 0
    for(int i=0;i<N;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }
    for(int i=0;i<N;i++){
        printVec(v[i]);
    }
    cout<<endl;
    cout<<v[0][1]<<endl;
    cout<<v[1][1]<<endl;
}