// https://www.youtube.com/watch?v=sWf7k1x9XR4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=39&ab_channel=takeUforward
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

// tell this to interviewer

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
    TreeNode *prev = nullptr;
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};

//

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
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();

            if (cur->right != NULL)
            {
                st.push(cur->right);
            }
            if (cur->left != NULL)
            {
                st.push(cur->left);
            }
            if (!st.empty())
            {
                cur->right = st.top();
            }
            cur->left = NULL;
        }
    }
};