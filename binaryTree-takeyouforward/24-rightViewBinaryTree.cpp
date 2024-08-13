// https://www.youtube.com/watch?v=KV4mRzTjlAk&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=25&ab_channel=takeUforward
// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        map<int, int> m;
        queue<pair<TreeNode *, int>> q;

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<TreeNode *, int> temp = q.front();
            q.pop();

            TreeNode *frontNode = temp.first;
            int hd = temp.second;

            m[hd] = frontNode->val;

            if (frontNode->left)
                q.push(make_pair(frontNode->left, hd + 1));

            if (frontNode->right)
                q.push(make_pair(frontNode->right, hd + 1));
        }

        for (auto i : m)
            ans.push_back(i.second);

        return ans;
    }
};

//  another way of writing code

vector<int> rightSideView(TreeNode *root)
{

    queue<TreeNode *> pending;
    if (!root)
        return {};
    vector<int> answer;
    pending.push(root);
    while (!pending.empty())
    {
        int len = pending.size();
        while (len--)
        {
            TreeNode *curr = pending.front();
            pending.pop();
            if (curr->left)
                pending.push(curr->left);
            if (curr->right)
                pending.push(curr->right);
            if (len == 0)
            {
                answer.push_back(curr->val);
            }
        }
    }
    return answer;
}