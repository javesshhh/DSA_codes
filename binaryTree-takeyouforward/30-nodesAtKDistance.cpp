// https://www.youtube.com/watch?v=i9ORlEy6EsI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=31&ab_channel=takeUforward
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void fn(TreeNode *node, TreeNode *prev, unordered_map<TreeNode *, TreeNode *> &par)
    {
        if (node == nullptr)
            return;
        par[node] = prev;
        if (node->left)
        {
            fn(node->left, node, par);
        }
        if (node->right)
        {
            fn(node->right, node, par);
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> par;
        fn(root, nullptr, par);
        queue<pair<TreeNode *, int>> q;
        q.push({target, 0});
        vector<int> ans;
        vector<int> vis(501, 0);
        vis[target->val] = 1;
        while (!q.empty())
        {
            TreeNode *node = q.front().first;
            int dis = q.front().second;
            vis[node->val] = 1;
            q.pop();
            if (dis == k)
            {
                ans.push_back(node->val);
                continue;
            }
            if (node->left && vis[node->left->val] == 0)
            {
                q.push({node->left, dis + 1});
            }
            if (node->right && vis[node->right->val] == 0)
            {
                q.push({node->right, dis + 1});
            }
            if (par[node] && vis[par[node]->val] == 0)
            {
                q.push({par[node], dis + 1});
            }
        }
        return ans;
    }
};