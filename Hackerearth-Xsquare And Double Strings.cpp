#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int hash[26]={0};
		for(int i=0;i<s.length();i++){
			hash[s[i]-97]++;
		}
        bool x=false;
		for(int i=0;i<26;i++){
			if(hash[i]>=2){
			bool=true;
            break;}
        }
if(bool)
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;
	}
}