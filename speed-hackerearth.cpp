// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int count = 1;
//     int minterm = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] >= minterm)
//             continue;
//         else if (arr[i] < arr[i - 1])
//         {
//             minterm = arr[i];
//             count++;
//         }
//     }
//     cout << count << endl;
// 	}
// }

// **** other code

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n;
// 		cin>>n;
// 		int arr[n];
// 		for(int i=0;i<n;i++)
// 		cin>>arr[i];
// 		int c=1;
// 		for(int j=0;j<n-1;j++){
// 			if(arr[j]>=arr[j+1])
// 			c++;
// 			else
// 			arr[j+1]=arr[j];
// 		}
// 		cout<<c<<endl;
// 	}
// }