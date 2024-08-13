// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

#include <bits/stdc++.h>
using namespace std;

int findCity(int n, int m, vector<vector<int>>& edges,int d) {

        vector<vector<int>>matrix(n,vector<int>(n,1e9));
        for(auto it:edges){
            matrix[it[0]][it[1]]=it[2];
            matrix[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            matrix[i][i]=0;
        }

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = min(matrix[i][j],
					                   matrix[i][k] + matrix[k][j]);
				}
			}
		}

        int ans[n]={0};
        for(int i=0;i<n;i++){
            // int cnt=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=d){
                    ans[i]++;
                }
            }
        }
        int mini=*min_element(ans,ans+n);
        for(int i=n-1;i>=0;i--){
            if(ans[i]==mini){
                return i;
            }
        }
    }

int main() {

}