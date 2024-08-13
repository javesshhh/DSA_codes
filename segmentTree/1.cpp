#include <bits/stdc++.h>
using namespace std;

void build(int ind, int l, int h, vector<int> &v, vector<int> &seg)
{
    if (l == h)
    {
        seg[ind] = v[l];
        return;
    }
    int mid = l + (h - l) / 2;
    build(2 * ind + 1, l, mid, v, seg);
    build(2 * ind + 2, mid + 1, h, v, seg);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query1(int ind, int low, int high, int l, int r, vector<int> &seg)
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
        int a = query1(2 * ind + 1, low, mid, l, r, seg);
        int b = query1(2 * ind + 2, mid + 1, high, l, r, seg);
        return min(a, b);
    }
}

void update(int ind,int low,int high,int i,int val,vector<int>&seg){
    if(low==high){
        seg[i]=val;
        return;
    }
    int mid=l+(h-l)/2;
    if(i<=mid) update(2*ind + 1,low,mid,i,val,seg);
    else update(2*ind + 2,mid+1,high,i,val,seg);
    seg[ind]=min(seg[2*ind + 1],seg[2*ind + 2]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> seg(4 * n, 0);
    build(0, 0, n - 1, v, seg);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << query1(0, 0, n - 1, l, r, seg) << endl;
        }
        else
        {
            int i, val;
            cin >> i >> val;
            update(0,0,n-1,i,val,seg);
            arr[i]=val;
        }
    }
}