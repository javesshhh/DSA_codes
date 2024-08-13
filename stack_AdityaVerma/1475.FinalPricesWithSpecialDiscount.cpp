// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/

class Solution
{
public:
    vector<int> finalPrices(vector<int> &arr)
    {
        vector<int> v;
        stack<int> s;
        int n = arr.size();
        v.push_back(arr[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            s.push(arr[i + 1]);
            if (s.top() <= arr[i])
            {
                v.push_back(arr[i] - s.top());
            }
            else
            {
                while (!s.empty() && s.top() > arr[i])
                {
                    s.pop();
                }
                if (s.empty())
                {
                    v.push_back(arr[i]);
                }
                else
                    v.push_back(arr[i] - s.top());
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};