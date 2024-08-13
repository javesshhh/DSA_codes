// to check the nxn matrix(consists of 1 &0) is symmetric 
// about the geometric center of the matrix about x and y axis
// sample input
// 01110
// 01010
// 10001 // geometric centre is third 0
// 01010
// 01110
// matrix is symmetric about x and y axis

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin>>t;
    while(t--){
  int n;
  cin>>n;
  char a[n][n];
  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          cin>>a[i][j];
      }
  }
  bool flag=false;
  for(int i=0;i<n;i++){
      for(int j=0;j<n/2;j++){
          if(a[i][j]!=a[i][n-1-j] || a[j][i]!=a[n-1-j][i]){
              flag=true;
          }
      }
  }
  if(flag) cout<<"NO\n";
  else cout<<"YES\n";

}
}