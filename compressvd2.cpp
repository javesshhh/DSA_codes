#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    int z=n;
	    if(n==1)
	    cout<<n<<endl;
	    else if(n==2) {
	        if(arr[0]==arr[1])
	        cout<<n-1<<endl;
	        else
	        cout<<n<<endl;
	    }
	    else {
	    if(arr[0]==arr[1])
	    {
	    z--;
	    }
	    for(int i=1;i<n-1;i++){
	             if(arr[i]==arr[i+1])
	             {
	               z--;
	             } 
	    }
	    
	    cout<<z<<endl;
	}}
	return 0;
}