#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
            cin >> v[i];
        vector<int> v2;
        v2 = v;
        if (v[0] == v2[1])
        {
            v.erase(v.begin());
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (v[i] == v2[i - 1] || v[i] == v2[i + 1])
            {
                v.erase(v.begin() + i);
            }
        }
        if (v[n - 2] == v[n - 1])
            v.erase(v.begin() + n - 1);
        cout << v.size() << endl;
    }
    return 0;
}