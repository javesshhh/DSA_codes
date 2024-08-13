// https://www.youtube.com/watch?v=ZWGW7FminDM&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=53&ab_channel=takeUforward
// https://leetcode.com/problems/recover-binary-search-tree/description/

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
    void dfs(TreeNode *root, vector<int> &vec)
    {
        if (!root)
            return;
        dfs(root->left, vec);
        vec.push_back(root->val);
        dfs(root->right, vec);
    }
    void in(TreeNode *root, vector<int> &vec, int &i)
    {
        if (!root)
            return;
        // i++;
        in(root->left, vec, i);
        if (root->val != vec[i])
            root->val = vec[i];
        i++;
        in(root->right, vec, i);
    }

public:
    void recoverTree(TreeNode *root)
    {
        vector<int> vec;
        dfs(root, vec);
        sort(vec.begin(), vec.end());
        int i = 0;
        in(root, vec, i);
    }
};

// another

class Solution
{
    TreeNode *first, *last, *prev;

public:
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        if (prev != NULL && (root->val < prev->val))
        {
            if (first == NULL)
            {
                first = prev;
                last = root;
            }
            else
                last = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        first = last = prev = NULL;
        inorder(root);
        swap(first->val, last->val);
    }
};