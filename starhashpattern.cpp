#include <iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=i;j++){
				cout<<"*";
			}
			for(int j=i+1;j<=2*n-i;j++){
				cout<<"#";
			}
			for(int j=2*n-i+1;j<=2*n;j++){
				cout<<"*";
			}
			cout<<endl;
		}
		for(int i=0;i<2*n;i++)
		cout<<"*";
        cout<<endl;
	}
	}