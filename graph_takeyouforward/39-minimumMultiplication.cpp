// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-multiplications-to-reach-end

#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int>ans(100000,1e9);
        queue<pair<int,int>>q;
        q.push({0,start});
        ans[start]=0;
        int mod=100000;
        while(!q.empty()){
            int steps=q.front().first;
            int num=q.front().second;
            q.pop();
            if(num==end) return steps;
            for(int i=0;i<arr.size();i++){
                int num1=num*arr[i];
                 num1=num1%mod;
                if(steps+1<ans[num1]){
                    ans[num1]=steps+1;
                    q.push({steps+1,num1});
                }
            }
        }
        return -1;
    }

int main() {

}