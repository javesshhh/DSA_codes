#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    if(n==1)
	    cout<<0<<endl;
	    else if(n==2)
	    cout<<1<<endl;
	    else if(n==3)
	    cout<<1<<endl;
	    else if(n>3){
	        if(n%3==0)
            cout<<n/3<<endl;
	        else 
            cout<<n/3 + 1<<endl; 
	    }
	}
	return 0;
}