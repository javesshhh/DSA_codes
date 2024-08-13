// https://www.youtube.com/watch?v=ZbybYvcVLks&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=29&ab_channel=takeUforward
// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 0});
        unsigned long long first, last;
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            int mini = q.front().second;
            for (int i = 0; i < size; i++)
            {
                auto it = q.front();
                TreeNode *temp = it.first;
                unsigned long long val = it.second;
                if (i == 0)
                    first = val;
                if (i == size - 1)
                    last = val;
                q.pop();
                if (temp->left)
                    q.push({temp->left, (2 * val) + 1});
                if (temp->right)
                    q.push({temp->right, (2 * val) + 2});
            }
            ans = max(ans, (int)(last - first + 1));
        }
        return ans;
    }
};

// another

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     unsigned long long  val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(unsigned long long  x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(unsigned long long  x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void fn(TreeNode *root, map<unsigned long long, vector<unsigned long long>> &m, unsigned long long i, unsigned long long j)
    {
        if (root == nullptr)
            return;
        m[j].push_back(i);
        if (root->left)
        {
            fn(root->left, m, 2 * i + 1, j + 1);
        }
        if (root->right)
        {
            fn(root->right, m, 2 * i + 2, j + 1);
        }
    }

    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        map<unsigned long long, vector<unsigned long long>> m;
        fn(root, m, 0, 0);
        unsigned long long ans = 0;
        for (auto it : m)
        {
            unsigned long long a = *max_element(it.second.begin(), it.second.end());
            unsigned long long b = *min_element(it.second.begin(), it.second.end());
            ans = max(ans, a - b + 1);
        }
        return ans;
    }
};