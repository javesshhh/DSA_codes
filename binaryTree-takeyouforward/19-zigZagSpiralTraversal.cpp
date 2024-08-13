// https://www.youtube.com/watch?v=3OXWEdlIGl4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=20&ab_channel=takeUforward
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool flag = true;
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> temp;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            if (flag == false)
            {
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
            flag = !flag;
        }
        return ans;
    }
};