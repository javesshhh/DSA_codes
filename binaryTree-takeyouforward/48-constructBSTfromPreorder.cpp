// https://www.youtube.com/watch?v=UmJT3j26t1I&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=49&ab_channel=takeUforward
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

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
    TreeNode *fn(vector<int> &preorder, int l, int r, int &i)
    {
        if (i >= preorder.size())
        {
            return nullptr;
        }
        if (preorder[i] < l || preorder[i] > r)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[i++]);
        // i++;
        root->left = fn(preorder, l, root->val, i);
        root->right = fn(preorder, root->val, r, i);
        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        int l = INT_MIN;
        int r = INT_MAX;
        return fn(preorder, l, r, i);
    }
};