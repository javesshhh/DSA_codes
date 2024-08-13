// https://www.youtube.com/watch?v=fmflMqVOC7k&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=28&ab_channel=takeUforward
// https://www.interviewbit.com/problems/path-to-given-node/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool fn(TreeNode *root, int data, vector<int> &ans)
{
    if (root == nullptr)
    {
        return false;
    }

    ans.push_back(root->val);
    if (root->val == data)
    {
        // ans.push_back(root->val);
        return true;
    }
    // if(root->left==nullptr && root->right==nullptr){
    //     ans.pop_back();
    //     return false;
    // }
    if (fn(root->left, data, ans) == true)
    {
        return true;
    }
    if (fn(root->right, data, ans) == true)
    {
        return true;
    }
    ans.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode *root, int data)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }
    fn(root, data, ans);
    return ans;
}