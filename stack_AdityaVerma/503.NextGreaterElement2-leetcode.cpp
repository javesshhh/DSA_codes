// https://leetcode.com/problems/next-greater-element-ii/description/

vector<int> nextGreater(vector<int> &v)
{
    int n = v.size();
    vector<int> ans(n, -1);
    stack<int> s;
    s.push(v[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= v[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(v[i]);
    }
    return ans;
}

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            nums.push_back(nums[i]);
        }
        vector<int> ans = nextGreater(nums);
        for (int i = 0; i < n; i++)
        {
            ans.pop_back();
        }
        return ans;
    }
};

//

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> s;
        vector<int> res(n, -1);

        for (int i = 2 * n - 1; i >= 0; --i)
        {
            int num = nums[i % n];
            while (!s.empty() && s.top() <= num)
                s.pop();
            if (!s.empty())
                res[i % n] = s.top();
            s.push(num);
        }
        return res;
    }
};