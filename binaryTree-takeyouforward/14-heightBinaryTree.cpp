// https://www.youtube.com/watch?v=eD3tmO66aBA&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=15&ab_channel=takeUforward
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

// by using level order traversal

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
    int maxDepth(TreeNode *root)
    {
        // vector<vector<int>> ans;
        if (root == nullptr)
        {
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while (!q.empty())
        {
            int sz = q.size();
            // vector<int> temp;
            ans++;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                // temp.push_back(node->val);
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            // ans.push_back(temp);
        }
        return ans;
    }
};

// another

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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        stack<pair<TreeNode *, int>> s;
        s.push({root, 1});
        int ans = -1;
        while (!s.empty())
        {
            TreeNode *temp = s.top().first;
            int dis = s.top().second;
            ans = max(ans, dis);
            s.pop();
            if (temp->right)
            {
                s.push({temp->right, dis + 1});
            }
            if (temp->left)
            {
                s.push({temp->left, dis + 1});
            }
        }
        return ans;
    }
};