// https://www.youtube.com/watch?v=WszrfSwMz58&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=18&ab_channel=takeUforward
// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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
    int fn(TreeNode *root, int &maxi)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftm = fn(root->left, maxi);
        int rightm = fn(root->right, maxi);
        if (leftm < 0)
        {
            leftm = 0;
        }
        if (rightm < 0)
        {
            rightm = 0;
        }
        maxi = max(maxi, root->val + leftm + rightm);
        return root->val + max(leftm, rightm);
    }

    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        int k = fn(root, maxi);
        return maxi;
    }
};