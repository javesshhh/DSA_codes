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
    vector<vector<int>>v;
    // now this is a 2d vector with both rows and columns of dynamic range

    for(int i=0;i<N;i++){
        int n;
        cin>>n;
        vector<int>temp;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    v[0].push_back(10);
    v.push_back(vector<int> ());
    for(int i=0;i<v.size();i++){
        printVec(v[i]);
    }
    cout<<v[0][1]<<endl;
    cout<<v[1][1]<<endl;
}