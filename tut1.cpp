#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{2, 1, 3};
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0)
        {
            v.push_back(v[i] / 2);
            count++;
        }
    }
    cout << count << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
    
}