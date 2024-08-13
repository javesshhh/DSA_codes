// https://www.youtube.com/watch?v=LgLRTaEMRVc&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=36&ab_channel=takeUforward
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    TreeNode *fn(vector<int> &postorder, int poststart, int postend, vector<int> &inorder, int instart, int inend, unordered_map<int, int> &mp)
    {
        if (poststart > postend || instart > inend)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(postorder[postend]);
        int inroot = mp[root->val];
        int left = inroot - instart;
        root->left = fn(postorder, poststart, poststart + left - 1, inorder, instart, inroot - 1, mp);
        root->right = fn(postorder, poststart + left, postend - 1, inorder, inroot + 1, inend, mp);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int poststart = 0;
        int postend = postorder.size() - 1;
        int instart = 0;
        int inend = inorder.size() - 1;
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        TreeNode *root = fn(postorder, poststart, postend, inorder, instart, inend, mp);
        return root;
    }
};