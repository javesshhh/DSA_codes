#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        int mindIndex = i;
    }
    for (int j = i + 1; j < n; ++j)
    {
        if (a[j] < a[mindIndex])
        {
            mindIndex = j;
        }
        swap(a[i], a[mindIndex]);
    }
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
}

// o(n2) algorithm
// inbuilt sorting algo is o(n log n) -- preferred