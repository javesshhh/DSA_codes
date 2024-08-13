// https://www.youtube.com/watch?v=cX_kPV_foZc&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=48&ab_channel=takeUforward
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // if(root==nullptr){
        //     return root;
        // }
        if (root->val == p->val)
        {
            return p;
        }
        if (root->val == q->val)
        {
            return q;
        }
        if ((root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val))
        {
            return root;
        }
        if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};