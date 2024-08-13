#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {2, 3, 4, 5, 7};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // vector<int>::iterator it = v.begin();
    // // .begin points to 1st element  or 0th index of vector
    // // .end points to the next of the last index, that is out of length of vector v, next to last element

    // for (it = v.begin(); it != v.end(); it++)
    // {
    //     cout << (*it) << endl;
    // }

    vector < pair<int, int>>v_p={{1,2},{2,3},{3,4}};
    vector < pair<int, int>>:: iterator it=v_p.begin();
    for (it = v_p.begin(); it ! = v_p.end(); ++it){
        cout << (*it).first << " " << (*it).second<<endl;
    }
    for (it = v_p.begin(); it ! = v_p.end(); ++it){
        cout << (it - > first) << " " << (it - > second)<<endl;
    }
    // ( * itt ) .first <=> ( itt- > first )
}