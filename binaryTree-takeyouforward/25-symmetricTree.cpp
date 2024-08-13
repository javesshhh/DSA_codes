// https://www.youtube.com/watch?v=nKggNAiEpBE&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=26&ab_channel=takeUforward
// https://leetcode.com/problems/symmetric-tree/description/

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
    bool fn(TreeNode *a, TreeNode *b)
    {
        if ((a == nullptr && b != nullptr) || (a != nullptr && b == nullptr))
        {
            return false;
        }
        else if (a == nullptr && b == nullptr)
        {
            return true;
        }
        else if (a->val != b->val)
        {
            return false;
        }
        return fn(a->left, b->right) && fn(a->right, b->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        return fn(root->left, root->right);
    }
};