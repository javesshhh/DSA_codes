// https://www.youtube.com/watch?v=kouxiP_H5WE&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=45&ab_channel=takeUforward
// https://leetcode.com/problems/delete-node-in-a-bst/description/

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
    TreeNode *lastr(TreeNode *root)
    {
        if (root->right == nullptr)
        {
            return root;
        }
        return lastr(root->right);
    }

    TreeNode *fn(TreeNode *root)
    {
        if (root->right == nullptr)
        {
            return root->left;
        }
        if (root->left == nullptr)
        {
            return root->right;
        }
        TreeNode *right = root->right;
        TreeNode *lastright = lastr(root->left);
        lastright->right = right;
        return root->left;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (root->val == key)
        {
            return fn(root);
        }
        TreeNode *node = root;
        if (node->val > key)
        {
            node->left = deleteNode(node->left, key);
        }
        else
        {
            node->right = deleteNode(node->right, key);
        }
        return root;
    }
};

// another by iterative approach

// Striver Solution
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;
        if (root->val == key)
            return helper(root);

        TreeNode *dummy = root;
        while (root)
        {
            if (root->val > key)
            {
                if (root->left && root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                    root = root->left;
            }
            else
            {
                if (root->right && root->right->val == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                    root = root->right;
            }
        }
        return dummy;
    }

    TreeNode *helper(TreeNode *root)
    {
        if (!root->left)
            return root->right;
        if (!root->right)
            return root->left;

        // Point Left's rightmmost node to root->right.
        TreeNode *leftChild = lastRight(root->left);
        leftChild->right = root->right;
        return root->left;
    }

    TreeNode *lastRight(TreeNode *root)
    {
        if (!root->right)
            return root;
        return lastRight(root->right);
    }
};