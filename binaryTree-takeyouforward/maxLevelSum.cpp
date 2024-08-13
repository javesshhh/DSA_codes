// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

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
    // int ans=INT_MAX;
    int maxLevelSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int sum = root->val;
        int ans = 1;
        int lvl = 1;
        while (!q.empty())
        {
            int sz = q.size();
            int temp = 0;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
                temp = temp + node->val;
            }
            if (temp > sum)
            {
                ans = lvl;
                sum = temp;
            }
            lvl++;
        }
        return ans;
    }
};