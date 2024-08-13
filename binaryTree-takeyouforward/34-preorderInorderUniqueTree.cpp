// https://www.youtube.com/watch?v=aZNaLrVebKQ&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=35&ab_channel=takeUforward
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    TreeNode *fn(vector<int> &preorder, int prestart, int prend, vector<int> &inorder, int instart, int inend, map<int, int> &mp)
    {
        if (prestart > prend || instart > inend)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[prestart]);
        int inroot = mp[root->val];
        int left = inroot - instart;
        root->left = fn(preorder, prestart + 1, prestart + left, inorder, instart, inroot - 1, mp);
        root->right = fn(preorder, prestart + left + 1, prend, inorder, inroot + 1, inend, mp);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int prestart = 0;
        int prend = preorder.size() - 1;
        int instart = 0;
        int inend = inorder.size() - 1;
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        TreeNode *root = fn(preorder, prestart, prend, inorder, instart, inend, mp);
        return root;
    }
};