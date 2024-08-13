// https://www.youtube.com/watch?v=_-QHfMDde90&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=28&ab_channel=takeUforward
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

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
    bool fn(TreeNode *root, TreeNode *node, vector<TreeNode *> &v)
    {
        if (root == nullptr)
        {
            return false;
        }

        v.push_back(root);
        if (root == node)
        {
            return true;
        }
        if (fn(root->left, node, v) == true)
        {
            return true;
        }
        if (fn(root->right, node, v) == true)
        {
            return true;
        }
        v.pop_back();
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> pp;
        vector<TreeNode *> qq;
        fn(root, p, pp);
        fn(root, q, qq);
        int pn = pp.size();
        int qn = qq.size();
        int i = 0;
        TreeNode *ans = root;
        while (i < pn && i < qn)
        {
            if (pp[i] == qq[i])
            {
                ans = pp[i];
            }
            else
            {
                break;
            }
            i++;
            // j++;
        }
        return ans;
    }
};

// another method

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Optimal Solution - TC : O(n), SC : O(h); h --> height of BT
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return root;

        if (root == p || root == q)
            return root;

        TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

        if (leftAns != NULL && rightAns != NULL)
            return root;
        else if (leftAns != NULL && rightAns == NULL)
            return leftAns;
        else if (leftAns == NULL && rightAns != NULL)
            return rightAns;
        else
            return NULL;
    }
};