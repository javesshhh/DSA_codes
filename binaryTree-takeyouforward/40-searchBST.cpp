// https://www.youtube.com/watch?v=KcNt6v_56cc&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=41&ab_channel=takeUforward
// https://leetcode.com/problems/search-in-a-binary-search-tree/description/

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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->val == val)
        {
            return root;
        }
        if (root->val > val)
        {
            return searchBST(root->left, val);
        }
        if (root->val < val)
        {
            return searchBST(root->right, val);
        }
        return nullptr;
    }
};