// https://leetcode.com/problems/binary-tree-paths/description/

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
    void fn(TreeNode *root, vector<string> &ans, string temp)
    {
        if (root == nullptr)
        {
            return;
        }
        temp = temp + to_string(root->val) + "->";
        if (root->left == nullptr && root->right == nullptr)
        {
            temp.pop_back();
            temp.pop_back();
            ans.push_back(temp);
        }

        fn(root->left, ans, temp);
        fn(root->right, ans, temp);
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        string temp = "";
        if (root == nullptr)
        {
            return ans;
        }
        fn(root, ans, temp);
        return ans;
    }
};