// https://www.youtube.com/watch?v=f-sj7I5oXEI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=48&ab_channel=takeUforward
// https://leetcode.com/problems/validate-binary-search-tree/description/


// by checking order of inorder traversal is increasing

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
    // long long int curr;

    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *node = root;
        // vector<int> inorder;
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
                    return true;
                node = st.top();
                st.pop();
                // curr=node->val;
                // inorder.push_back(node->val);
                if (prev != nullptr)
                {
                    if (node->val <= prev->val)
                    {
                        return false;
                    }
                }
                prev = node;
                node = node->right;
            }
        }
        return true;
    }
};


// using video logic

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
    bool fn(TreeNode *root, long long int low, long long int high)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->val > low && root->val < high)
        {
            return fn(root->left, low, root->val) && fn(root->right, root->val, high);
        }
        return false;
    }

    bool isValidBST(TreeNode *root)
    {
        return fn(root, LLONG_MIN, LLONG_MAX);
    }
};