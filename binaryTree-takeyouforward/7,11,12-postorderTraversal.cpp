// https://www.youtube.com/watch?v=COQOU6klsBg&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=8&ab_channel=takeUforward
// https://takeuforward.org/data-structure/post-order-traversal-of-binary-tree/
// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return ans;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
};

// https://www.youtube.com/watch?v=2YBhNLodD8Q&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=12&ab_channel=takeUforward
// using 2 stacks

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> q1, q2;
        if (root == nullptr)
        {
            return ans;
        }
        q1.push(root);
        while (!q1.empty())
        {
            TreeNode *node = q1.top();
            q1.pop();
            q2.push(node);
            if (node->left != nullptr)
            {
                q1.push(node->left);
            }
            if (node->right != nullptr)
            {
                q1.push(node->right);
            }
        }
        while (!q2.empty())
        {
            TreeNode *node = q2.top();
            q2.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};

// using 1 stack, just by pushing val directly into ans vector instead of stack and finally reversing ans

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> q1;
        if (root == nullptr)
        {
            return ans;
        }
        q1.push(root);
        while (!q1.empty())
        {
            TreeNode *node = q1.top();
            q1.pop();
            ans.push_back(node->val);
            if (node->left != nullptr)
            {
                q1.push(node->left);
            }
            if (node->right != nullptr)
            {
                q1.push(node->right);
            }
        }
        // while(!q2.empty()){
        //     TreeNode* node=q2.top();
        //     q2.pop();
        //     ans.push_back(node->val);
        // }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// https://www.youtube.com/watch?v=NzIGLLwZBS8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=13&ab_channel=takeUforward
// another method using 1 stack

vector<int> postOrderTrav(node *cur)
{

    vector<int> postOrder;
    if (cur == NULL)
        return postOrder;

    stack<node *> st;
    while (cur != NULL || !st.empty())
    {

        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else
                cur = temp;
        }
    }
    return postOrder;
}