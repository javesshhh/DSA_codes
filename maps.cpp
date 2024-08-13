#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int,string>m1;
    // take first datatype which you want unique and second as frequency of first
    m1[1]="abc";  
    m1[5]="cde";   // O(log n)
    m1[3]="fgh";
    m1.insert({4,"xyz"});
    for(auto it=m1.begin();it!=m1.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    cout<<endl;

    map<string,int>m2;
    // take first datatype which you want unique and second as frequency of first
    m2.insert({"abc",1});
    m2.insert({"cde",5});
    m2.insert({"fgh",3});
    m2.insert({"xyz",4});
    for(auto it=m2.begin();it!=m2.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    //no values are repeated in maps
    // maps print the elements of vectors in sorted order (lexographical order)
    // while unordered maps print elements in unsorted (actual order)

    cout<<endl;

    auto it=m1.find(5);
    if(it==m1.end()){
        cout<<"no find"<<endl;
    }
    else if(it!=m1.end()){
        // if it is .end then no such value is present in map else it is present
        cout<<"yes found"<<endl;
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    m1.erase(4);  // O(log n)
    for(auto it=m1.begin();it!=m1.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    cout<<endl;
    auto itt=m1.find(7);
    if(itt!=m1.end()){
        m1.erase(itt);
    }
    for(auto it=m1.begin();it!=m1.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    m2.clear();
    for(auto it=m2.begin();it!=m2.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    // unordered maps
    cout<<endl;

    unordered_map<int,string>m3;
    // take first datatype which you want unique and second as frequency of first
    m3[1]="abc";  
    m3[5]="cde";   // O(log n)
    m3[3]="fgh";
    m3.insert({4,"xyz"});
    for(auto it=m3.begin();it!=m3.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    cout<<endl;

    unordered_map<string,int>m4;
    // take first datatype which you want unique and second as frequency of first
    m4.insert({"abc",1});
    m4.insert({"cde",5});
    m4.insert({"fgh",3});
    m4.insert({"xyz",4});
    for(auto it=m4.begin();it!=m4.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    // in ordered maps, no sorted printing occurs
    // so complexity of every operation here is o(1)
    // so whenever order doesn't matter then use unordered sets
}