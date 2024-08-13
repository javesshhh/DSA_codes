// https://www.youtube.com/watch?v=FiFiNvM29ps&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=44&ab_channel=takeUforward
// https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }
        if (root->val > val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        if (root->val < val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

// another method

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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->val > val)
            {
                if (curr->left)
                    curr = (curr->left);
                else
                {
                    curr->left = new TreeNode(val);
                    break;
                }
            }
            else if (curr->val < val)
            {
                if (curr->right)
                    curr = (curr->right);
                else
                {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }
        // curr=new TreeNode(val);
        return root;
    }
};