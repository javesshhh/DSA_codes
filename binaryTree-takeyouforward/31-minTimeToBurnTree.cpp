// https://www.youtube.com/watch?v=2r5wLmQfD6g&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=32&ab_channel=takeUforward
// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

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
    unordered_map<TreeNode *, TreeNode *> parent;

    void fn(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
            {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    TreeNode *target = nullptr;

    void trav(TreeNode *root, int start)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->val == start)
        {
            target = root;
        }
        trav(root->left, start);
        trav(root->right, start);
    }

    int amountOfTime(TreeNode *root, int start)
    {
        if (root == nullptr)
        {
            return 0;
        }
        trav(root, start);
        fn(root);
        queue<TreeNode *> q;
        q.push(target);
        unordered_map<TreeNode *, int> vis;
        int dis = 0;
        vis[target] = 1;
        while (!q.empty())
        {
            dis++;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left && vis[node->left] != 1)
                {
                    q.push(node->left);
                    vis[node->left] = 1;
                }
                if (node->right && vis[node->right] != 1)
                {
                    q.push(node->right);
                    vis[node->right] = 1;
                }
                if (parent[node] && vis[parent[node]] != 1)
                {
                    q.push(parent[node]);
                    vis[parent[node]] = 1;
                }
            }
        }
        return dis - 1;
    }
};