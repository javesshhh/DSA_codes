// https://www.youtube.com/watch?v=YK78FU5Ffjw&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=14&ab_channel=takeUforward
// https://leetcode.com/problems/permutations/description/

class Solution
{
public:
    void perm(vector<int> &nums, vector<vector<int>> &ans, vector<int> &a, int vis[])
    {
        if (a.size() == nums.size())
        {
            ans.push_back(a);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (vis[i] == 0)
            {
                a.push_back(nums[i]);
                vis[i] = 1;
                perm(nums, ans, a, vis);
                a.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> a;
        int vis[nums.size()];
        for (int i = 0; i < nums.size(); i++)
        {
            vis[i] = 0;
        }
        perm(nums, ans, a, vis);
        return ans;
    }
};

// https://www.youtube.com/watch?v=f2ic2Rsc9pU&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=15&ab_channel=takeUforward

class Solution
{
public:
    void perm(vector<int> &nums, vector<vector<int>> &ans, int i)
    {
        if (i >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[j], nums[i]);
            perm(nums, ans, i + 1);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        // vector<int>a;
        int i = 0;
        perm(nums, ans, i);
        return ans;
    }
};

// another logic by stl

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums);

        while (next_permutation(nums.begin(), nums.end()))
        {
            ans.push_back(nums);
        }
        return ans;
    }
};