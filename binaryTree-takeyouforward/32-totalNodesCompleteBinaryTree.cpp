// https://www.youtube.com/watch?v=u-yWemKGWO0&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=33&ab_channel=takeUforward
// https://leetcode.com/problems/count-complete-tree-nodes/description/



// simple O(n) solution

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
    int countNodes(TreeNode *root)
    {
        //  vector<int>ans;
        int ans = 0;
        if (root == nullptr)
        {
            return ans;
        }
        stack<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.top();
            q.pop();
            ans++;
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
            if (node->left != nullptr)
            {
                q.push(node->left);
            }
        }
        return ans;
    }
};



// for O(log N) approach, refer video

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
    int countNodes(TreeNode *root)
    {
        int leftHeight = 0, rightHeight = 0;
        TreeNode *left = root, *right = root;
        while (left)
        { // find leftHeight
            leftHeight++;
            left = left->left;
        }
        while (right)
        { // find rightHeight
            rightHeight++;
            right = right->right;
        }
        if (leftHeight == rightHeight)
        { // all nodes are present in last level
            return (pow(2, leftHeight)) - 1;
        }
        else
        {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};