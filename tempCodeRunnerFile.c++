// #include <bits/stdc++.h>
// #define int long long int
// #define mii map<int,int>
// #define umii unordered_map<int,int>
// #define pii pair<int,int>
// #define vi vector<int>
// #define vb vector<bool>
// #define vs vector<string>
// #define vpii vector<pair<int,int>>
// #define vvi vector<vector<int>>
// #define tc int t; cin>>t; while(t--)
// #define pb push_back
// #define ppb pop_back()
// #define gcd(a, b) __gcd(a, b)
// #define fr(a,b) for(int i = a; i < b; i++)
// #define frr(a,b) for(int i = a; i >= b; i--)
// #define vin(a,n) for(int i=0;i<n;i++) cin>>a[i]
// #define vout(a) for(auto ch : a){cout<<ch<<" ";} cout<<'\n'
// #define yes cout<<"YES"<<'\n'
// #define no cout<<"NO"<<'\n'
// #define ret(a) cout<<a<<'\n'
// #define mod 1000000007
// using namespace std;

// signed main() {
// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--){
//         int a,b,c;
//         cin>>a>>b>>c;
//         if(a+b>=10 || b+c>=10 || c+a>=10){
//             cout<<"YES"<<endl;
//         }
//         else{
//             cout<<"NO"<<endl;
//         }
//     }
//     return 0;
// }
// #include <bits/stdc++.h>
// #define int long long int
// #define mii map<int,int>
// #define umii unordered_map<int,int>
// #define pii pair<int,int>
// #define vi vector<int>
// #define vb vector<bool>
// #define vs vector<string>
// #define vpii vector<pair<int,int>>
// #define vvi vector<vector<int>>
// #define tc int t; cin>>t; while(t--)
// #define pb push_back
// #define ppb pop_back()
// #define gcd(a, b) __gcd(a, b)
// #define fr(a,b) for(int i = a; i < b; i++)
// #define frr(a,b) for(int i = a; i >= b; i--)
// #define vin(a,n) for(int i=0;i<n;i++) cin>>a[i]
// #define vout(a) for(auto ch : a){cout<<ch<<" ";} cout<<'\n'
// #define yes cout<<"YES"<<'\n'
// #define no cout<<"NO"<<'\n'
// #define ret(a) cout<<a<<'\n'
// #define mod 1000000007
// using namespace std;

// signed main() {
// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         int a[n];
//         int b[n];
//         for(int i=0;i<n;i++){
//             cin>>a[i]>>b[i];
//         }
//         int ans;
//         int mch=INT_MIN;
//         for(int i=0;i<n;i++){
//             if(a[i]<=10 && b[i]>mch){
//                 mch=b[i];
//                 ans=i+1;
//             }
//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
#define int long long int
#define mii map<int, int>
#define umii unordered_map<int, int>
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define pb push_back
#define ppb pop_back()
#define gcd(a, b) __gcd(a, b)
#define fr(a, b) for (int i = a; i < b; i++)
#define frr(a, b) for (int i = a; i >= b; i--)
#define vin(a, n)               \
    for (int i = 0; i < n; i++) \
    cin >> a[i]
#define vout(a)           \
    for (auto ch : a)      \
    {                     \
        cout << ch << " "; \
    }                     \
    cout << '\n'
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define ret(a) cout << a << '\n'
#define mod 1000000007
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        // vector<vector<string>>v(8,vector<string>(8));
        // for(int i=0;i<8;i++){
        //     for(int j=0;j<8;j++){
        //         cin>>v[i][j];
        //     }
        // }
        // int ch,y;
        // for(int i=0;i<8;i++){
        //     for(int j=0;j<8;j++){
        //         if(v[i][j]!="."){
        //             ch=i;
        //             y=j;
        //             goto label;
        //         }
        //     }
        // }
        // label:
        // string s="";
        // for(int i=ch;i<8;i++){
        //     if(v[i][y]=="."){
        //         break;
        //     }
        //     s=s+v[i][y];
        // }
        // cout<<s<<endl;
        vector<vector<char>> v;
        char ch;
        int ab = -1,ba;
        // int l;
        for (int i = 0; i < 8; i++)
        {
            vector<char> zz;
            for (int j = 0; j < 8; j++)
            {
                cin >> ch;
                zz.push_back(ch);
                if (ch != '.' && ab == -1)
                {
                    p = j;
                    ba = i;
                }
            }
            v.push_back(zz);
        }
        // cout<<l<<" "<<p<<endl;
        string ans;
        for (int i = ba; i < 8; i++)
        {
            if (v[i][ab] == '.')
            {
                /* code */
                break;
            }
            // cout<<v[i][p]<<endl;
            ans = ans + v[i][ab];
        }
        cout << ans << endl;
    }
    return 0;
}