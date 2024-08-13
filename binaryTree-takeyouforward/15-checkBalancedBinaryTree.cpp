// https://www.youtube.com/watch?v=Yt50Jfbd8Po&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=16&ab_channel=takeUforward
// https://leetcode.com/problems/balanced-binary-tree/description/

// going to every node and separately calling fn and also same to its right and left part

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
    int fn(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return max(1 + fn(node->left), 1 + fn(node->right));
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        int left = fn(root->left);
        int right = fn(root->right);
        if (abs(left - right) > 1)
        {
            return false;
        }
        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);
        if (l == false || r == false)
        {
            return false;
        }
        return true;
    }
};


// O(n) solution

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
    int fn(TreeNode *node)
    {
        if (node == nullptr)
        {
            return -1;
        }
        int lh = fn(node->left);
        int rh = fn(node->right);
        if (lh == -1 || rh == -1)
        {
            return -1;
        }
        if (abs(rh - lh) > 1)
        {
            return -1;
        }
        return max(1 + lh, 1 + rh);
    }

    bool isBalanced(TreeNode *root)
    {
        if (fn(root) == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
