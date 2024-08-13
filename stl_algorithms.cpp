#include <bits/stdc++.h>
using namespace std;

int main() {
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    // int x;
    // cin>>x;
    // sort(arr,arr+n);        // lowerbound and upperbound fn operate on sorted array in log n complexity otherwise o(n) complexity for unsorted array
    // int *ptr1=lower_bound(arr,arr+n,x);
    // // lowerbound returns pointer of value x
    // // if x is present in array then it returns that pointer and if not then address of next greater element

    // int *ptr2=upper_bound(arr+2,arr+n;x);         // here we can also give restricted range
    // // upperbound returns pointer of value x
    // // even if x is present in array then also it returns address of next greater element

    // if(ptr2==(arr+n)){
    //     cout<<"not found"<<endl;
    // }
    // else{
    //     cout<<(*ptr2)<<endl;
    // }

    vector<int>v={6,4,5,25,5,8,7};
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    // auto it=lower_bound(v.begin(),v.end(),6);
    // auto it=lower_bound(v.begin(),v.end(),9);
    auto it=upper_bound(v.begin(),v.end(),6);
    // auto it=upper_bound(v.begin(),v.end(),25);
    if(it==v.end()){
        cout<<"not found"<<endl;
    }
    else{
        cout<<(*it)<<endl;
    }
    // cout<<(*it)<<endl;
    // set<int>s;
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     s.insert(x);
    // }
    // auto it1=s.lower_bound(5);          // this is the way to use lowerbound upperbound in set map
    // cout<<(*it1)<<endl;

    // // in maps, lb ub are applicable only on key

    int min=*min_element(v.begin(),v.end());        // min_element returns address
    cout<<min<<endl;
    int max=*max_element(v.begin(),v.end());        // max_element returns address
    cout<<max<<endl;
    int sum=accumulate(v.begin(),v.end(),0);        // returns value
    // accumulate(staring index,ending index,initial sum)
    cout<<sum<<endl;
    int ct=count(v.begin(),v.end(),5);              // returns freq of that number
    cout<<ct<<endl;
    // auto element=find(v.begin(),v.end(),8);
    auto element=find(v.begin(),v.end(),9);         // find element in vector
    if(element!=v.end()){
        cout<<*element<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

    string s="dhfdjfsdkf";
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it;
    }
    cout<<endl;
    reverse(v.begin(),v.end());
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it;
    }
    cout<<endl;
}