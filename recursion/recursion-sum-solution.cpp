// https://www.youtube.com/watch?v=eQCS_v3bw0Q&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=7&ab_channel=takeUforward
// different variations of sum recursion problem


// to print only one subsequence of sum B

#include <bits/stdc++.h>
using namespace std;

bool generate(int i,vector<int>&A,vector<int>&a,vector<vector<int>>&ans,int n,int B,int &sum){
        if(i==n){
            if(sum==B){
                ans.push_back(a);
                return true;
                }
            return false;
        }
        a.push_back(A[i]);           // element included in vector
        sum=sum+(A[i]);
        if(generate(i++,A,a,ans,n,B,sum)==true)
        return true;
        sum=sum-(A[i]);
        a.pop_back();
        if(generate(i++,A,a,ans,n,B,sum)==true)
        return true;     // element not included in vector

        return false;
    }

    vector<vector<int>> combinationSum(vector<int> &A, int B) {
        vector<vector<int>>ans;
        vector<int>a;
        int n=A.size();
        int sum=0;
        if(generate(0,A,a,ans,n,B,sum)==true)
        return ans;
        else
        return {};
    }

int main() {
    vector<int>A={7,2,6,5};
    int B=7;
    vector<vector<int>>v;
    v=combinationSum(A,B);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}