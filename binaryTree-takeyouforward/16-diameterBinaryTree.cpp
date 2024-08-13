// https://www.youtube.com/watch?v=Rezetez59Nk&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=17&ab_channel=takeUforward
// https://leetcode.com/problems/diameter-of-binary-tree/description/
// https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/

// by recursively traversing

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
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {

        // Brute force approach taking O(N^2) time and stack space O(N)
        // find out max(lh+rh,max(ld,rd)).....This is diameter of BT;

        if (root == NULL)
            return 0;

        int option1 = height(root->left) + height(root->right);
        int option2 = diameterOfBinaryTree(root->left);
        int option3 = diameterOfBinaryTree(root->right);

        return max(option1, max(option2, option3));
    }
};

// optimized O(n) approach

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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxi = -1;
        finding(root, maxi);

        return maxi;
    }

    int finding(TreeNode *root, int &maxi)
    {
        if (root == NULL)
        {
            return 0;
        }

        int l = finding(root->left, maxi);
        int r = finding(root->right, maxi);

        maxi = max(maxi, l + r);

        return 1 + max(l, r);
    }
};