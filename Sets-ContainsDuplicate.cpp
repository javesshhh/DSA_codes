// Given an integer array nums, return true if any value appears at least twice in the array,
// and return false if every element is distinct.

// Constraints:

// 1 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9

// Here we cant use hash array bcoz we cant declare 1e9 length array even globally
// So here we used sets to overcome this issue

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,r;
    cin>>n;
    vector <int> nums;
    for (int i = 0; i < n; i++){
        cin >> r;
        nums.push_back(r);
    }
    set<int> temp;
    int c=0;
    for(int i=0;i<nums.size();i++)
    {
    if(temp.find(nums[i]) != temp.end())
    {
    cout<<"duplicate"<<endl;
    return 0;
    }
    else
    {
    temp.insert(nums[i]);
    }
    }
    cout<<"no duplicate"<<endl;
    return 0;
}