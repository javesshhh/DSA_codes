#include <bits/stdc++.h>
using namespace std;

// Pair is used to combine together two values that may be of different data types.
// Pair provides a way to store two heterogeneous objects as a single unit.
// It is basically used if we want to store tuples

// CPP program to illustrate Pair in STL
// #include <iostream>
// #include <utility>
// using namespace std;

// int main()
// {
// 	// defining a pair
// 	pair<int, char> PAIR1;

// 	// first part of the pair
// 	PAIR1.first = 100;
// 	// second part of the pair
// 	PAIR1.second = 'G';

// 	cout << PAIR1.first << " ";
// 	cout << PAIR1.second << endl;

// 	return 0;
// }


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

int main(){
    vector<pair<int,int>> v = {{1,2},{2,3},{3,4}};
    // now in vector v, pair of integers will be stored
    printVec(v);
}
