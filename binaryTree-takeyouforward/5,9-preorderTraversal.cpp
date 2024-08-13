// https://www.youtube.com/watch?v=RlUu72JrOCQ&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=6&ab_channel=takeUforward
// https://takeuforward.org/data-structure/preorder-traversal-of-binary-tree/
// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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


// recursive solution
class Solution
{
public:
    vector<int> ans;

    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return ans;
        }
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};

// https://www.youtube.com/watch?v=Bfqd8BsPVuw&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=10&ab_channel=takeUforward

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


// iterative solution
class Solution {
public:


    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr){
            return ans;
        }
        stack<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.top();
            q.pop();
            ans.push_back(node->val);
            if(node->right!=nullptr){
                q.push(node->right);
            }
            if(node->left!=nullptr){
                q.push(node->left);
            }
        }
        return ans;
    }
};