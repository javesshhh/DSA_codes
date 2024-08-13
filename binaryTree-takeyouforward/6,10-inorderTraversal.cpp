// https://www.youtube.com/watch?v=Z_NEgBgbRVI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=7&ab_channel=takeUforward
// https://takeuforward.org/data-structure/inorder-traversal-of-binary-tree/
// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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

// recursive
class Solution
{
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return ans;
        }
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        return ans;
    }
};

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

// iterative
// https://www.youtube.com/watch?v=lxTGsVXjwvM&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=11&ab_channel=takeUforward

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode *> st;

        while (root || !st.empty())
        {
            if (root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                TreeNode *temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                root = temp->right;
            }
        }

        return ans;
    }
};

// another solution

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *node = root;
        vector<int> inorder;
        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty() == true)
                    break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};