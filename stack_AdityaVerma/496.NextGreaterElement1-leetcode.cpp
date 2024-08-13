// https://leetcode.com/problems/next-greater-element-i/description/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums2.size();
        vector<int> v(n);
        stack<int> s;
        v.push_back(-1);
        for (int i = n - 2; i >= 0; i--)
        {
            s.push(nums2[i + 1]);
            if (s.top() > nums2[i])
            {
                v.push_back(s.top());
            }
            else
            {
                while (!s.empty() && s.top() <= nums2[i])
                {
                    s.pop();
                }
                if (s.empty())
                {
                    v.push_back(-1);
                }
                else
                {
                    v.push_back(s.top());
                }
            }
        }
        reverse(v.begin(), v.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums2[i]] = v[i];
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};