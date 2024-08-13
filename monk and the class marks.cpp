// problem
// https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/?fbclid=IwAR09BMLG-1NhqDlVQq0KIzSr8ZTgqrbJmdfnsXc7KnDiphgX5UmbFLoEYjE

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin>>n;
//     map<int,set<string>> data;
//     for(int i=0;i<n;i++){
//         string name;
//         int marks;
//         cin>>name>>marks;
//         data[marks].insert(name);
//     }
//     // for(auto it=data.begin();it!=data.end();it++){
//     //     for(auto i=(*it).second.begin();i!=(*it).second.end();i++){
//     //         cout<<(*it).first<<" "<<(*i)<<endl;
//     //     }
//     // }

//     auto itt=data.end();
//     itt--;

//     auto a = (data.begin());
//     // a--;
//     auto it=itt;
//     for(auto it=itt;it!=a;it--){
//         for(auto ii=(*it).second.begin();ii!=(*it).second.end();ii++){
//             cout<<(*ii)<<" "<<(*it).first<<endl;
//         }
//     }
//     it--;
//            for(auto ii=(*it).second.begin();ii!=(*it).second.end();ii++){
//             cout<<(*ii)<<" "<<(*it).first<<endl;
//            }
// }

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string,int>x,pair<string,int>y){
    if(x.second!=y.second){
        return x.second>y.second;
    }
    else{
        return x.first<y.first;
    }
}

int main() {
    int n;
    cin>>n;
    vector<pair<string,int>>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n;i++){
        cout<<a[i].first<<" "<<a[i].second<<endl;
    }
}