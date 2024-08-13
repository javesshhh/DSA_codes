#include <bits/stdc++.h>
using namespace std;

void printVec ( vector <pair<int,int>> & v ) {
    cout << "size : " << v.size ( ) << endl ;
    for ( int i = 0 ; i < v.size ( ) ; ++ i ) {
        // v.size ( ) → > 0 ( 1 )
        cout << v[i].first << " " << v[i].second<<endl;;
        // assume v[i] as variable p, now consider it as 1st pair
        // so p.first will give first value of that pair and p.second will give its second value
        // ex. {1,2}, p.first -> 1 , p.second -> 2
    }
        cout << endl ;
}

int main() {
    vector<pair<int,int>> v;
    printVec(v);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    printVec(v);
}