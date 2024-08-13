#include <bits/stdc++.h>
using namespace std;

class SGTree
{
    public:
    vector<int> seg;
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build(int ind, int l, int h, vector<int> &v)
    {
        if (l == h)
        {
            seg[ind] = v[l];
            return;
        }
        int mid = l + (h - l) / 2;
        build(2 * ind + 1, l, mid, v);
        build(2 * ind + 2, mid + 1, h, v);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query1(int ind, int low, int high, int l, int r)
    {
        if (l > high || r < low)
        {
            return INT_MAX;
        }
        else if (low >= l && high <= r)
        {
            return seg[ind];
        }
        else
        {
            int mid = low + (high - low) / 2;
            int a = query1(2 * ind + 1, low, mid, l, r);
            int b = query1(2 * ind + 2, mid + 1, high, l, r);
            return min(a, b);
        }
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[i] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

int main()
{
    int n1;
    cin >> n1;
    vector<int> v1(n1);
    for (int i = 0; i < n1; i++)
    {
        cin >> v1[i];
    }
    SGTree sg1(n1);
    sg1.build(0, 0, n1 - 1, v1);
    int n2;
    cin >> n2;
    vector<int> v2(n2);
    for (int i = 0; i < n2; i++)
    {
        cin >> v2[i];
    }
    SGTree sg2(n2);
    // vector<int> seg(4 * n, 0);
    sg2.build(0, 0, n2 - 1, v2);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l1, r1;
            cin >> l1 >> r1;
            int a = sg1.query1(0, 0, n1 - 1, l1, r1);
            int l2, r2;
            cin >> l2 >> r2;
            int b = sg2.query1(0, 0, n2 - 1, l2, r2);
            cout << min(a, b) << endl;
        }
        else
        {
            int arr, i, val;
            cin >> arr >> i >> val;
            if (arr == 1)
                sg1.update(0, 0, n1 - 1, i, val);
            else
                sg2.update(0, 0, n2 - 1, i, val);
        }
    }
}